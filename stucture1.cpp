#include  <iostream>
#include  <bits/stdc++.h>
using namespace std;
struct Student_data  {
    string name;
    int roll_number;
    int age;
    int marks[5]; //five subjects
    int total;
    int avg;
};


int main ()
{
   int n,i,j;
   cout<<"Enter total students :";
   cin>>n;
   
   struct Student_data student[n];


for (i = 0; i < n; i++){
   cout << "Enter"<<(i+1)<<"students name:"<<endl ;
    cin >>student[i].name;
    
    cout << "Enter"<<(i+1)<<"students roll number:"<<endl;
    cin >>student[i].roll_number;
    cout << "Enter"<<(i+1)<<"students age:"<<endl;
    cin >>student[i].age;
    cout<<"Enter marks of "<<(i+1)<<"students"<<endl;
  for(j=0;j<5;j++)
  {
   cout << "Enter"<<(i+1)<<"students number:";
   cin>>student[i].marks[j];
   student[i].total=student[i].total+student[i].marks[j];

  }
  student[i].avg=student[i].total/5;
  cout<<"-------------------------------"<<endl;



    }

for(i=0; i<n;i++){
   cout<<(i+1)<<"students name"<<student[i].name<<endl;
   cout<<(i+1)<<"students name"<<student[i].roll_number<<endl;
   if(student[i].avg>75){
         cout<<"Your Grade is A"<<endl;
      }else if(student[i].avg>60){
         cout<<"Your Grade is B"<<endl;
      }else if(student[i].avg>36){
         cout<<"Your Grade is C"<<endl;
      }
      else{
         cout<<"Your Fail"<<endl;
      }
      cout<<"---------------------------------------"<<endl;


}

return 0;
}

