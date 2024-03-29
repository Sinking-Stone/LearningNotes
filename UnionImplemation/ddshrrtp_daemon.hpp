#ifndef DDSHRRTP_DAEMON
#define DDSHRRTP_DAEMON
#include <string>

class ddshrrtp_daemon {
private:
  std::string dameo_dds_fifoPath;
  int dameo_dds_fd;
  bool isServer;

public:
  ddshrrtp_daemon(bool isServer = 1,
                  std::string dameo_dds_filePath = "/tmp/dameo_dds");
  ~ddshrrtp_daemon();

  bool start();
  bool stop();
  int read();
};

#endif