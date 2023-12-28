#include<iostream>
#include<math.h>
using namespace std;

void prime(int n)
{   
    bool flag = 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n%i==0)
        {   cout<<"Not prime";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout<<"Prime";
    }
}

int main()

{   
    int n = 48;
    prime(n);    
    return 0;
}