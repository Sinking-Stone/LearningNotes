#include "ddshrrtp_daemon.hpp"
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
ddshrrtp_daemon::ddshrrtp_daemon(bool isServer,
                                 std::string dameo_dds_filePath) {
  this->dameo_dds_fifoPath = dameo_dds_filePath;
  this->dameo_dds_fd = -1;
  this->isServer = isServer;
  if (0 < this->dameo_dds_fifoPath.size()) {
    mkfifo(this->dameo_dds_fifoPath.c_str(), 0666);
  }
}

ddshrrtp_daemon::~ddshrrtp_daemon() {}

bool ddshrrtp_daemon::start() {
  if (dameo_dds_fifoPath.size() <= 0) {
    perror("dameo_dds_fifoPath invalid");
    return false;
  }
  if (isServer) {
    this->dameo_dds_fd =
        open(dameo_dds_fifoPath.c_str(), O_RDONLY | O_NONBLOCK);
  } else {
    this->dameo_dds_fd = open(dameo_dds_fifoPath.c_str(), O_WRONLY);
  }

  if (this->dameo_dds_fd < 0) {
    perror("dameo_dds_fd invalid");
    return false;
  }
  if (!isServer) {
    // start dds_hrrtp process
    int dameo_dds_signal = 1;
    size_t dameo_dds_signal_size = write(dameo_dds_fd, &dameo_dds_signal, 4);
    if (0 < dameo_dds_signal_size) {
      return true;
    }

    return false;
  }
  return true;
}

bool ddshrrtp_daemon::stop() {
  if (!isServer) {
    int dameo_dds_signal = 2;
    size_t dameo_dds_signal_size = write(dameo_dds_fd, &dameo_dds_signal, 4);
    if (dameo_dds_signal_size <= 0) {
      return false;
    }
    close(dameo_dds_fd);
  } else {
    close(dameo_dds_fd);
  }
  this->dameo_dds_fd = -1;
  return true;
}
int ddshrrtp_daemon::read() {

  int dameo_dds_signal = -1;
  if (isServer) {
    ::read(this->dameo_dds_fd, &dameo_dds_signal, 4);
  }
  return dameo_dds_signal;
}

// // server
// int main(void) {
//   ddshrrtp_daemon ddshrrtp_daemon;
//   ddshrrtp_daemon.start();
//   while (1) {
//     std::cout << ddshrrtp_daemon.read() << std::endl;
//     usleep(100000);
//   }
//   return 0;
// }

// // client
// int main(void) {
//   ddshrrtp_daemon ddshrrtp_daemon(0);
//   ddshrrtp_daemon.start();
//   sleep(10);
//   ddshrrtp_daemon.stop();
//   return 0;
// }