
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int answer;
    int guess;
    int left=1,right=10000;
    srand(time(NULL));
    answer = rand() % 10000;//range is 0-10000
    printf("%d is the answer",answer);
    while (1) {
        cout << "Range: " << left << "~" << right << endl;
        cin >> guess;
        if(guess > right || guess < left) exit(1);
        if(guess == answer) break;
        else{
            if(guess > answer) right = guess;
            else left = guess;
        }
    }
    cout << "You are right" << endl;
    
    
    /* Describe the range for rand() */
    while (1) {
        answer = rand() % 10000;
        cout << answer << endl;
        if(answer == 0 || answer == 10000)
            break;
        cout << answer << endl;
    }
    
    
    //System block
    return 0;
}
