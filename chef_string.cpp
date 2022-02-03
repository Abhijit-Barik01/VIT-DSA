#include<iostream>
using namespace std;
#include<vector>
string substr(string s,int start,int end){
	string ans="";
	while(start<=end){
		ans+=s[start];
		start++;
	}
	return ans;
}
int main(){
	int test;
	cin>>test;
	vector<string>main={" "," "," "};
	while(test--){
		string s;
		string ans="NO";
		cin>>s;
		int n=s.size();
	}
	return 0;
}
