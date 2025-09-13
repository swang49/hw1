#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) { // Must run in O(1)
  if(tail_ == nullptr) { // Base case: empty list
    tail_ = new Item(); // create new Node
    head_ = tail_;
  }

  if(tail_->last == ARRSIZE) { // allocate new node if needed
    Item* newNode = new Item();
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
  }

  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++; // increment size of array as needed
}

void ULListStr::push_front(const std::string& val) { // Must run in O(1)
  if(head_ == nullptr) { // Base case: empty list, same as push_back but for head pointer
     head_ = new Item();
     tail_ = head_;
     head_->first = ARRSIZE;
     head_->last = ARRSIZE;
  }

  if(head_->first == 0) { // allocate new node if needed
    Item* newNode = new Item(); 
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  head_->first--;
  head_->val[head_->first] = val;
  size_++; // increment size of array as needed
}

void ULListStr::pop_back() { // Must run in O(1)
  if(tail_ == nullptr) { // Base case: empty list
    return;
  }

  tail_->last--; // Move back
  size_--;

  if(tail_->first == tail_->last) { // If node is empty, delete it
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_ != nullptr) {
      tail_->next = nullptr;
    }
    else {
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::pop_front() { // Must run in O(1)
  if(head_ == nullptr) { // Base case: empty list
    return;
  }

  head_->first++; //Move forwards
  size_--;

  if(head_->first == head_->last) { // If node is empty, delete it
    Item* temp = head_;
    head_ = head_->next;
    if(head_ != nullptr) {
      head_->prev = nullptr;
    }
    else {
      tail_ = nullptr;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const { // Must run in O(1)
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const { // Must run in O(1)
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const { // Must run in O(n)
  if(loc >= size_) { // If the location is out of bounds
    return nullptr;
  }

  Item* temp = head_; // Start from head
  size_t index = 0; // Tracks index

  while(temp != nullptr) { // Loop through
    size_t count = temp->last - temp->first; // Number of elements
    if(loc < index + count) { // If in range
      return &temp->val[temp->first + (loc - index)];
    }

    index += count; // if not found, move to next node
    temp = temp->next; 
  }

  return nullptr; // If any errors
}
// End of my code

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
