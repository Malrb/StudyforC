#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void)
{
    char password[8];
    char rndsmp[] = {'@','!'};
    int randnum,choose,number;
    srand(time(NULL));
    for(int i=0;i<8;i++){
        randnum = rand() % 3 + 1;
        switch(randnum){
            case 1:
                choose = rand() % 2;
                password[i] = rndsmp[choose];
                break;
            case 2:
                number = rand() % 10;
                password[i] = number + '0';
                break;
            case 3:
                //Random Number 65~122  instead 91~96
                number = rand() % 65 + 57;
                if(number < 65)
                    number += 30;
                password[i] = number;
                break;
        }
    }
    for(int i=0;i<8;i++){
        printf("%c",password[i]);
    }
    return 0;
}
