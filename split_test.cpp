
#include <iostream>
#include "split.h"

using namespace std;


int main(int argc, char* argv[]){
//create a chain of nodes (numbers 0-5)
  Node* zero = new Node(0, nullptr);
  Node* one = new Node(1, zero);
  Node* two = new Node(2, one);
  Node* three = new Node(3, two);
  Node* four = new Node(4, three);
  Node* five = new Node(5, four);

//create even and odd nodes
  Node* even = nullptr;
  Node* odd = nullptr;

//create a copy node with the last node in the list
  Node* copy = five;

//split it
  split(copy, odd, even);
//print the even nodes
  while(even!=nullptr){
    cout<<even->value;
    even = even->next;
  }
  cout<<" ";
    //print the odd nodes

  while(odd!=nullptr){
    cout<<odd->value;
    odd=odd->next;
  }
  cout<<endl;


  delete zero;
  delete one;
  delete two;
  delete three;
  delete four;
  delete five;

  
}