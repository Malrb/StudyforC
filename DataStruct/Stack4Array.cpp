#include <iostream>
using namespace std;

class StackArray{
private:
    int top;
    int capacity;
    int* stack; // "Array" representing stack
    void DoubleCapacity();
public:
    StackArray():top(-1),capacity(1){ // constructor
        stack = new int[capacity];
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackArray::DoubleCapacity(){
    capacity *= 2; //double capacity
    int* newStack = new int[capacity];
    for(int i=0;i<capacity/2;i++){
        newStack[i] = stack[i]; // copy element to newStack
    }
    delete stack; //delete [] stack; 
    stack = newStack;
}

void StackArray::Push(int x){
    if(top == capacity - 1){
        DoubleCapacity(); // if stack is full, double the capacity
    }
    stack[++top] = x; // update top and put x into stack
}

bool StackArray::IsEmpty(){
    return (top == -1);
}

void StackArray::Pop(){
    if(IsEmpty()){
        cout << "Stack is Empty.\n";
        return;
    }
    // stack[top] = 0; --> Clear up the stack
    /* stack[top].~T(); */ //What is this?
    top--;
}

int StackArray::Top(){
    if(IsEmpty()){
        cout << "Stack is empty.\n";
        return -1;
    }
    return stack[top];
}

int StackArray::getSize(){
    return top+1;  // return the number of elements in stack
}

int main(){
    StackArray s;
    s.Pop(); // Stack empty
    s.Push(14);
    s.Push(9);
    cout << "\ntop: " << s.Top() << " size: " << s.getSize() << endl; //9,2
    s.Push(7); 
    cout << "\ntop: " << s.Top() << " size: " << s.getSize() << endl; //7,3
    s.Pop();
    s.Pop();
    cout << "\ntop: " << s.Top() << " size: " << s.getSize() << endl; //14,1
    s.Pop();
    cout << "\ntop: " << s.Top() << " size: " << s.getSize() << endl; //-1,0

    return 0;
}
