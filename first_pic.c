#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("picture.ppm", O_CREAT | O_WRONLY, 0644);
  char buffer[256];
  write(fd, "P3\n500 500\n255\n", strlen("P3\n500 500\n255\n"));

  int x, y;
  for (x = 0; x < 500; x++){
    for (y = 0; y < 500; y++){
      sprintf(buffer, "%d %d %d\n", 255 - ((x % 2) * x * x), 255 - ((y % 2) * y * y), 255 - (((x * y) % 2) * (x * y)));
      write(fd, buffer, strlen(buffer));
    }
  }
  
  close(fd);
  return 0;
}
