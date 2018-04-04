
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/* TROUBLE SHOOTING AREA
Spy++ : Microsoft software to detect window information

 */

#define BUTTON_ID      1001
static HWND hButton1;
static HWND hButton2;
static HWND hButton3;
static HWND hButton4;
static HWND hButton5;
static HWND hButton6;

//char data[1000];
FILE * fPtr;

class CMsgTestDlg{
	private:
		HWND hwnd;
	public:
		void OnClose();
		void OnExec();
		void OnEditWnd();
		void OnGetWnd();
		void OnReg();
		void OnRegMod();
};

//HINSTANCE hInst;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch(Message) {
		case WM_CREATE:
    		hButton1 = CreateWindow(TEXT("Button"), TEXT("關閉記事本"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 30, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);
		    hButton2 =  CreateWindow(TEXT("Button"), TEXT("開啟記事本"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 90, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);
		    hButton3 = CreateWindow(TEXT("Button"), TEXT("詐騙記事本"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 150, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);
			hButton4 = CreateWindow(TEXT("Button"), TEXT("取得記事本"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 210, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);	
			hButton5 = CreateWindow(TEXT("Button"), TEXT("取得IE註冊碼"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 270, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);
		    hButton6 = CreateWindow(TEXT("Button"), TEXT("修改IE註冊碼"),    
		             WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		             120, 330, 100, 40,        
		             hwnd, (HMENU) BUTTON_ID, NULL, NULL);
      		break;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			TextOut(hdc, 5, 10, "輕鬆優化 盡在疼訊", 17);
			EndPaint(hwnd, &ps);
			break;
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

void CMsgTestDlg::OnClose()
{
	HWND hWnd = ::FindWindow("TMainForm",NULL);
	if(hWnd == NULL)
	{
		MessageBox( 
   			NULL, // or specify owner window 
   			"已全部優化",  
   			"無效", 
   			MB_OK // or other flags here... 
		); 
		return;
	}
	char text[MAXBYTE] = {0};
	::SendMessage(hWnd,WM_GETTEXT,(WPARAM)MAXBYTE,(LPARAM)text);
		MessageBox( 
   			NULL, // or specify owner window 
   			text,  
   			"標題擷取", 
   			MB_OK // or other flags here... 
		); 
} 

void CMsgTestDlg::OnExec()
{
	WinExec("calc.exe",SW_SHOW);
}

void CMsgTestDlg::OnEditWnd()
{
	HWND hWnd = ::FindWindow(NULL,"未命名 - 記事本");
	if(hWnd == NULL)
	{
		MessageBox( 
   			NULL, // or specify owner window 
   			"未開啟優化",  
   			"無效", 
   			MB_OK // or other flags here... 
		); 
		return;
	}
	char* pCharText = "標題修改 By 疼訊優化軟件";
	::SendMessage(hWnd,WM_SETTEXT,NULL,(LPARAM)pCharText);
}

void CMsgTestDlg::OnGetWnd()
{
	HWND hWnd = ::FindWindow("Notepad",NULL);
	if(hWnd == NULL){
		MessageBox( 
   			NULL, // or specify owner window 
   			"未開啟優化",  
   			"無效", 
   			MB_OK // or other flags here... 
		); 
		return;
	}
	char pCharText[MAXBYTE] = {0};
	::SendMessage(hWnd,WM_GETTEXT,(WPARAM)MAXBYTE,(LPARAM)pCharText);
	MessageBox( 
   			NULL, // or specify owner window 
   			pCharText,  
   			"標題擷取", 
   			MB_OK // or other flags here... 
		); 
}
void CMsgTestDlg::OnReg()
{
	char* szKeyPath  = "Software\\Microsoft\\Internet Explorer\\Main"; 
    char* szKeyName  = "Start Page"; 
    char* szNewValue = "http://www.faccbook.idv.tw";
 
    HKEY hIESettings = NULL; 
    LONG lRes = RegOpenKeyEx(HKEY_CURRENT_USER, szKeyPath, 
        0, KEY_READ | KEY_WRITE, &hIESettings); 
 
    if (lRes != ERROR_SUCCESS) 
    { 
//        cerr << "Error opening the key: " << szKeyPath << endl; 
//        return -1; 
		MessageBox( 
   			NULL, // or specify owner window 
   			"註冊碼無效",  
   			"無效", 
   			MB_OK // or other flags here... 
		); 
    } 
 
    // Read the current value. 
    BYTE  abyOldValue[MAX_PATH]; 
    DWORD dwBufSize = MAX_PATH; 
    lRes = RegQueryValueEx(hIESettings, szKeyName, 0, NULL, abyOldValue, &dwBufSize); 
 
 
    if (lRes != ERROR_SUCCESS)  // TODO: Handle ERROR_MORE_DATA. 
    { 
//        cerr << "Error reading the value"<< endl; 
//        return -1;
		MessageBox( 
   			NULL, // or specify owner window 
   			"讀取註冊碼失敗",  
   			"無效", 
   			MB_OK // or other flags here... 
		);  
    } 
 
	fPtr = fopen("Regedit4IE.txt", "a");
	char* ptr = (char*)abyOldValue;
	if(fPtr == NULL)
    {
        /* File not created hence exit */
        //printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fputs(ptr, fPtr);
    fputs("\r\n",fPtr);
    fclose(fPtr);

 	MessageBox( 
   			NULL, // or specify owner window 
   			(char*)abyOldValue,  
   			"註冊碼", 
   			MB_OK // or other flags here... 
	);  
    //cout << "The old value: " << (char*)abyOldValue << endl; 
 
    // Set a new value. 
//    lRes = RegSetValueEx(hIESettings, szKeyName, 0, REG_SZ, 
//        (BYTE*)szNewValue, strlen(szNewValue) + 1); 
// 
//    if (lRes != ERROR_SUCCESS) 
//    { 
//        cerr << "Error writing the value"<< endl; 
//        return -1; 
//    } 
}
void CMsgTestDlg::OnRegMod()
{
	char* szKeyPath  = "Software\\Microsoft\\Internet Explorer\\Main"; 
    char* szKeyName  = "Start Page"; 
    //char* szNewValue = "about:blank"; 
    char* szNewValue = "http://www.faccbook.idv.tw";
 
    HKEY hIESettings = NULL; 
    LONG lRes = RegOpenKeyEx(HKEY_CURRENT_USER, szKeyPath, 
        0, KEY_READ | KEY_WRITE, &hIESettings); 
 
    if (lRes != ERROR_SUCCESS) 
    { 
//        cerr << "Error opening the key: " << szKeyPath << endl; 
//        return -1; 
		MessageBox( 
   			NULL, // or specify owner window 
   			"註冊碼無效",  
   			"無效", 
   			MB_OK // or other flags here... 
		); 
    } 
 
    // Read the current value. 
    BYTE  abyOldValue[MAX_PATH]; 
    DWORD dwBufSize = MAX_PATH; 
    lRes = RegQueryValueEx(hIESettings, szKeyName, 0, NULL, abyOldValue, &dwBufSize); 
 
 
    if (lRes != ERROR_SUCCESS)  // TODO: Handle ERROR_MORE_DATA. 
    { 
//        cerr << "Error reading the value"<< endl; 
//        return -1;
		MessageBox( 
   			NULL, // or specify owner window 
   			"讀取註冊碼失敗",  
   			"無效", 
   			MB_OK // or other flags here... 
		);  
    }
    
	// Set a new value. 
    lRes = RegSetValueEx(hIESettings, szKeyName, 0, REG_SZ, 
        (BYTE*)szNewValue, strlen(szNewValue) + 1); 
        
    if (lRes != ERROR_SUCCESS) 
    { 
//        cerr << "Error writing the value"<< endl; 
//        return -1; 
		MessageBox( 
   			NULL, // or specify owner window 
   			"修改註冊碼失敗",  
   			"無效", 
   			MB_OK // or other flags here... 
		);  
    } 
    
   	MessageBox( 
   		NULL, // or specify owner window 
   		"IE瀏覽器網頁已遭竄改",  
   		"警告", 
   		MB_OK // or other flags here... 
	);  
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","疼訊優化軟件",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		420, /* width */
		430, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		if(msg.hwnd == hButton1)
		{
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnClose();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
			
		}else if(msg.hwnd == hButton2){
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnExec();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
			
		}else if(msg.hwnd == hButton3){
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnEditWnd();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
			
		}else if(msg.hwnd == hButton4){
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnGetWnd();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
		}else if(msg.hwnd == hButton5){
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnReg();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
		}else if(msg.hwnd == hButton6){
			switch(msg.message)
			{
				case WM_LBUTTONDOWN:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					CMsgTestDlg cms;
					cms.OnRegMod();
					continue;
				case WM_LBUTTONUP:
					//
					//MessageBox(NULL, "Hello!","Demo!",MB_ICONEXCLAMATION|MB_OK);
					continue;
			}
		}
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
