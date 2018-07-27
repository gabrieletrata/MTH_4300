//****************************************
// p3.cpp
// Deletes last occurence of a number of a
// sequence.
//****************************************
// Name: Gabriel Etrata
// Class MTH 4300 Spring 2018
// Professor: Ivan Matic
// Homework_4
//****************************************
// @author Gabriel Etrata
// @version 1.0
// @since 2018-02-28
// Adapted from Ivan Matic's "example_linkedList.cpp"

#include <iostream>

class ListNode{
public:
 int content;
 ListNode *pointerToNext;
};

void freeTheMemory(ListNode *runner){
 if(runner != nullptr){
 freeTheMemory((*runner).pointerToNext);
 delete runner;
 }
}

void deleteTheNumber(ListNode *runner, int x){
 if(runner->pointerToNext != nullptr){
   if((runner->pointerToNext)->content == x){
      ListNode *temp = runner->pointerToNext;
      runner->pointerToNext = (runner->pointerToNext)->pointerToNext;
      delete temp;
    } else {
      deleteTheNumber(runner->pointerToNext,x);
    }
 }
}

//Reverses the Linked List
ListNode* reverseTheList(ListNode *runner){
  ListNode* cursor = nullptr;
  ListNode* next;
  while(runner){
    next = runner->pointerToNext;
    runner->pointerToNext = cursor;
    cursor = runner;
    runner = next;
  }
  return cursor;
}

int main(){
 int userInput;
 ListNode *head;
 std::cout<<"Insert the first element of the list: ";
 std::cin>>userInput;
 head = new ListNode;
 (*head).content = userInput;
 (*head).pointerToNext = nullptr;
 ListNode *runner;
 runner = head;
 while(userInput!=-9){
 std::cout << "Insert an element of the list (-9 for the end): ";
 std::cin >> userInput;
 if(userInput!=-9){
 // *runner is the last node in the list (tail)
 // (*runner).pointerToNext is currently nullptr
 // We now allocate new memory for ListNode and make
 // (*runner).pointerToNext to contain the address
 // of this new ListNode
 (*runner).pointerToNext = new ListNode;
 // runner is no more pointing to the tail
 // The next line updates the runner to point
 // to the newly created tail
 runner = (*runner).pointerToNext;
 // We now set the content of the tail
 (*runner).content = userInput;
 // and make sure that the tail‘s pointer
 // to the the next is set to nullptr
 (*runner).pointerToNext = nullptr;
 }
 }

 std::cout << "Which number to delete? ";
 std::cin >> userInput;
 runner = new ListNode;
 runner->pointerToNext = head;
 //Reverses the Linked List
 runner = reverseTheList(runner);
 deleteTheNumber(runner,userInput);
 //Reverses the list to get back original sequence
 runner = reverseTheList(runner);
 head = runner->pointerToNext;
 ListNode *saver = runner;
 std::cout<<"List printout: "<<std::endl;
 runner = head;
 while(runner!=nullptr){
 std::cout<<(*runner).content<<" ";
 runner = (*runner).pointerToNext;
 }
 std::cout<<std::endl;

 // FREEING THE MEMORY
 freeTheMemory(saver);
 return 0;
}
