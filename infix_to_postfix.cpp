/* C++ implementation to convert
infix expression to postfix*/

#include<bits/stdc++.h>
using namespace std;
#define SIZE 20


void push(char);
void  pop();
char peek();
int top=-1;
char st[SIZE];

//Function to return precedence of operators


int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix 
// expression to postfix expression
void infixToPostfix(string s)
{
    //char st[50];
    push('@');
    
    int l = s.length();
    
    string ns;
    
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, 
        // add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= '0' && s[i] <= '9'))
            ns+=s[i];
        // If the scanned character is an ‘(‘,
        // push it to the stack.
        else if(s[i] == '(')
        	push('(');
        
        // If the scanned character is an ‘)’, 
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(peek() != '@' && peek() != '(')
            {
                char c = peek();
                pop();
                
                ns += c;
            }
            if(peek() == '(')
            {
                char c = peek();
                pop();
            }
        }
        
        // If an operator is scanned
        else{
            while(peek() != '@' && prec(s[i]) <= prec(peek()))
            {
                char c = peek();
                pop();
                ns += c;
            }
            
            push(s[i]);
        }
    }
    
    // Pop all the remaining elements from the stack
    while(peek() != '@')
    {
        char c = peek();
        pop();
        ns += c;
    }
    
    cout << ns << endl;
}

// Driver Code
int main()
{
    string exp;
    cout<<"ENTER THE INFIX STRING TO CONVERT TO POSTFIX"<<endl;
    cin>>exp;
    
    infixToPostfix(exp);
    
    return 0;
}


	





  void pop(){
      if(top == -1)
      {
      cout<<"\nStack is Empty!!! Deletion is not possible!!!"<<endl;
     }
     else{
      
      top--;
      }

   }
    char peek(){
   	 if(top==-1){
   	 	cout<<"stack is empty"<<endl;
		}
	else
		return st[top];
   }
   void push(char value){
      if(top==SIZE-1){
      	cout<<"stack is full"<<endl;
      	
	  }
	  else{
	  	top++;
      	st[top]= value;
      	
	  } 
 }
      

