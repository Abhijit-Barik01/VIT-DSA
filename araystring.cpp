#include  <iostream>
#include  <bits/stdc++.h>
using namespace std;
int main ()
{
  
int n,l;
  
cout << "Enter the number of strings:"<<endl;
cin>>n;
cin.ignore();
cout<<"Enter length of the string:"<<endl;
cin>>l;
 cin.ignore();
  
string str[n][l];

cout<<"Enter name of string:"<<endl;

for (int i = 0; i < n; i++){
     getline(cin,str[i][l]);
     
    }

cout<<"printing the student name:"<<endl;
for(int i=0;i<n;i++)
{
   cout<<str[i][l]<<endl;
}
return 0;
}
