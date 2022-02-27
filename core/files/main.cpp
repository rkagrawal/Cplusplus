#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {

  FILE *fptr = fopen( "./msgfile", "w" );

  int fd = fileno(fptr);

  char buf[256];
  memset( buf, '\0', 256 );
  strcpy( buf, "Rajesh Agrawal" );

  write(fd, buf, strlen(buf) );

  *(unsigned long*) buf = 987654321;
  write(fd, buf, sizeof(unsigned long));

  FILE *fptr2 = fopen( "./msgfile", "r" );
  char buf2[256];
  int fd2 = fileno(fptr2);
  memset( buf2, '\0', 256 );
  read(fd2, buf2, 6 );
  std::cout << "Read : " << buf2 << std::endl;
  read(fd2, buf2, 8 );
  std::cout << "Read : " << buf2 << std::endl;

  read( fd2, buf2, sizeof(unsigned long));

  unsigned long xyz = *(unsigned long*) buf2;
  std::cout << xyz << std::endl;

}
