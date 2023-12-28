//***************************************** Work-2 by Charanpreet Singh ******************************
/*2D Directed Graph Problem
Aims:
â— Implement a simple graph structure
â— Implement some algorithms using the new structure

Complete tasks 1-5. You can add extra functions, classes, exceptions as you wish.
Uncomment the relevant blocks in `main` for some feedback
*/
// Compiling and executing using g++
#include <bits/stdc++.h>
#include <array>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    // The unique identifier for this node
    std::string id;
    // The node's position in a global coordinate frame
    std::array<double, 2> position;
};

bool operator<(const Node &lhs, const Node &rhs)
{
    return lhs.id < rhs.id;
}

struct Edge
{
    // The unique identifier for this edge
    std::string id;
    // This is a directed edge from a source node to a target node
    std::string source_node;
    std::string target_node;
};

class DirectedGraph
{

public:

    //private:
    // Nodes and their adjacent edges
    std::map<Node, std::vector<Edge>> graph_;

    //mapping string values to their respective nodes
    map<string, Node> id_node; 

    // 1. Implement node insertion.
    // Nodes should have unique ids and can not be inserted multiple times.
    void AddNode(const Node &node)
    {
        // checks if a node with the same id has been inserted previously
        for (auto it = graph_.begin(); it != graph_.end(); it++)
        { 
            if (it->first.id == node.id)
            {
                cout << "There is already a node with the same id!!";
                return;
            }
        }
        vector<Edge> ed;
        graph_[node] = ed;
        id_node[node.id] = node;
    }

    // 2. Implement edge insertion.
    // Edges should have unique ids and can not be inserted multiple times.
    // The nodes that an edge references must already be present in the graph.
    // The graph may only contain one directed edge from a source to a target.
    void AddEdge(const Edge &edge)
    {
        bool found_source_node = false;
        bool found_target_node = false;
        Node nd;
        for (auto it = graph_.begin(); it != graph_.end(); it++)
        { // checks if both source node and targetnode exists
            if (it->first.id == edge.source_node)
            {
                found_source_node = true;
                nd = it->first;
            }
            if (it->first.id == edge.target_node)
                found_target_node = true;
        }
        if (found_source_node == true && found_target_node == true)
        { // checks if edge already exists
            for (auto it = graph_[nd].begin(); it != graph_[nd].end(); it++)
            {
                if (it->id == edge.id)
                {
                    cout << "Edge id already exists! \n";
                    return;
                }
            }
            graph_[nd].push_back(edge);
        }
        else
        {
            cout << "Source node or target node not present in graph, please add to the graph first!";
            return;
        }
    }

};

// 3. Return all the in-edges for some node. If the node is invalid then you should throw an exception.

std::vector<Edge> InEdges(const DirectedGraph &graph, const Node &node)
{
    if (graph.graph_.find(node) == graph.graph_.end())
    {
        throw "Node doesnt exist!";
        return vector<Edge>{};
        // throw an exception
    }
    else
    {
        vector<Edge> answer;
        for (auto it = graph.graph_.begin(); it != graph.graph_.end(); it++)
        {
            vector<Edge> current = it->second;
            for (int i = 0; i < current.size(); i++)
            {
                if (current[i].target_node == node.id)
                {
                    answer.push_back(current[i]);
                }
            }
        }
        
        return answer;
    }
}

// 4. Return all the out-edges for some node. If the node is invalid then you should throw an exception.
std::vector<Edge> OutEdges(const DirectedGraph &graph, const Node &node)
{
    if (graph.graph_.find(node) == graph.graph_.end())
    {
        throw "Node doesnt exist!";
        return vector<Edge>{};
        // throw an exception
    }
    else
    {
        vector<Edge> answer;
        answer = graph.graph_.find(node)->second;
        
        return answer;
    }
}

// 5. Search for all nodes that are reachable from `start` node without travelling more than `radius` (euclidean distance)from the start node. Nodes outside this radius should not be expanded. You may decide how to return the results. If the start node is invalid then you should throw an exception. You should decide on what a valid radius is and validate the input appropriately.
struct RadiusSearch
{
    // tbd. It should be streamable to ostream.
    vector<Node> reachable;
};

void dfs(DirectedGraph &graph, Node cur, Node root, map<string, bool> &isVisited, vector<Node> &ans, double rad)
{
    if (isVisited[cur.id])
        return;
    isVisited[cur.id] = true;
    double val = 0;
    val = (cur.position[0] - root.position[0]) * (cur.position[0] - root.position[0]) + (cur.position[1] - root.position[1]) * (cur.position[1] - root.position[1]);
    val = sqrt(val);
    if (val <= rad)
        ans.push_back(cur);
    for (auto it = graph.graph_[cur].begin(); it != graph.graph_[cur].end(); it++)
    {
        if (!isVisited[it->target_node])
        {
            dfs(graph, graph.id_node[it->target_node], root, isVisited, ans, rad);
        }
    }
}

RadiusSearch RadiusLimitedSearch(DirectedGraph &graph, const Node &start,
                                 const double radius)
{
    RadiusSearch ret;
    map<string, bool> isVisited;
    vector<Node> ans;
    dfs(graph, start, start, isVisited, ans, radius);
    ret.reachable = ans;
    return ret;
}

ostream &operator<<(ostream &os, const RadiusSearch val)
{
    os << "The reachable nodes within the radius are: \n";
    for (auto it = val.reachable.begin(); it != val.reachable.end(); it++)
    {
        os << it->id << " ";
    }
    os << "\n";
    return os;
}

int main()
{
    // Some made up places in a made up world
    const Node oxford{"oxford", {0, 0}};
    const Node culham{"culham", {-1, 0}};
    const Node london{"london", {-5, 5}};
    const Node southampton{"southampton", {-10, 0}};
    const Node manchester{"manchester", {20, -5}};
    const Node birmingham{"birmingham", {5, -5}};
    // Some made up routes between made up places
    const Edge m40_south{"m40_south", oxford.id, london.id};
    const Edge m40_north{"m40_north", london.id, oxford.id};

    const Edge a34{"a34", oxford.id, southampton.id};
    const Edge small_train{"small_train", oxford.id, culham.id};
    const Edge big_train_north{"big_train_north", oxford.id, manchester.id};
    const Edge big_train_south{"big_train_south", manchester.id, oxford.id};
    const Edge m6_south{"m6_south", manchester.id, birmingham.id};

    DirectedGraph graph;

    //Problem 1.
    graph.AddNode(oxford);
    graph.AddNode(culham);
    graph.AddNode(london);
    graph.AddNode(southampton);
    graph.AddNode(manchester);

    //Problem 2.
    graph.AddEdge(m40_south);
    graph.AddEdge(m40_north);
    graph.AddEdge(a34);
    graph.AddEdge(small_train);
    graph.AddEdge(big_train_north);
    graph.AddEdge(big_train_south);

    // Problem 3.
    const auto inbound_to_oxford = InEdges(graph, oxford);
    std::cout << "There are " << inbound_to_oxford.size() << " routes in to Oxford\n";

    // Problem 4.
    const auto outbound_from_oxford = OutEdges(graph, oxford);
    std::cout << "There are " << outbound_from_oxford.size() << " routes from Oxford\n\n";

    // Problem 5.
    const auto ten_from_oxford = RadiusLimitedSearch(graph, oxford, 10);
    std::cout << ten_from_oxford << "\n";

    return 0;
}