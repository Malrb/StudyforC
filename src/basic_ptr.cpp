#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
  int* p;
  int* pt;
  int** ptt; // point to ptr-stored
  int x = 1;
  p = &x;
  pt = p;
  ptt = &p;
  cout << p << endl;  // x mem
  cout << *p << endl;  // x val
  cout << pt << endl;  // x mem
  cout << *pt << endl; // x val
  cout << ptt << endl; // p mem
  cout << *ptt << endl; // x mem
  cout << **ptt << endl; // x val
  return 0;
  
  /* OUTPUT---
  0xbff53b38
  1
  0xbff53b38
  1
  0xbff53b44
  0xbff53b38
  1
  */
}
