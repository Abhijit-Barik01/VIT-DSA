#include <iostream>
#include <algorithm>
using namespace std;
int rodcutting(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(max(rodcutting(n - a, a, b, c), rodcutting(n - b, a, b, c)), rodcutting(n - c, a, b, c));
    if (res == -1)
        return -1;
    return 1 + res;
}
int main()
{
    int n = 25;
    int a = 11, b = 12, c = 13;
    cout << rodcutting(n, a, b, c);
}
