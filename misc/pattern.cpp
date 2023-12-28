#include <iostream>
using namespace std;

void pattern1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            count = count + 1;
            cout << count << " ";
        }
        cout << endl;
    }
}

void butterfly(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n * 2; j++)
        {

            if (j <= i || j > (n * 2) - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = n * 2; j > 0; j--)
        {
            if (j > (n * 2) - i || j <= i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void reverseNumberPyr(int n)
{
    int count = 0;
    for (int i = n; i > 0; i--)
    {
        count++;
        for (int j = 0; j < i; j++)
        {
            cout << count << " ";
        }
        cout << endl;
    }
}

void binaryPyr(int n)
{
    int prev;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 && i % 2 == 0)
            {
                prev = 1;
            }
            else if (j == 0 && i % 2 != 0)
            {
                prev = 0;
            }
            else if (prev == 1)
            {
                prev = 0;
            }
            else if (prev == 0)
            {
                prev = 1;
            }

            cout << prev << " ";
        }
        cout << endl;
    }
}
void endHalfPyr(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= ((n - i) - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void palindrome(int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = i+1;
        for (int j = 0; j <(n * 2) - 1; j++)
        {
            if (j >= (n-1) - i and j <= (n-1) + i)
            {
                if (j <= n-1)
                {
                    cout << k;
                    if (i > 0 && j!=n-1)
                    {
                        
                        k--;
                    }
                }
                else if (j >n-1)
                {
                    k++;
                    cout << k;
                }
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        
    }
}
void diamond(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j>=(n-1)-i && j<=(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i = n-1; i>=0; i--)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j>=(n-1)-i && j<=(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void hollowDiamond(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j==(n-1)-i || j==(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i = n-1; i>=0; i--)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j==(n-1)-i || j==(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void hollowRectangle(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j<=(n-1)-i || j>=(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i = n-1; i>=0; i--)
    {
        for (int j = 0; j<(n*2)-1; j++)
        {
            if (j<=(n-1)-i || j>=(n-1)+i)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void rhombus(int n)
{
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout<<" ";
        }

        for(int j=1; j<=n; j++)
        {
            cout<<"*";
        }

        cout<<endl;
    }
}

void hollowRhombus(int n)
{
    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        {
            cout<<" ";
        }

        for(int j=1; j<=n; j++)
        {
            if (i>1 and i<n)
            {
                if (j==1 || j==n)
                {
                    cout<<"*";
                }
                else
                {
                    cout<<" ";
                }
            }
            else
            {
                cout<<"*";
            }
        }

        cout<<endl;
    }
}
void pyrNum(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<" ";
        }
        
        for(int j = 0; j<=i;j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}

void pyrNum2(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<" ";
        }
        
        for(int j = 0; j<=i;j++)
        {
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void butterfly(int n)
{
    for(int i = 0; i<n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<" ";
        }
        
        for(int j = 0; j<=i;j++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    //binaryPyr(5);
    pyrNum2(5);
    return 0;
}