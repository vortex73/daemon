#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  int id = fork();
  printf("Hello World from id : %d\n",id);
  if (id == 0) {
    printf("Hello from the child process");
  
  } else {
  printf("Hello From the main process\n");
  }
  return 0;
}
