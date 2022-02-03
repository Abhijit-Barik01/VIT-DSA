#include<bits/stdc++.h>
using namespace std;
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
void infixToprefix(string s ){
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
    cout<<result<<endl;
  result=string(result.rbegin(), result.rend());
  //reverse(result.begin(),result.end());
    cout <<"prefix is "<<result<< endl;
	
	
	
	
}
int main(){
	
	
string exp;
    cout<<"ENTER THE INFIX STRING TO CONVERT TO PREFIX"<<endl;

    cin>>exp;
    
    infixToprefix(exp);
    
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
