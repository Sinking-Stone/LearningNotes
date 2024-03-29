#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  char *dameo_dds_fifoPath = "/tmp/dameo_dds";
  mkfifo(dameo_dds_fifoPath, 0666);
  int dameo_dds_fd = open(dameo_dds_fifoPath, O_RDONLY | O_NONBLOCK);// O_NONBLOCK以非阻塞的方式打开
  std::cout << dameo_dds_fd << std::endl;
  while (true) {
    int dameo_dds_signal = -1;
    int dameo_dds_signal_size = read(dameo_dds_fd, &dameo_dds_signal, 4);
    std::cout << "dameo_dds_signal_size : " << dameo_dds_signal_size
              << " ; dameo_dds_signal : " << dameo_dds_signal << std::endl;
    if (dameo_dds_signal == 2) {
      break;
    }
    usleep(100000);
  }

  close(dameo_dds_fd);
}