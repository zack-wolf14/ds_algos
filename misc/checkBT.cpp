#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//1. parent should be one for each child (child,parent)
//2. parent should have atmost 2 children (parent, (child1,child2))
//3. check for all iteration

bool checkBT(vector<string> strArr)
{
    unordered_map<int, vector<int>> parents;
    unordered_map<int, int> children;

    for (int i = 0; i < strArr.size(); i++)
    {
        int child = strArr[i][1];
        int parent = strArr[i][3];

        if (parents.count(parent))
        {
            parents[parent].push_back(child);
        }
        else
        {
            parents[parent] = {child};
        }

        if (parents[parent].size()>2)
        {
            return false;
        }

        if (children.count(child))
        {
            return false;
        }
        else
        {
            children[child] = parent;
        }
    }
    return true;
} 
int main()
{   
    vector<string> strArr {"(1,2)", "(3,2)", "(2,4)", "(5,2)"};
    cout<<checkBT(strArr)<<endl;   
    return 0;
}