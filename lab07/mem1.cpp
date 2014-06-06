#include <iostream>
#include <stdlib.h>
using namespace std;

int abs__(int n)
{
   cout<<"segmento codigo: "<<(void *) abs__<<"\r\n";
   n = (n<0) ? -1*n:n;

   return n;
}

int main()
{
  cout<<"segmento codigo: "<<(void *) main<<"\r\n";
  cout<<"segmento heap : "<<(void *) malloc(1)<<"\r\n";

  int x = 3;
  cout<<"segmento stack: "<<(void *) &x<<"\r\n";
  
  abs__(x);

  return 0;
}

