#include <iostream>
using namespace std;

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{   
    int n = 6;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    printarr(arr, n);

    int finalarr[n];
    for (int i = 1; i<n; i++)
    {
        
    }

    return 0;
}