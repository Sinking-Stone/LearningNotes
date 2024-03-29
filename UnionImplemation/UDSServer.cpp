/*
 * @Date         : 2024-01-08 16:06:38
 * @Description  : "Unix Domain Socket" (UDS) technology can be utilized to
 * achieve bidirectional data flow between IOTASK (Input/Output Task) and TCS,
 * as well as between IOTASK and DDS (Data Distribution Service).
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 * @Author       : qianlang 2540995459@qq.com
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2024-02-01 15:13:04
 * @FilePath     : /UnionImplemation/UDSServer.cpp
 */

#include "UDSServer.hpp"
#include <fcntl.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 *
 *
 * @param  {void}
 * @return {void}
 * @description: allocate memory space for data storage
 */
TCS_UDS_DDS::TCS_UDS_DDS() {
  buf = NULL;
  buf = new char[bufLength];
  if (buf == NULL) {
    perror("new buf error");
  }
  memset(buf, 0, sizeof(bufLength));

  recv_sockfd = -1;
  send_sockfd = -1;
}

/**
 *
 *
 * @param  {void}
 * @return {void}
 * @description: free allocated memory space
 */
TCS_UDS_DDS::~TCS_UDS_DDS() {
  if (buf != NULL) {
    delete buf;
  }
}

/**
 *
 *
 * @param  {string} UDS_filename_trans: UDS filename
 * @param  {bool} flag: true represents async,false represents sync
 * @return {bool}
 * @description: using SOCK_STREAM to create a socket,bind and connect if flag
 * is false
 */
bool TCS_UDS_DDS::init(std::string UDS_filename_trans, bool flag) {
  if (0 <= recv_sockfd) {
    perror("recv_socket has existed");
    return false;
  }

  if (UDS_filename_trans.size() <= 0) {
    perror("UDS_filename invalid");
    return false;
  }

  is_server = flag;

  recv_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);

  if (recv_sockfd < 0) {
    perror("init-socket");
    return false;
  }

  sockaddr_un recv_addr;
  recv_addr.sun_family = AF_UNIX;
  if (flag) {
    struct stat buffer;
    if (stat("/tmp/TB_QL_3902", &buffer) == 0) {
      std::system("rm /tmp/TB_QL_3902");
    }
    strcpy(recv_addr.sun_path, "/tmp/TB_QL_3902");
  } else {
    struct stat buffer;
    if (lstat(UDS_filename_trans.c_str(), &buffer) == 0) {
      std::system(std::string("rm ").append(UDS_filename_trans).c_str());
    }
    strcpy(recv_addr.sun_path, UDS_filename_trans.c_str());
  }

  if (bind(recv_sockfd, (struct sockaddr *)&recv_addr, sizeof(recv_addr)) ==
      -1) {
    perror("init-bind");
    close(recv_sockfd);
    recv_sockfd = -1;
    return false;
  }

  if (flag) {
    int flags = fcntl(recv_sockfd, F_GETFL, 0);
    if (flags == -1) {
      perror("fcntl");
      close(recv_sockfd);
      recv_sockfd = -1;
      return false;
    }
    flags |= O_NONBLOCK;
    if (fcntl(recv_sockfd, F_SETFL, flags) == -1) {
      perror("fcntl");
      close(recv_sockfd);
      recv_sockfd = -1;
      return false;
    }

    // char *dameo_dds_fifoPath = "/tmp/dameo_dds";
    // int dameo_dds_fd = open(dameo_dds_fifoPath, O_WRONLY);
    // int dameo_dds_signal = 1;
    // write(dameo_dds_fd, &dameo_dds_signal, 4);
    // close(dameo_dds_fd);
  }
  return true;
}

/**
 *
 *
 * @param  {string} UDS_filename_trans: UDS filename
 * @return {bool}
 * @description: close recv_socket and send_socket and server_fd_map
 */
bool TCS_UDS_DDS::file_close() {
  bool close_flag = true;

  if ((send_sockfd != -1) && (close(send_sockfd) < 0)) {
    perror("file_close_send_socket");
    close_flag = false;
  }
  send_sockfd = -1;

  if ((recv_sockfd != -1) && (close(recv_sockfd) < 0)) {
    perror("file_close_recv_socket");
    close_flag = false;
  };
  recv_sockfd = -1;

  for (auto it = server_fd_map.begin(); it != server_fd_map.end(); ++it) {
    if (close(it->second) < 0) {
      perror("file_close_server_fd_map");
      close_flag = false;
    }
  }
  server_fd_map.clear();

  return close_flag;
}

/**
 *
 *
 * @param  {char} *: read_buf points to the buffer
 * @return {int}
 * @description: recv data from another endpoint , address to read_buf
 */
int TCS_UDS_DDS::file_read(char **read_buf) {
  *read_buf = NULL;
  if (recv_sockfd < 0) {
    std::perror("file_read_recv_sockfd");
    std::exit(EXIT_FAILURE);
  }

  if (is_server) {
    int idleLength = bufLength - 6;
    int recvDataLen = 6;
    short recvDataNum = 0;
    while (1) {
      int bytes_received =
          recv(recv_sockfd, buf + bufLength - idleLength, idleLength, 0);
      if (bytes_received == -1) {
        if (bufLength == idleLength) {
          return -1;
        } else {
          memcpy(buf, (void *)&recvDataLen, 4);
          memcpy(buf + 4, (void *)&recvDataNum, 2);
          *read_buf = buf;
          return bufLength - idleLength;
        }
      }
      recvDataLen += bytes_received;
      recvDataNum += 1;
      idleLength -= bytes_received;
    }
  } else {
    int bytes_received = recv(recv_sockfd, buf, bufLength, 0);
    *read_buf = buf;
    return bytes_received;
  }

  return -1;
}

/**
 *
 *
 * @param  {const char} *path: destination file path
 * @param  {const char} *send_buf: data need to send
 * @param  {int} send_length:the length of data
 * @return {bool}
 * @description: IOTASK send data to another endpoint
 */
bool TCS_UDS_DDS::file_write_from_3902(const char *path, const char *send_buf,
                                       int send_length) {
  int server_send_socket = -1;
  if (this->server_fd_map.count(std::string(path)) == 0) {
    server_send_socket = send_data_connect(path);
    if (server_send_socket < 0) {
      return false;
    }
    this->server_fd_map[std::string(path)] = server_send_socket;
  } else {
    server_send_socket = this->server_fd_map[std::string(path)];
  }

  ssize_t numBytes = send(server_send_socket, send_buf, send_length, 0);
  if (numBytes < 0) {
    close(server_send_socket);
    this->server_fd_map.erase(std::string(path));
    perror("send");
    return false;
  }
  return true;
}

/**
 *
 *
 * @param  {char} *send_buf: data need to send
 * @param  {int} send_length: length of data
 * @return {void}
 * @description: DDS send data to another endpoint
 */
bool TCS_UDS_DDS::file_write_from_ECU(const char *send_buf, int send_length) {
  if (send_sockfd < 0) {
    send_sockfd = send_data_connect("/tmp/TB_QL_3902");
    if (send_sockfd < 0) {
      return false;
    }
  }

  if (send(send_sockfd, send_buf, send_length, 0) <= 0) {
    perror("send");
    close(send_sockfd);
    send_sockfd = -1;
    return false;
  }
  return true;
}

/**
 *
 *
 * @param  {const char} *path:
 * @return {void}
 * @description: reconnect to another endpoint,aiming to send data
 */
int TCS_UDS_DDS::send_data_connect(const char *path) {
  int send_sockfd_tmp = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (send_sockfd_tmp < 0) {
    perror("send_data_connect");
    return -1;
  }

  sockaddr_un send_addr;
  send_addr.sun_family = AF_UNIX;
  strcpy(send_addr.sun_path, path);
  if (connect(send_sockfd_tmp, (struct sockaddr *)&send_addr,
              sizeof(send_addr)) < 0) {
    close(send_sockfd_tmp);
    return -1;
  }

  return send_sockfd_tmp;
}