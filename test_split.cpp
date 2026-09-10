/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

void printList(Node* head){
  while(head != NULL){
    std :: cout << head->value << "->";
    head = head->next;
  }
  std :: cout << "nullptr\n";
}

void deleteList(Node* head){
  while(head != NULL){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main(int argc, char* argv[])
{
  Node* in = new Node(1, new Node(1, new Node(3, new Node(4, new Node(5, nullptr)))));
  
  Node* odds = nullptr;
  Node* evens = nullptr;

  std :: cout << "Original list before split: ";

  split(in, odds, evens);

  std :: cout << "Odds list: ";
  printList(odds);

  std :: cout << "Evens list: ";
  printList(evens);

  std :: cout << "List after split: ";

  if(in == nullptr){
    std :: cout << "nullptr\n";
  } else{
    std :: cout << "NOT nullptr\n";
  }

deleteList(odds);
deleteList(evens);
}
