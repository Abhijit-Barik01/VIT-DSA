
#include  <iostream>
using namespace std;
#define SIZE 10
void push(int);
void  pop();
void display();
int stack[SIZE], top = -1;


int main(){
	
   int choice;
   int v;
  
   while(1){
      cout<<"\n"<<"***** MENU *****"<<"\n"<<endl;
      cout<<"1. Push\n2. Pop\n3. Display\n4.Exit"<<endl;
      cout<<"\nEnter your choice:" <<endl;
      cin>>choice;
      switch(choice){

         case 1:
               cout<<"Enter the value to be insert:";
               cin>>v;
               
               push(v);
            
               break;
         case 2: 
		 	   pop();
               break;
         case 3: 
		 		 display();
                 break;
         case 4: exit(0);

         default: cout<<"\nWrong selection!!! Try again!!!"<<endl;


      }
   }
   return 0;
}
 void push(int value){
      if(top==SIZE-1){
      	cout<<"stack is full"<<endl;
      	
	  }
	  else{
	  	top++;
      	stack[top]= value;
      	cout<<"insertion sucessfull"<<endl;
	  }   
      
      
   }
   void pop(){
      if(top == -1)
      {
      cout<<"\nStack is Empty!!! Deletion is not possible!!!"<<endl;
     }
     else{
      cout<<"\nDeleted :"<< stack[top]<<endl;
      top--;
      }

   }
   void display(){
      if(top==-1)
         cout<<"stack is empty!!!"<<endl;
      else{
      	cout<<"Element of stack";
         for(int i=top;i>=0;i--){
            cout<<stack[i]<<" " ;
         }
      }
   }

