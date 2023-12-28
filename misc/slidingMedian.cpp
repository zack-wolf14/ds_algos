#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<double> v)
{
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    
}

class SlidingWindow 
{
    public:
        multiset <double> arr;
        
        void insert(double x){
            arr.insert(x);
        }

        void delete_(double x)
        {
            arr.erase(arr.find(x));
        }
        double getMedian()
        {
            int n = arr.size();
            double a = *next(arr.begin(), n/2-1);
            double b = *next(arr.begin(), n/2);
            if(arr.size() & 1)return b;
            return (a+b)*0.5;
        }

        vector<double> medianSlidingWindow(int nums[], int numLength)
        {
            vector <double> ans;
            arr.clear();
            int k = nums[0];
            for(int i = 1; i<=k; i++)
            {
                if (i<numLength)
                {
                insert(nums[i]);
                ans.push_back(getMedian());
                }
                else
                {
                    break;
                }
            }
            
            
            for (int i = k+1, j=1; i<numLength; i++, j++){
                delete_(nums[j]);
                insert(nums[i]);
                ans.push_back(getMedian());
            }
            
            return ans;
        }
};
int main()
{
    SlidingWindow sd;
    int v[] = {5,2,3,6,5,7};
    vector<double> ansString = sd.medianSlidingWindow(v, 6);
    stringstream ss1;
  
    for (int i=0; i < ansString.size(); ++i)
    {
        ss1 << ansString[i];
        if (i+1!=ansString.size())
        {
            ss1 << ",";
        }
    }
    
    string medianString = ss1.str();
    cout<<medianString;
    return 0;
}