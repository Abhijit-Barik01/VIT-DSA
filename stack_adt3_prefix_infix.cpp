#include <bits/stdc++.h>
using namespace std;
//infixToPostfix
#define SIZE 20

void push(char);
void  pop();
char peek();
int top=-1;
char st[SIZE];



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
string infixToPostfix(string s)
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
      
        else if(s[i] == '(')
        	push('(');
        
        
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
    return ns;
    //cout <<"Postfix Expression:" <<ns << endl;
}







 string infixToprefix(string s ){
	push('@');
	string result;
	
	int n=s.length();
	for(int i=n-1;i>=0;i--){
		if((s[i]>='a'&& s[i]<='z')|| (s[i]>='A'&& s[i]<='Z')||(s[i]>='0'&& s[i]<='9'))
			{
				result+=s[i];
			}
		else if(s[i]==')')
			push(s[i]);
		else if(s[i]=='('){
			
			while(peek()!='@' && peek()!=')'){
				char c = peek();
				pop();
				result+=c;	
				
			}
			if(peek() == ')')
            {
              char c=peek();
                pop();
            }
			
		}
		else if(s[i]=='^'){
		while(peek()!='@'&& prec(s[i])<=prec(peek())){
				char c=peek();
				pop();	
				result+=c;	
		}
		push(s[i]);	
	}
		
		else{
				while(peek()!='@'&& prec(s[i])<prec(peek())){
				char c=peek();
				pop();	
				result+=c;
				
			}
			push(s[i]);	
			
		}
	}
	 while(peek() != '@')
    {
       char  c = peek();
        pop();
        result += c;
    }
    
  result=string(result.rbegin(), result.rend());
  return result;
	
	
	
	
}

//evaluation 

int sti[SIZE];
int peeki(){
   	 if(top==-1){
   	 	cout<<"stack is empty"<<endl;
		}
	else
		return sti[top];
   }
   void pushi(int value){
      if(top==SIZE-1){
      	cout<<"stack is full"<<endl;
      	
	  }
	  else{
	  	top++;
      	sti[top]= value;
      	
	  } 
 }

int evaluatePostfix(string exp) 
{ 
    // Create a stack
    
    
    int i; 

    // Scan all characters one by one 
    for (i = 0; exp[i]; ++i) 
    { 
       
        
        // If the scanned character is an 
        // operand (number here), extract the full number 
        // Push it to the stack. 
        if (isdigit(exp[i])) 
        { 
          
            pushi(exp[i] - '0'); 
            
    
        } 
        
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = peeki();
            pop();
            
            int val2 = peeki();
            pop();
            
            switch (exp[i]) 
            { 
                case '+': pushi(val2+val1); break; 
                case '-':pushi(val2-val1); break; 
                case '*':pushi(val2*val1); break; 
                case '/':pushi(val2/val1); break; 
            } 
        } 
    } 
    
    return peeki(); 
} 


int evaluatePrefix(string exp) 
{ 
    
    
    int i; 
	
    // Scan all characters one by one 
    for (i=exp.size()-1;i>=0;--i) 
    { 
        
        
 
         if (isdigit(exp[i])) 
        { 
            pushi(exp[i] - '0'); 

        } 
        
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = peeki();
            pop();
            
            int val2 = peeki();
            pop();
            
            switch (exp[i]) 
            { 
                case '+': pushi(val1+val2); break; 
                case '-':pushi(val1-val2); break; 
                case '*':pushi(val1*val2); break; 
                case '/':pushi(val1/val2); break; 
            } 
        } 
    } 
    
    return peeki(); 
} 


int main(){
	int choice;
	string exp,ns;
	while(1){
		 cout<<"\n"<<"*****HIGH  Level MENU *****"<<"\n"<<endl;
         cout<<"1. POSTFIX  conversion\n2. PREFIX conversion\n3. POSTFIX CONVERSION AND EVALUATION\n4. PREFIX CONVERSION AND EVALUATION\n5. Exit"<<endl;
	     cout<<"Enter your choice:\n";
		cin>>choice;
		switch(choice){
			case 1:
				//string exp;
			    cout<<"ENTER THE INFIX STRING TO CONVERT TO POSTFIX"<<endl;
			    cin>>exp;
			    cout <<"Postfix Expression:" << infixToPostfix(exp) << endl;

			    break;
			case 2:
				//string exp;
				cout<<"ENTER THE INFIX STRING TO CONVERT TO PREFIX"<<endl;
				cin>>exp;
				infixToprefix(exp);
			   cout <<"Prefix Expression:" << infixToprefix(exp) << endl;

				break;	
			case 3:
				 cout<<"ENTER THE INFIX STRING  FOR POSTFIX CONVERSION AND EVALUATION"<<endl;
			    cin>>exp;
				 ns=infixToPostfix(exp);
				 cout<<"POSTFIX EXPRESSION:"<<ns<<endl;
			    cout <<"POSTFIX EVALUATION OF THIS INFIX"<<ns<<"   IS:   "<<evaluatePostfix(ns); 
				break;
			case 4:
				cout<<"ENTER THE INFIX STRING  FOR PRETFIX CONVERSION AND EVALUATION"<<endl;
			    cin>>exp;
				 ns=infixToprefix(exp);
				 cout<<"PREFIX EXPRESSION:"<<ns<<endl;
			    cout <<"PREFIX EVALUATION OF THIS INFIX"<<ns<<"   IS:   "<<evaluatePrefix(ns); 
				break;

				
			case 5:
				exit(0);
			    

		}
	}
	return 0;
}
void push(char value){
	if(top==SIZE-1)
		cout<<"pstack is full"<<endl;
	else{
		top++;
		st[top]=value;
	}
	
}
void pop(){
		if(top==-1)
			cout<<"popstack is empty"<<endl;
		else
			top--;
}
char peek(){
		if(top==-1)
			cout<<"peekstack is empty"<<endl;
		else
			return st[top];
}
