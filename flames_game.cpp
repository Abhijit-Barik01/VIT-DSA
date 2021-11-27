#include <iostream>
#include<string>
using namespace std; 

struct Node{
    char data;
    Node* next;
    Node *prev;
    Node(char d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
int printlist(Node *head){
	cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<p->data<<" ";
}
int length(Node *head){
	int count=1;
    for(Node *p=head->next;p!=head;p=p->next)
        count++;
    return count;
}

int count(string str1,string str2)
{
    
  int n = str1.size();
   int m = str2.size();
   int tc = n + m;
   int sc = 0;
   int rc;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str1[i]== str2[j])
            {
                str1[i] = -1;
                str2[j] = -1;
                sc = sc + 2;
                break;
            }
        }
    }
 
    rc = tc - sc;
    return rc;
 
}


Node *delet(Node *head,int x){

Node *curr=head;
Node *prev1=NULL;

int count=1;
int rc=x;
while(count<x){
	curr=curr->next;
	count++;
	
}
Node *temp1= curr;
prev1=curr->prev;
curr->prev->next=curr->next;
curr->next->prev=curr->prev;
temp1->next=NULL;
delete(temp1);
return(prev1->next);
    
}

int main() 
{ 

	Node *temp1,*temp2,*temp3,*temp4,*temp5;
	Node *head=new Node('F');

	temp1=new Node('L');
    head->next=temp1;
    temp1->prev=head;
	temp2=new Node('A');
    temp1->next=temp2;
    temp2->prev=temp1;
	temp3=new Node('M');
    temp2->next=temp3;
    temp3->prev=temp2;
	temp4=new Node('E');
    temp3->next=temp4;
    temp4->prev=temp3;
	temp5=new Node('S');
    temp4->next=temp5;
    temp5->prev=temp4;
    temp5->next=head;
    head->prev=temp5;
	printlist(head);
	string str1;
	string str2;
	cout<<"\n"<<"Enter the string1:"<<endl;
	cin>>str1;
	cout<<"\n"<<"Enter the string2:"<<endl;
	cin>>str2;
	int x=count(str1,str2);
	//cout << "X: " << x << endl;
	int i=0;
	while(i<5)
	{
		head= delet(head,x);
		i++	;
	}
	
    
     //printlist(head);

     //cout<<length(head);
     
     cout<<"\n";
     switch(head->data){
        case 'F':
            cout<<str1<<" is FRIEND to "<<str2<<endl;
            break;
        case 'L':
            cout<<str1<<" is Love to "<<str2<<endl;
            break;
        case 'A':
            cout<<str1<<" is Affection to "<<str2<<endl;
            break;
        case 'M':
            cout<<str1<<" is Marriage to "<<str2<<endl;
            break;
        case 'E':
            cout<<str1<<" is ENEMY to "<<str2<<endl;
            break;

        case 'S':
            cout<<str1<<" is SISTER to "<<str2<<endl;
            break;
     }
     
  
	return 0;
} 
