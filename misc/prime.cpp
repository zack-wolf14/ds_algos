#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void prime(int *arr)

{   
    int size;
    arr = new int [size];
    int flag;
    cout<<"Prime No. - ";
    for (int i = 0; i<size; i++)
    {   
    
        for (int j = 2; j < arr[i]/2; j++)
        {
            
            if (arr[i]%j==0)
            {   
                flag = 1;
                break;
            }
            else if (arr[i]%j!=0)
            {
                flag=0;
                
            }
            
        }
        if (flag ==0){cout<< arr[i] << " ";}
        
    }
    
}

int main()

{
    int *array, count;

    count = 100;

    array = new int [count];
    for (int i = 0; i < count; i++)
    {
        array[i] = rand()%50;
    }
    
    prime(array);
    return 0;
}