#include <stdio.h>
#include <signal.h>

void sig(int s) {
  signal(SIGINT,sig);
  printf("received signal '%d'\r\n",s);
}

int main() {

  // sigemptyset(&sigs);

  if (signal(SIGINT,sig)==SIG_ERR)
    printf("could not catch SIGINT\n");
  while(1) {}
}
