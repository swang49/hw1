/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  // Case 1: null list
  Node* emptyList = nullptr;
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(emptyList, odds, evens);

  // Case 2: Randomized list {3, 4, 6, 7, 10}
  Node* ranList = new Node{3, nullptr};
  ranList->next = new Node{4, nullptr};
  ranList->next->next = new Node{6, nullptr};
  ranList->next->next->next = new Node{7, nullptr};
  ranList->next->next->next->next = new Node{10, nullptr};

  odds = nullptr;
  evens = nullptr;

  split(ranList, odds, evens);

  Node* current = odds; // delete odds
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  current = evens; // delete evens
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  // Case 3: Only evens {2, 4, 6, 8, 10}
  Node* evenList = new Node{2, nullptr};
  evenList->next = new Node{4, nullptr};
  evenList->next->next = new Node{6, nullptr};
  evenList->next->next->next = new Node{8, nullptr};
  evenList->next->next->next->next = new Node{10, nullptr};

  odds = nullptr;
  evens = nullptr;

  split(evenList, odds, evens);

  current = odds; // delete odds
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  current = evens; // delete evens
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  // Case 4: Only odds {1, 3, 5, 7, 9}
  Node* oddList = new Node{1, nullptr};
  oddList->next = new Node{3, nullptr};
  oddList->next->next = new Node{5, nullptr};
  oddList->next->next->next = new Node{7, nullptr};
  oddList->next->next->next->next = new Node{9, nullptr};

  odds = nullptr;
  evens = nullptr;

  split(oddList, odds, evens);

  current = odds; // delete odds
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }

  current = evens; // delete evens
  while(current != nullptr) {
    Node* temp = current->next;
    delete current;
    current = temp;
  }
}
