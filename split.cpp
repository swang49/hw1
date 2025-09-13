/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void addToEnd(Node*& head, Node* newNode);

void split(Node*& in, Node*& odds, Node*& evens) {
  /* Add code here */
// WRITE YOUR CODE HERE

// Base case - in is an empty linked list
  if(in == nullptr) {
  return;
  }

// Implementation if in is NOT empty
  Node* current = in;
  Node* list = in->next;
  current->next = nullptr;

  split(list, odds, evens); // Recursively call function until only one element of in is left 

  if(current->value % 2 == 0) { // If current value is even, add to evens
    addToEnd(evens, current);
  }
  else {
    addToEnd(odds, current); // If current value is odd, add to odds
  }

// Make sure to make in nullptr at the end
  in = nullptr;
}

/* If you needed a helper function, write it here */
void addToEnd(Node*& head, Node* newNode) { // helper function to make adding to evens and odds easier
  if(head == nullptr) {
    head = newNode;
  }
  else {
    addToEnd(head->next, newNode);
  }
}