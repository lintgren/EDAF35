#define _POSIX_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

typedef struct sigaction sigact;

void handle_usr(int s) {
  printf("a suitable message\r\n");
}

void sig(int s) {
  printf("sigint received\r\n");
}


int main() {
  printf("%d\r\n",getpid());
  sigset_t sig_block, sig_handle;
  sigfillset(&sig_block);
  sigemptyset(&sig_handle);

  sigaddset(&sig_handle,SIGUSR1);

  sigact sig_int, sig_usr;
  sig_int.sa_handler = sig;
  sig_int.sa_flags = 0;
  sig_usr.sa_handler = handle_usr;
  sig_usr.sa_flags = 0;

  sigaction(SIGUSR1,&sig_usr,0);
  sigaction(SIGINT,&sig_int,0);

  sigprocmask(SIG_BLOCK, &sig_block,0);
  sigprocmask(SIG_UNBLOCK,&sig_handle,0);

  time_t endTime = time(NULL) + 10;
  while(time(NULL)<endTime) {

  }
  printf("loop done\r\n");
}
