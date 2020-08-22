#include<bits/stdc++.h> 
#include <vector>

class Graph{
  int V;
  std::list<int> *adj;
public:

  Graph(int V){
    this -> V = V;
    adj = new std::list<int>[V];
  }

  void addedge(int v, int w){
    adj[v].push_back(w);
  }

  void DFSUtil(int s, std::vector<bool> &visited){
    std::stack<int> stack;
    stack.push(s);
    while (!stack.empty()){
      s = stack.top();
      stack.pop();
      if (!visited[s]) std::cout << s << " "; visited[s] = true;
      for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
          stack.push(*i);
    }
  }

  void DFS(){
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
      if (!visited[i])
        DFSUtil(i, visited);
  }


};

int main() {
  Graph g(5);
  g.addedge(1, 0);
  g.addedge(2, 1);
  g.addedge(3, 4);
  g.addedge(4, 0);

  g.DFS();
  return 0;
}