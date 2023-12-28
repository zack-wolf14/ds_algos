#include <iostream>
using namespace std;

int main()
{
    int origNum = 152;
    int sum = 0;
    int num = origNum;

    while(num>0)
    {   
        int n = num%10;
        sum = sum + (n*n*n);
        num = num/10;
    }

    cout<<sum<<endl;
    
    if (sum==origNum)
    {
        cout<<"Armstrong";
    } 
    return 0;
}