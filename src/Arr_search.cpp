
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 20
using namespace std;
int search_sort(int[] , int, int, int);
/* Main Functions */
int main(int argc, const char * argv[]) {
    
    int i,src=0,key;
    int a[SIZE];
    srand(time(NULL));
    for(i=0;i<SIZE;i++)
        a[i] = rand() % 10 + 1;
    cout << "Search Number you want: (1~10)";
    cin >> key;
    while (SIZE > src) {
        int ans;
        ans = search_sort(a, src, SIZE, key);
        if(ans == -1){
            if(!src)
                cout << key << "not found\n";
            break;
        }else{
            cout << key << " found at a[" << ans << "] = " << a[ans] << endl;
            src = ans + 1; // Avoid the same value with key
        }
    }
    //System block
    return 0;
}

int search_sort(int a[], int src, int size, int key){
    int i;
    for(i=src;i<size;i++)
        if(a[i] == key){
            return i;
        }
    return -1;
}
