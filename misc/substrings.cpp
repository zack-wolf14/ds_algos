#include <iostream>
using namespace std;

int main()
{
    string s = "abcde";
    int n = s.length();
    int len = n;
    for (int i=0; i<n; i++)
    {   
        for (int j = 1; j<=len; j++)
        {   
            cout<<s.substr(i,j)<<endl;
            
        }
        len--;
    }
    
    return 0;
}