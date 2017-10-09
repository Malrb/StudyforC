#include <iostream>
/* 前置定義 (Pre-Processing) */
#define CPU "Central Processing Unit"  //定義字串
#define PI 3.14159  //定義常數
#define MAX 87
using namespace std;
int main(void)
{
    /* Difference with operation speed  */
    /* CPU register is faster than RAM memory */
    //Declare variable in CPU register
    register int reg_cpu;
    //Declare in RAM memory - the same with "int ram_mem;"
    auto int ram_mem;
    //Declare var at outside file for "included file"
    extern int outside;

    /* Testing the speed with parameter above */
    for(int i=0;i<10000;i++)
        cout<<i<<" ";
    return 0;
}
