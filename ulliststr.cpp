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
// pushback
void ULListStr::push_back(const std::string&val){
  if(empty()){
    Item* newItem = new Item();
    head_ = tail_ = newItem;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
  } 
  else if (tail_->last == ARRSIZE){
    Item* newItem = new Item();
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_= newItem;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

// pushfront
void ULListStr::push_front(const std::string&val){
  if(empty()){
    Item* newItem = new Item();
    head_ = tail_ = newItem;
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
  } 
  else if (head_->first == 0){
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_= newItem;
    
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
  }
  else{
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

// pop back
void ULListStr::pop_back(){
  if (empty()) return;

  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    
    if (tail_ != NULL) {
      tail_->next = NULL;
    } else {
      head_ = NULL;
    }
    delete temp;
  }
}

// pop front
void ULListStr::pop_front() {
  if (empty()) return;

  head_->first++;
  size_--;

  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    
    if (head_ != NULL) {
      head_->prev = NULL;
    } else {
      tail_ = NULL; 
    }
    delete temp;
  }
}

// return functions
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

// getValAtLoc
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc>=size_){
    return NULL;
  }

  Item* current = head_;

  while(current != NULL){
    size_t numItemsInNode = current->last - current->first;
    if(loc < numItemsInNode){
      return &current->val[current->first +loc];
    }

    loc = loc - numItemsInNode;
    current = current->next;
  }
  return NULL;
}

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
