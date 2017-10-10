#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int cmpString(char*, char*);
/* Main Functions */
int main(int argc, const char * argv[]) {
    
    int checksum;
    char word1[] = "I like C";
    char word2[] = "This is fun";
    checksum = cmpString(word1, word2);
    if(!checksum)
        cout << "String equals\n";
    else
        cout << "String Not equals\n";
    
    //System block
    return 0;
}
int cmpString(char* str1, char* str2)
{
    int i;
    //cout << str1 --> output: whole char[] (string)
    for (i=0; !(*(str1+i) == '\0' && *(str2+i) == '\0'); i++) {
        if(*(str1+i) != *(str2+i)) return -1;
    }
    return 0;
}

/******************************************
Introduce the how pointer work with array
******************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
/* Main Functions */
int main(int argc, const char * argv[]) {
    char str1[10];
    char* ptr;
    scanf("%s",str1);
    /* INPUT: Chishen */
    ptr = str1;//get str1 address and let ptr point to (start adr)
    cout << ptr[2];
    /* OUTPUT: i */
}
