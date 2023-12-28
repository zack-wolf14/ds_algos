#include <iostream>
using namespace std;

void binarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    

    while (left!=right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] < x)
        {
            left = mid;
        }
        else if (arr[mid] > x)
        {
            right = mid;
        }
        else
        {
            cout << "at Index - " << mid;
        }
    }
}
int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int x = 4;

    binarySearch(arr, n, x);

    return 0;
}