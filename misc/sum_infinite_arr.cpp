#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)

        {
            cout << arr[i] << endl;
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}

int prefix_sum(vector<int> arr, int n)
{
    vector<int> prefix_arr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefix_arr.push_back(arr[i]);
            
        }
        else
        {
            prefix_arr.push_back(arr[i] + prefix_arr[i - 1]);
            
        }
    }
    print_arr(prefix_arr, n);

    return prefix_arr[n-1];
}

int suffix_sum(vector<int> arr, int n)
{
    vector<int> suffix_arr(n);
    for (int i = n; i > 0; i--)
    {
        if (i == n)
        {
            suffix_arr[i] = arr[i];
            
        }
        else
        {
            suffix_arr[i] = (arr[i] + suffix_arr[i + 1]);
            
        }
    }
    print_arr(suffix_arr, n);

    return suffix_arr[0];
}

int main()
{
    int n;
    cout << "enter size of array ";
    cin >> n;
    vector<int> arr;
    for (int num = 0; num < n; num++)
    {
        int x;
        cout << "enter elements ";
        cin >> x;
        arr.push_back(x);
    }
    cout<<"main arr ";
    print_arr(arr, n);
    int L = 1;
    int R = 4;

    int startL = L-(n*(L/n));
    int startR = R-(n*(R/n));

    cout<<"start left - "<<startL<<endl;    
    cout<<"start right - "<<startR<<endl;    

    vector<int> arrL;
    vector<int> arrR;

    for(int i=startL-1; i<=n-1; i++)
    {
        arrL.push_back(arr[i]);
    }
    cout<<"Left arr ";
    print_arr(arrL, arrL.size());
    for(int i = startR-1; i>=0; i--)
    {
        arrR.push_back(arr[i]);
    }
    cout<<"right arr ";
    print_arr(arrR, arrR.size());
    int pre_sum = prefix_sum(arrL, arrL.size());
    int suf_sum = suffix_sum(arrR, arrR.size());
    return 0;
}