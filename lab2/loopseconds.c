// #define _POSIX_SOURCE
// #define _POSIX_C_SOURCE
// #define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

volatile int itr_proceed = 0;

typedef struct sigaction sigact;

void handle_usr(int s) {
  printf("a suitable message\r\n");
}

void sig(int s) {
  printf("sigint received\r\n");
}

void handle_alarm(int s) {
  // printf("handle alarm called!\r\n");
  itr_proceed = 0;
}

int main() {
  printf("%d\r\n",getpid());
  sigset_t sig_block, sig_handle; //, sig_alarm;
  sigfillset(&sig_block);
  sigemptyset(&sig_handle);
  // sigemptyset(&sig_alarm);

  sigaddset(&sig_handle,SIGUSR1);
  // sigaddset(&sig_alarm,SIGALRM);

  sigact sig_int, sig_usr, sig_alrm;
  sig_int.sa_handler = sig;
  sig_int.sa_flags = 0;
  sig_usr.sa_handler = handle_usr;
  sig_usr.sa_flags = 0;
  sig_alrm.sa_handler = handle_alarm;
  sig_alrm.sa_flags = 0;

  sigaction(SIGUSR1,&sig_usr,0);
  sigaction(SIGINT,&sig_int,0);
  sigaction(SIGALRM,&sig_alrm,0);

  sigprocmask(SIG_BLOCK, &sig_block,0);
  sigprocmask(SIG_UNBLOCK,&sig_handle,0);

  time_t endTime = time(NULL) + 10;
  while(time(NULL)<endTime) {}
  sigset_t pend;
  sigpending(&pend);
  printf("Pending signals:\r\n");
  for (int i = 1;i!=_NSIG;++i) {
    if (sigismember(&pend, i))
      printf("%d (%s)\r\n",i,strsignal(i));
  }
  sigprocmask(SIG_UNBLOCK,&sig_block,0);

  printf("Starting iteration benchmark\r\n");
  int itr_time = 2;
  int itr_count = 0;
  itr_proceed = 1;
  alarm(itr_time);
  while(itr_proceed)
    ++itr_count;
  printf("performed %d iterations in %d seconds\r\n",itr_count,itr_time);

  printf("loop done\r\n");
}
