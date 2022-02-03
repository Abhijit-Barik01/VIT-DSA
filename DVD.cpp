//using circular queue
#include <iostream>
using namespace std;

class Queue{
	int *arr;
	int front,size, capacity;
	Queue(int c){
		arr=new int[c];
		capacity=c;
		front=0;
		size=0;
	}

};





int main(){
	
	int choice;
	while(1){

cout<<"1.Insert element to queue \n"; 
cout<<"2.Delete element from queue \n"; 
cout<<"3.Display all elements of queue \n"; 
cout<<"4.Quit \n"; 
cout<<"Enter your choice : "; 
		cin>>choice;

switch(choice){
	case 1:
		q.enqueue();
		break;
	case 2:
		q.dequeue();
		break;
	case 3:
		q.display()
		break;
	case 4:
	exit (1);
	default:
		cout<<"Wrong choice";
}
	}
}
bool isFull(){
	return(q.size==q.capacity);
}
bool isEmpty(){
	return(q.size==0);
}
int getfront(){
	if(q.isEmpty())
		return -1;
	else
		return q.front;
}
int getRear(){
	if(q.isEmpty())
		return -1;
	else{
	return (q.front+q.size-1)%q.capacity;
	}
}
void enqueue(int x){
	if(q.isFull())
		cout<<"DVD BUFFER IS FULL";
	int rear=q.getRear();
	q.rear=q.rear+1;
	arr[q.rear]=x;

}
void dequeue(){
	if(q.isEmpty())
		cout<<"NO DATA IN  DVD TO DELETE ";
  q.front=(q.front+1)%capacity;
  size--;

}
void display()
{
	//queue<int>q=&p;
	while(!q.isEmpty()){
		cout<<q.getFront();
		q.dequeue();
	}
}

int main(){
	struct q(50);
	int choice;
	while(1){

cout<<"1.Insert element to queue \n"; 
cout<<"2.Delete element from queue \n"; 
cout<<"3.Display all elements of queue \n"; 
cout<<"4.Quit \n"; 
cout<<"Enter your choice : "; 
		cin>>choice;

switch(choice){
	case 1:
		q.enqueue();
		break;
	case 2:
		q.dequeue();
		break;
	case 3:
		q.display()
		break;
	case 4:
	exit (1);
	default:
		cout<<"Wrong choice";
}
	}
}
