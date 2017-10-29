#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class LinkedList; //for set to ListNode friend , Need to define first
class ListNode{
private:
    int data;
    ListNode* next;
public:
    ListNode(): data(0),next(0){};
    ListNode(int index):data(index),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;
    ListNode* first;
public:
    LinkedList():first(0){};
    void printList(); // Called- "Traversal(尋訪)" to every node
    void pushFront(int x);
    void pushBack(int x);
    void deleteNode(int x);
    void clearList();
    void reverse();
};

void LinkedList::printList(){
    if(first == 0){
        cout << "List is empty\n";
        return;
    }
    ListNode* current = first;
    while(current != 0){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::pushFront(int x){
    ListNode* newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
}

void LinkedList::pushBack(int x){
    ListNode* newNode = new ListNode(x);
    if(first == 0){
        first = newNode;
        return;
    }
    ListNode* current = first;
    while(current->next != 0){
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::deleteNode(int x){
    ListNode* current = first;
    ListNode* previous = 0;
    //Traversal First and check if node incompatible
    while(current !=0 && current->data != x){
        previous = current;
        current = current->next;
    }
    //if List empty,or List not found x
    if(current == 0){
        cout << "There is no " << x << " in list.\n";
    }else if(current == first){
        first = first->next; // current->next
        delete current; /* Free mem to Double-LinkedList(heap) */
        current = 0; /* Pointer still point to unuse struct */  // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
    }else{
        previous->next = current->next;
        delete current;
        current = 0;
        //return;   /No impact If return have or not.
    }
}

void LinkedList::clearList(){
    while(first != 0){
        ListNode* current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}

void LinkedList::reverse(){
    if(first == 0 || first->next == 0){
        //list is empty or list has only one node
        return;
    }

    ListNode* previous = 0;
    ListNode* current = first;
    ListNode* preceding = first->next;

    while(preceding != 0){
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next; //If preceding is NULL, means end of list
    }
    current->next = previous; // Redirect the current next-direction for final node
    first = current; // Let current node to be first
}

/* Main Function */
int main(){
    LinkedList list;
    list.printList(); //Empty now
    list.deleteNode(4);
    list.pushBack(5); //5
    list.pushBack(3); //5,3
    list.pushFront(9); //9,5,3
    list.printList();
    list.pushBack(4); //9,5,3,4
    list.deleteNode(9); //5,3,4
    list.pushFront(8); //8,5,3,4
    list.printList();
    list.reverse(); //4,3,5,8
    list.printList();
    list.clearList();
    list.printList();
    
    return 0;
}
