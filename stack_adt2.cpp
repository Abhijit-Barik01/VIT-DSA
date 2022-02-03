#include  <iostream>
using namespace std;
#define SIZE 20
string backward_stack[SIZE];
string forward_stack[SIZE];
int top_backward = -1;
int top_forward=-1;
string current_add;// global variable
void push(string current_add); //push.pop,display function for low level .backward stack
void pop();
void display();
int isfull();
int isempty();
//this mainly for forward stack.midlevel
int isempty_forward();
int isfull_forward();
void pop_forward();
void display_forward();
void push_forward(string x);
//this is for higlevel
string z; //global variable
string stack[SIZE];
int top_back=-1;
int top_for=SIZE;
void push_back(string x){
      if(top_back<top_for-1){
         top_back++;
         stack[top_back]=x;
      }
      else{
         cout<<"stack is full"<<endl;
      }
}
void push_for(string x){
   if(top_back<top_for-1){
      top_for--;
      stack[top_for]=x;
   }
   else{
      cout<<"stack is full"<<endl;
   }
}
void pop_back(){
   if(top_back>=0){
      z=stack[top_back];
      top_back--;
   }
   else{
      cout<<"stack is empty";
   }

}
void pop_for(){
   if(top_for<SIZE){
     z=stack[top_for];
      top_for++;
   }
   else{
      cout<<"stack is full";
   }

}
void displaystack()
{
int i=0;
cout<<"The current page URL is:"<<z<<endl;
cout<<"FORWARD PAGES LIST:\n";
if(top_for==SIZE)
      cout<<"NO WEBPAGES\n";
else
{
   for(i=top_for;i<SIZE;i++)
      cout<<stack[i]<<endl;
}
cout<<"BACKWARD PAGES LIST:\n"<<endl;
   if(top_back==-1)
      cout<<"NO WEBPAGES\n";
   else{
      for(i=top_back;i>=0;i--)
         cout<<stack[i]<<endl;
}

}




int main(){
	
   int choice;
   string x;//taking input  web address in this variable low level
   int first=0,innerlevel_choice=1;
  
while(choice!=4){
      cout<<"\n"<<"***** MENU *****"<<"\n"<<endl;
      cout<<"1. Low Level\n2. Mid Level\n3. High Level\n4. Exit"<<endl;
      cout<<"\nEnter your choice level:" <<endl;
      cin>>choice;
         switch(choice){
            case 1:while(innerlevel_choice!=3){
               cout<<"1.Go to a new web address\n";
               cout<<"2.Go back to previous web address(use after adding new web address)\n";
               cout<<"3.Exit\n";
               cout<<"Enter your choice from low level\n";
               cin>>innerlevel_choice;
               switch(innerlevel_choice)
               {
                     case 1:
                        cout<<"Enter the web address\n";
                        cin>>x;
                        push(current_add);
                        current_add=x;
                        display();
                        cout<<"The current site is  "<<current_add<<endl;
                        break;
                     case 2: current_add=backward_stack[top_backward];
                              pop();
                              display();
                              cout<<"The current site is  "<<current_add<<endl;
                              break;

               }
            
            }
            break;

         case 2:while(innerlevel_choice!=4){
               cout<<"1.Go ahead(use after Go Back)\n";
               cout<<"2.Go back(Dont use in empty backward stack)\n";
               cout<<"3.Go to a new address\n";
               cout<<"4.Exit\n";
               cout<<"Enter your choice from mid level \n";
               cin>>innerlevel_choice;
               switch(innerlevel_choice){
                  case 1: push(current_add);//pusing in backward stack
                  current_add=forward_stack[top_forward];
                  pop_forward();
                  display(); //backward stack displaying
                  cout<<"The current site is  "<<current_add<<endl;
                  display_forward();
                  break;
                  case 2: push_forward(current_add);
                          current_add=backward_stack[top_backward];
                          pop();
                          display();//display backward stack
                          cout<<"The current site is  "<<current_add<<endl;
                          display_forward();
                          break;
                  case 3: cout<<"Enter the web address\n";
                     cin>>x;
                     if(first>0){
                     push(current_add);
                     }
                     first++;
                     current_add=x;
                     display();
                     cout<<"The current site is  "<<current_add<<endl;;
                     top_forward= -1;
                     display_forward();
                     break;

               }

            }
            break;

            case 3:
            	
				
               int t = 0;
               cout<<"Enter the new URL"<<endl;
               cin>>z;
               cout<<"\n";
               while(1)
               {
               cout<<"\nOPTIONS:\n1. Forward\n2. Backward(use after Forward& dont use it if Backward stack is Empty )\n3. Stop\n";
               cout<<"Enter your choice from High Level: ";
               cin>>t;
               switch(t){
                  case 1:
                        push_back(z);
                        
                        if(top_for==SIZE){
                           cout<<"Enter the new URL"<<endl;
                           cin>>z;

                        }
                        else
                           pop_for();
                    displaystack();
                     break;
                  case 2:
                       push_for(z);
                       pop_back();
                       displaystack();
                       break;
                  case 3:
                  	cout<<"END"<<endl;
                  	exit(0);


               }
            }
           
            break;


         
              

//         	default: cout<<"\nWrong selection!!! Try again!!!"<<endl;




         }
      
      }
      return 0;
}




//this for mainly low level//
int isempty(){
if(top_backward==-1)
   return 1;
else
   return 0;
}
int isfull(){
if(top_backward==SIZE-1)
   return 1;
else
   return 0;
}
void push(string current_add){
if(isfull())
   cout<<"stack is full\n";
else{
     top_backward++;
     backward_stack[top_backward]=current_add;
      }

}
void pop(){
if(isempty()){

   cout<<"stack is empty\n";
}
else{
   top_backward--;
}
}
void display(){
   int i;
   cout<<"web pages in backward stack\n";
    if(isempty())
      cout<<"backward stack is empty!\n";
      else{
            for(i=top_backward;i>=0;i--)
               cout<<backward_stack[i]<<endl;
               }
}


// this for mainly mid level
int isempty_forward(){
if(top_forward==-1)
   return 1;
else
   return 0;
}
int isfull_forward(){
if(top_forward==SIZE-1)
   return 1;
else
   return 0;
}

void push_forward(string current_add){
int i;
if(isfull_forward())
   cout<<"stack is full\n"<<endl;
else{
   top_forward++;
   forward_stack[top_forward]=current_add;
   }

}

void pop_forward(){
if(isempty_forward()){
cout<<"stack is empty\n";
}
else{
top_forward--;
}
}

void display_forward(){
int i;
cout<<"web adress in forward stack\n";

if(isempty_forward())
cout<<" forward stack is empty\n";
else{
for(i=top_forward;i>=0;i--)
   cout<<forward_stack[i]<<endl;
}
}
