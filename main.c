#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  int id = fork();
  if (id==0) {
    sleep(1);
  
  }
  printf("current id: %d parent id: %d\n",getpid(),getppid());
}
