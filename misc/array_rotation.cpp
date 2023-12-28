#include <iostream>
using namespace std;

void rotateLeft1(int arr[], int n, int digits) // Time - O(n**2) Space- O(1)
{
    for (int i = 0; i < digits; i++)
    {
        int first = arr[0];
        for (int j = 0; j < n; j++)
        {
            if (j<n-1)
            {
                arr[j] = arr[j+1];
            }
            else
            {
                arr[j] = first;
            }
        }
        
    }
    
}

void rotateLeft2(int arr[], int n, int d) // Time - O(n) Space - O(d)
{   
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];    
    }

    for (int i=0; i<n-d; i++)
    {
        arr[i] = arr[i+d]; 
    }
    
    
    for (int i=n-d, j=0;  i<n; i++)
    {
        
        arr[i] = temp[j];
        j++;
    }
}


void reverse(int arr[], int start, int end)
{   
    int move = start;
    for (int i = start; i<((end-start)/2)+move; i++)
    {   
        int temp = arr[i];
        arr[i] = arr[(end-1)-i+move];
        arr[(end-1)-i+move] = temp;
    }
}
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void rotateLeft3(int arr[], int n, int d) // Time - O(n) Space- O(1) -- Best Method
{
    reverse(arr,0,d);
    cout<<"First -> ";
    display(arr,n);

    reverse(arr,d,n);
    cout<<"Second -> ";
    display(arr,n);

    reverse(arr,0,n);
    cout<<"Final -> ";
    display(arr,n);
    
}


int main()
{
    int array[] = {1,2,3,4,5};
    cout<<"Before -> ";
    display(array,5);
    rotateLeft3(array,5,2);
    // rotateLeft2(array,5,3);
    // display(array,5);
    return 0;
}