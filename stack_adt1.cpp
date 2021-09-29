
#include  <iostream>
using namespace std;
#define SIZE 20
void push(string);
void  pop();
void display();
void peek();
void submission(string);
void firstten();
string stack[SIZE];
int top = -1;


int main(){
	
   int choice;
   string v,s;
   int f=1;
  
   while(1){
      cout<<"\n"<<"***** MENU *****"<<"\n"<<endl;
      cout<<"1. Push\n2. Pop\n3. Display\n4. Peek Last Submission\n5. Search For submission\n6. First 10 student\n7. Exit"<<endl;
      cout<<"\nEnter your choice:" <<endl;
      cin>>choice;
      switch(choice){

         case 1:
               cout<<"Enter the value to be insert:";
               cin>>v;
				//To avoid repetation of same data entry
               if(top!=-1){
						int t=top;
						for(int j=0;j<=t;j++){
		            if(v==stack[j]){
							f=0;
							cout<<"\nNumber already Exists\n";
							break;
						}
					}
					if(f==0) continue;
	            	push(v);
	         }
	         else{
				push(v);
				}
            
               break;
         case 2: 
		 	   pop();
               break;
         case 3: 
         		cout<<"Element of stack: ";
		 		 display();
                 break;
         case 4:
         	cout<<"Last register number of the last submitted record"<<endl;
         		peek();
         		break;
        case 5: 
        		cout<<"Enter the reg no of student who submitted assignment or not:"<<endl;
        		cin>>s;
        		submission(s);
        		break;
        case 6:
        		cout<<"THE REGISTER NUMBER OF FIRST 10 STUDENTS WHO SUBMITTES FIRST"<<endl;
        		firstten();
        		break;
        		
        
        case 7: exit(0);

         default: cout<<"\nWrong selection!!! Try again!!!"<<endl;


      }
   }
   return 0;
}
 void push(string value){
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
      	
         for(int i=top;i>=0;i--){
            cout<<stack[i]<<"---" ;
         }
      }
   }
   void peek(){
   	 if(top==-1){
   	 	cout<<"stack is empty"<<endl;
		}
	else
		cout<<stack[top]<<endl;
   }
   void submission( string x){
   		int f=0;
   	 if(top==-1)
         cout<<"stack is empty!!!"<<endl;
      
         for(int i=top;i>=0;i--){
            if(stack[i]==x)
            	{
            		f=1;
            		break;
				}
            	
         }
      
      if(f==1)
      	cout<<" SUBMITTED"<<endl;
      else
      	cout<<"NOT SUBMITTED YET"<<endl;
   }
   void firstten(){
   	for(int i=0;i<10;i++){
   		cout<<stack[i]<<"---";
	   }
	   
   }

