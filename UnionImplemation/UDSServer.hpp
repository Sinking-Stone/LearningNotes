#ifndef UDSServer
#define UDSServer

#include <map>
#include <string>
#include <sys/un.h>

class TCS_UDS_DDS {
private:
  // std::string UDS_filename;

  int recv_sockfd;
  int send_sockfd;
  std::map<std::string, int> server_fd_map;

  // struct sockaddr_un sock_addr;
  char *buf;
  int bufLength = 1048576;
  // true represents async,false represents sync;
  bool is_server;
  // struct sockaddr_un send_addr;

public:
  TCS_UDS_DDS();
  ~TCS_UDS_DDS();

  // flag: true represents async,false represents sync;UDS_filename_trans
  // represents filepath+filename;
  bool init(std::string UDS_filename_trans, bool flag);

  bool file_close();
  // return:byte_read_num   read_buf:address of buffer
  int file_read(char **read_buf);
  // send_addr:sender's filepath+filename
  bool file_write_from_3902(const char *path, const char *send_buf,
                            int send_length);

  bool file_write_from_ECU(const char *send_buf, int send_length);
  int send_data_connect(const char *path) ;
};

#endif