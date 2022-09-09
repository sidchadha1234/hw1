#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>


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

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& value){
//if there is no tail item, it will create a new node 
    if(tail_==NULL){
        tail_ = new Item;
        head_ = tail_;
        tail_->first = 0;
        tail_->last = 1;
        tail_->next = NULL;
        tail_->prev = NULL;
        tail_->val[tail_->first] = value;
        size_++; 

    }

//if there is a tail item and you can add it to that tail, you just add it to the back of the val array of the tail
    else if(tail_!=NULL&&tail_->last<10){
      tail_->val[tail_->last] = value; 
      tail_->last++;
      size_++;
    }
//if there is a tail item and the val array in the list is full, you create a new node
    else if(tail_!=NULL && tail_->last>=10)
    {
        Item* temp = tail_;
        tail_->next = new Item;
        tail_ = tail_->next;
        tail_->prev = temp;
        tail_->first = 0;
        tail_->last = 1;
        tail_->val[tail_->first] = value;
        size_++;
    }
  }

  
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& value){
    //if there is no head node, you just create a new node at the start
    if(head_==NULL){
        head_ = new Item;
        tail_ = head_;
        head_->first = ARRSIZE-1; //be sure to do this as you should put first at the end of the first node
        head_->last = ARRSIZE;
        head_->next = NULL;
        head_->prev = NULL;
        head_->val[head_->first] = value;
        size_++; 
    }
    //if there is space inside head and there is a head, you just add it before first
    else if(head_!=NULL&&head_->first>0){
      head_->val[head_->first-1] = value;
      head_->first--;
      size_++;
    }
    //if there is no space inside head, then you create a head node before it and put the value at the end of that new head node
    else if(head_!=NULL && head_->first==0)
    {
        Item* temp = head_;
        head_->prev = new Item;
        head_ = head_->prev;
        head_->next = temp;
        head_->first = ARRSIZE-1;
        head_->last = ARRSIZE;
        head_->val[head_->first] = value;
        size_++;
    }
  }
  
/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
//everything works till here

  void ULListStr::pop_back(){
//if there is no tail throw an exception
    if(tail_ == NULL){
      throw std::invalid_argument("List is empty - popback");
    }
    //if the size of the whole list is 1, delete the whole list (head/tail)
    else if(size_==1){
      head_ = NULL;
      delete tail_;
      tail_ = NULL;
      size_--;
    }
    //if there is a tail and there is only one item in. the tail, delete the tail and make the previous element the tail
    else if(tail_ !=NULL && (tail_->last-tail_->first==1)){
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next=NULL;
        delete temp;
        size_--;
    }
    //if there is a tail and there is more than one item in. the tail, delete the last element of the tail
    else if(tail_!=NULL && (tail_->last-tail_->first>1)) {
        tail_->last=tail_->last-1; //this automatically deletes last as you make last the element before 
        size_--; //make sure to decrememnt size if you are deleting anything
    }


  }  
  
  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    //if there is no head throw an exception

    if((head_==NULL)){
      throw  std::invalid_argument("List is empty - popfront");
    }
    //if the size of the whole list is 1, delete the whole list (head/tail)

    else if(size_==1){
        tail_ = NULL;
        delete head_;
        head_ = NULL;
        size_--;
      }
    //if there is a head and there is only one item in the head delete the head and make the next element the head

    else if(head_!=NULL&&(head_->last-head_->first==1)){
        Item* temp = head_;
        head_ = head_->next;
        head_->prev=NULL;
        delete temp;
        size_--;
    }
    //if there is a head and there is more than one item in the head, delete the first element of the head

    else if(head_!=NULL && (head_->last-head_->first)>1) {
        head_->first=head_->first+1; 
        size_--;
    }
  }
    
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */

  std::string const & ULListStr::back() const{
//if the tail is null throw an exception (there is no back)
    if(tail_==NULL){
        throw std::invalid_argument("list is empty - back");
//otherwise just return the back of the list using this as a const reference
    }else{
        return this->tail_->val[tail_->last-1];
    }

  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
  //if the head is null throw an exception (there is no front)

     if(head_==NULL){
        throw std::invalid_argument("list is empty - front");
      }
      //otherwise just return the front of the list using this as a const reference

      else{
        return this->head_->val[head_->first];
      }
  }

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */

  std::string* ULListStr::getValAtLoc(size_t loc) const{
//if there are any errors (loc is out of bounds or size is 0), throw an exception
    if(loc>=size_||loc<0||size_==0){
       throw std::invalid_argument("invalid argument - get");
    }

    Item* temp = head_;
//place is the position within each node and r is the place within the whole list
    size_t place = temp->first;
    size_t r = 0;
//while the place within the list hasn't reached the desire locaiton, keep going
    while(r<loc){
 
      if(place == temp->last-1){ 
        //if you've reached the end of the node change to the next node
        temp=temp->next;
        place = temp->first;
      }else{
        place++; //if you haven't reached the end of the node, increment
      }
      r++;
    }     
//if you've finally reached the index you want the while statement will terminate and you can return the correct address
    return &temp->val[place];
 
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