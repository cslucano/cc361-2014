#include <iostream>
#include <stdlib.h>
using namespace std;

int main() 
{
  cout<<"ubicacion del bloque de codigo(code) : \n"<<(void*)main<<"\n\n";
  int* x = new int;
  cout<<"ubicacion del bloque heap : \n"<<x<<"\n\n";
  int y = 3;
  y = y + 10;
  cout<<"ubicacion de la pila - stack: \n"<<&y<<"\n\n";

  return 0;
}
