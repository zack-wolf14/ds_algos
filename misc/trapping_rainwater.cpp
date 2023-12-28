#include <iostream>
using namespace std;

int main()
{   int n = 10;
    int arr [n] = {3,4,2,9,6,2,0,5,6,1};
    int amount = 0;
    for(int i=1; i<n; i++)
    {   
        int left = arr[i];
        for (int j=i; j>0; j--)
        {   
            
            if (arr[i-j]>left)
            {
                left = arr[i-j];
            }
        
        }

        int right = arr[i];
        for (int k = n-1; k>i; k--)
        {
            
            if (arr[k]>right)
            {
                right = arr[k];

            }
        }

        if (right >=left)
        {
            amount = amount + (left-arr[i]);
        }       
        else{
            amount = amount + (right-arr[i]);
        }
    }
    cout << "Amount of Water -> " << amount;
    return 0;
}