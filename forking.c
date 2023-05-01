#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  printf("%d %d are the parent and child process IDs of the process before the fork\n",getppid(),getpid());
  int x = fork();
  if (x==0){
    printf("%d %d are the parent and child process IDs of child process after the fork\n",getppid(),getpid());
  }else {
  printf("%d %d are the parent and the child process IDs of the parent process after the fork\n",getppid(),getpid());
  }
  return 0;
}


