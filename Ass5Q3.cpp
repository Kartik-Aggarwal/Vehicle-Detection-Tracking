#include <bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>>&mat, int n, int m){
    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
    for (int i=0;i<n+2;i++){
        for (int j=0;j<m+2;j++){
            if (i==0||j==0||i==n+1||j==m+1){
                vis[i][j] = true;
            }
        }
    }
    int tl = 0;
    int bl = n-1;
    int ll = 0;
    int rl = m-1;

    while (tl<bl&&ll<rl){
        
        int previ = tl;
        int prevj = ll;
        int stor = mat[tl][ll];
        int i = tl;
        int j = ll+1;
        bool l = true;
        bool t, r, b;
        while (i!=tl&&j!=ll){
            cout<<i<<" "<<j<<endl;
            if (vis[i+1][j+1]==true){
                // break;
                if (t){
                    l = true;
                    t = false;
                    j++;
                    i++;
                }else if(l){
                    b = true;
                    l = false;
                    i--;
                    j++;
                }else if(b){
                    r = true;
                    b = false;
                    j--;
                    i--;
                }else{
                    t = true;
                    r = false;
                    i++;
                    j--;
                }
            }
            vis[i+1][j+1] = true;
            int x = mat[i][j];
            mat[i][j] = stor;
            stor = x;
            if (t){j++;}
            else if (r){i++;}
            else if(b){j--;}
            else{i--;}
        }


        tl--;
        bl++;
        ll++;
        rl--;
    }

}

// sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Graph(int V);
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
 

int  main() {
    int n, m, t;
    cin>>n>>m>>t;
    vector<vector<int>>mat(n, vector<int>(m)), ans(n, vector<int>(m));
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    rotate(mat, n, m);

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }






}
