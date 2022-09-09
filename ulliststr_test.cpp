/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
#include <cstddef>
using namespace std;


int main(int argc, char* argv[])
{
 

    ULListStr dat;
    //the below tests all three if statements of push back
    dat.push_back("3");  

    
    for(int i = 0;i<7;i++){ 
          dat.push_back("4");
    }
    
    cout<<"This should print out 4: " <<dat.get(7)<<endl; 


    for(int i = 0;i<10;i++){ 
          dat.push_back("6");
    }
    cout<<"This should print out 6: " <<dat.get(15)<<endl; //test get 


//the below tests pop_back and get

    for(int i = 0;i<17;i++){ 
      dat.pop_back();
    }


    cout<<"This should print 3: " <<dat.get(0)<<endl; //test get 


    //the below tests push front/pop front if statements 

    dat.push_front("5"); 

    cout<<"This should print 5: "<<dat.get(0)<<endl; //bl

    dat.pop_front();

    for(int i = 0;i<7;i++){ 
      dat.push_front("4");
    }
    
    cout<<"This should print out 4: " <<dat.get(5)<<endl; 


    for(int i = 0;i<10;i++){ 
      dat.push_front("6");
    }

    cout<<"This should print out 6: " <<dat.get(2)<<endl;

    for(int i = 0;i<11;i++){ 
      dat.pop_front();
    }
    cout<<"This should print out 4: "<<dat.get(1)<<endl;

//the below tests out back and front 

    dat.push_back("7");
    dat.push_front("5");
    cout<<"This should print out 7: "<<dat.back()<<endl;
    cout<<"This should print out 5: " << dat.front()<<endl;
//this will test the edge cases for each function(null or one node)
  cout<<"EDGE CASES: "<<endl;

//popback pushback edge cases
  try{
    ULListStr edge;
    edge.push_back("3");
    edge.pop_back();
    cout<<"This should print out 0: "<<edge.size()<<endl;
    cout<<"There should be a popback exception after this:";
    edge.pop_back();
    
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
//popfront pushfront edge cases

  try{
    ULListStr edgetwo;
    edgetwo.push_front("2");
    edgetwo.pop_front();
    cout<<"This should print out 0: "<<edgetwo.size()<<endl;
    cout<<"There should be a popfront exception after this:";
    edgetwo.pop_front();
    
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
//front edge case
  try{
    ULListStr edgethree;
    cout<<"There should be a front() exception after this:";
    edgethree.front();
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}

//back edge case
  try{
    ULListStr edgefour;
    cout<<"There should be a back() exception after this:";
    edgefour.back();
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
//get edge case
  try{
    ULListStr edgefive;
    cout<<"There should be an invald get argument after this: ";
    edgefive.get(3);
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}



}
