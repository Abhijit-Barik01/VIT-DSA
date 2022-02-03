#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int queue_array[MAX];
int rear =-1;
int front =-1;
int adult=0;
int children=0;
int sum=0;
void insert()
{

sum=sum+1;
if(sum>20)
{
cout<<endl<<"ALL 20 SEATES ARE RESERVED. U CAN USE VIP ENTRY OPTION FOR VIP PERSONS "<<endl;
}
	
else{
	int count= 21-sum;
	cout<<"Ride not started,  "<<count<<" people still required"<<endl;
		if(front ==-1)
			front =0;
	     int add_item;
		 cout<<"Insert the member's age in queue : "<<endl;
		 cin>>add_item;
		 rear = rear +1;
		 queue_array[rear]= add_item;
		 if(add_item>18)
		 	adult++;
		else
			children++;
	}

}



void delet(){
		if(front==rear)
			{
		  		cout<<"Queue is empty \n";
				return;
			}
	else{
			 cout<<"Element deleted from queue is :\n "<< queue_array[front]<<endl;
			 		if(queue_array[front]>=18)
			 			adult--;
			 		else
			 			children--;
			        front = front +1;
			}
    }

 void display()
	{
	cout<<"Number of adult person-->"<<adult<<endl;
	cout<<"Number of children-->"<<children<<endl;
	int i;
	if((front ==-1) || (front > rear))
      cout<<"Queue is empty \n";
	else
	{
	cout<<"Queue is : \n";
	for(i = front; i <= rear; i++)
	  cout<<queue_array[i] <<endl;
	
	}
	
	}
void vip(){
	
sum=sum+1;
if(sum>=20)
{
cout<<endl<<"All seates reserver for Ride.But we have to delet VIP entry "<<endl;
for(int i=1;i<=20;i++)
 	delet();
sum=1;
adult= 0;
children= 0;
rear =-1;
front =-1;	
}
else{

int count= 21-sum;
	cout<<"Ride not started,  "<<count<<"people still required"<<endl;
		if(front ==-1)
			front =0;
	     int add_item;
		 cout<<"Insert the vip member's age in queue : "<<endl;
		 cin>>add_item;
		 rear = rear +1;
		 queue_array[rear]= add_item;
		 if(add_item>18)
		 	adult++;
		else{
			children++;		
		}
			
	
}
}


int main(){

	{
	int choice;
	while(1)
	{
		cout<<"\n"<<"***** MENU *****"<<"\n"<<endl;
	cout<<"1.Insert member's age  for roler coster ride \n";
	cout<<"2.Display (chidren & adult) \n";
	cout<<"3.vip Entry(use this option for vip person when all seat are reserved) \n";
	cout<<"4.Quit \n";
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	      insert();
	break;

	case 2:
	         display();
	break;
	case 3:
			vip();
	break;
	case 4:
	 exit(1);
	default:
	 cout<<"Wrong choice \n";
	}


}
}
}
