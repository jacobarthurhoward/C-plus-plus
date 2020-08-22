#include <bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list<int> *adj;

  void DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i]) DFSUtil(*i, visited);
  }


public:


  Graph(int V){
    this -> V = V;
    adj = new list<int>[V]; 
  }
  
  void addedge(int v, int w){
    adj[v].push_back(w); // add w to v's list
  }

  void DFS(int v){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
      visited[i] = false;
    DFSUtil(v, visited);
  }
};


int main() {
  Graph g(4);
  g.addedge(0, 1);
  g.addedge(0, 2);
  g.addedge(1, 2);
  g.addedge(2, 0);
  g.addedge(2, 3);
  g.addedge(3, 3);

  g.DFS(2);
  
  return 0;
}