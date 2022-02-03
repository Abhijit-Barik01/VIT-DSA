#include<bits/stdc++.h>
using namespace std;
#define SIZE 70
int st[SIZE];
int top=-1;

void pop(){
      if(top == -1)
      {
      cout<<"\nStack is Empty!!! Deletion is not possible!!!"<<endl;
     }
     else{
      
      top--;
      }

   }
    int peek(){
   	 if(top==-1){
   	 	cout<<"stack is empty"<<endl;
		}
	else
		return st[top];
   }
   void push(int value){
      if(top==SIZE-1){
      	cout<<"stack is full"<<endl;
      	
	  }
	  else{
	  	top++;
      	st[top]= value;
      	
	  } 
 }

int evaluatePostfix(string exp) 
{ 
    // Create a stack
    
    
    int i; 
//    reverse(exp.begin(),exp.end());
	
    // Scan all characters one by one 
    for (i=exp.size()-1;i>=0;--i) 
    { 
        // if the character is blank space then continue 
        if(exp[i] == ' ')continue; 
        
        // If the scanned character is an 
        // operand (number here), extract the full number 
        // Push it to the stack. 
        else if (isdigit(exp[i])) 
        { 
            int num=0,j= i; 
            while (i < exp.size() && isdigit(exp[i]))
                i--;
            i++;
            
            // extract full number 
            for(int k=i;k<=j;k++)
            { 
                num = num * 10 + (int)(exp[k] - '0'); 

            } 
            
            
            // push the element in the stack 
            push(num); 
        } 
        
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = peek();
            pop();
            
            int val2 = peek();
            pop();
            
            switch (exp[i]) 
            { 
                case '+': push(val1+val2); break; 
                case '-':push(val1-val2); break; 
                case '*':push(val1*val2); break; 
                case '/':push(val1/val2); break; 
            } 
        } 
    } 
    
    return peek(); 
} 

// Driver code
int main() 
{ 
    string exp;
    cout<<"Enter the prefix expression";
    getline(cin,exp);
    cout << evaluatePostfix(exp); 
    return 0; 
}
