#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
  //“宣告指標”與“運算式指標”是不一樣ㄉㄚ
  int* p; // 儲存一個指向整數的指標
  int* pt;
  int** ptt; // point to ptr-stored // 儲存一個指向整數的指標的指標
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
