#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#define MAX 50
int main(int argc, char* argv[])
{
	//HIDE CONSOLE DURING EXECUTING
	//ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);
// 	HWND hwnd_win = GetForegroundWindow();
//    ShowWindow(hwnd_win,SW_HIDE);
//    _sleep(4000);
//    ShowWindow(hwnd_win,SW_SHOW);
// 	COPY FILE INTO SPECIFIED PATH 
	char path[] = "C:\\Users\\rb\\Documents\\copy.exe";
  	char charArray[MAX];
  	HMODULE hmodule = GetModuleHandle(0);
  	GetModuleFileName(hmodule, charArray, MAX);
  	CopyFile(charArray, path, TRUE);
  	
  	HRESULT hr;
	LPCTSTR Url = _T("https://cdn.free.com.tw/blog/wp-content/uploads/2014/08/Placekitten480-g.jpg"), File = _T("C:\\Users\\rb\\Documents\\download.jpg");
//	TCHAR url[] = TEXT("https://cdn.free.com.tw/blog/wp-content/uploads/2014/08/Placekitten480-g.jpg");
//	TCHAR path[MAX] = TEXT("C:\\Users\\rb\\Documents\\download.jpg");
//	GetCurrentDirectory(MAX, path);

/*	For an individual user:
	C:\users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup

	For all users:
	C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup
*/	
	hr = URLDownloadToFile (0, Url, File, 0, 0);
	switch (hr)
	{
		case S_OK:
			printf("Successful download\n");
			break;
		case E_OUTOFMEMORY:
			printf("Out of memory error\n");
			break;
		case INET_E_DOWNLOAD_FAILURE:
			printf("Cannot access server data\n");
			break;
		default:
			printf("Unknown error\n");
			break;
	}
	
	//FreeConsole();

	system("pause");
	return 0;
}
