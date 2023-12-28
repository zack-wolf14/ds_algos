#include <iostream>
using namespace std;

int main()
{
    int num = 256;
    int n = 3;

    for (int i=0; i<n; i++)
    {
        cout<<num%10<<endl;
        num = num /10;
    }
    return 0;
}