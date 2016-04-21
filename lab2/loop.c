#define _POSIX_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

typedef struct sigaction sigact;

void handle_usr(int s) {
  printf("a suitable message\r\n");
}

void sig(int s) {
  printf("sigint received\r\n");
  sigact ign_sa, usr_sa;
  ign_sa.sa_handler = SIG_IGN;
  ign_sa.sa_flags = 0;
  usr_sa.sa_handler = handle_usr;
  usr_sa.sa_flags = 0;
  sigaction(SIGUSR1,&ign_sa,0);
  sigaction(SIGUSR2,&usr_sa,0);
  while(1){}
  // printf("received signal '%d'\r\n",s);
}


int main() {
  sigset_t sigs;
  sigemptyset(&sigs);

  sigact new_sa, old_sa;
  new_sa.sa_handler = sig;
  new_sa.sa_mask = sigs;
  new_sa.sa_flags = 0;

  sigaction(SIGINT,&new_sa,&old_sa);

  while(1) {}
}
