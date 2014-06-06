#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * fib_thread(){
  while(1)
  {
  }

  return;
}

int main()
{
  pthread_t tid_01;
  pthread_t tid_02;
  pthread_t tid_03;
  pthread_t tid_04;

  pthread_create(&tid_01, NULL, fib_thread, NULL);
  pthread_create(&tid_02, NULL, fib_thread, NULL);
  pthread_create(&tid_03, NULL, fib_thread, NULL);
  pthread_create(&tid_04, NULL, fib_thread, NULL);

  pthread_join(tid_01, NULL);
  pthread_join(tid_02, NULL);

  return 0;
}
