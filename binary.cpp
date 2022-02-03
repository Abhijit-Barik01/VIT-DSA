//this code for convert a decimal number to binARY FROM DECIMAL
#include <iostream>
using namespace std;
int binary(int n)
{
	if (n == 0)
		return;
	binary(n / 2);
	cout << (n % 2) << endl;
	return 0;
}
int main()
{
	int n;
	cin >> n;
	binary(n);
	return 0;
}
