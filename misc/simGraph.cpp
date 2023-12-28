#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Graph
{
    int vertex;
    list<int> *l;
public:
    Graph(int v)
    {
        this->vertex = v;
        l = new list<int>[v];
    }

    void addEdge(int a , int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
        
    }
    void displayGraph() 
    {
        for(int i=0; i<vertex; i++)
        {
            cout << "Vertex - " << i << "--> ";
            for(int out:l[i])
            {
                cout << out << " ";
            }

            cout<<endl ;
            
        }
    }

}; 

int main()
{
    Graph g(5);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(4,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,4);

    g.displayGraph();
    return 0;
}