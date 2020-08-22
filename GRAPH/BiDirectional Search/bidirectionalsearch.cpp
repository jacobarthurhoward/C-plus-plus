#include <bits/stdc++.h>

class Graph{
  int V;
  std::list<int> *adj;

public:
  Graph(int V){
    this -> V = V;
    adj = new std::list<int>[V];
  }

  void addedge(int u, int v){
    this -> adj[u].push_back(v);
    this -> adj[v].push_back(u);
  }

  void printpath(int *s_parent, int *t_parent, int s, int t, int intersectnode){
    std::vector<int> path; 
    path.push_back(intersectnode);
    int i = intersectnode;
    while (i != s){
      path.push_back(s_parent[i]);
      i = s_parent[i];
    }
    
    reverse(path.begin(), path.end());
    i = intersectnode;
    while (i != t){
      path.push_back(t_parent[i]);
      i = t_parent[i];
    }

    std::vector<int>::iterator it;
    std::cout << "****  PATH  ****" << std::endl;
    for (it = path.begin(); it != path.end(); it++)
      std::cout << *it << " ";
    std::cout << std::endl;
  }

  int isintersecting(bool *s_visited, bool *t_visited){
    int intersectnode = -1;
    for (int i = 0; i < V; i++)
      if (s_visited[i] && t_visited[i])
        return i;
    return -1;
  }

  void breadthfirstsearch(std::list<int> *queue, bool *visited, int *parent){
    int current = queue -> front();
    queue -> pop_front();
    std::list<int>::iterator i;
    for (i = adj[current].begin(); i != adj[current].end(); i++){
      if (!visited[*i]){
        parent[*i] = current;
        visited[*i] = true;
        queue -> push_back(*i);
      }
    }
  }


  int bidirectionalsearch(int s, int t){
    bool s_visited[V], t_visited[V];
    int s_parent[V], t_parent[V];
    std::list<int> s_queue, t_queue;
    int intersectnode = -1;

    for (int i = 0; i < V; i++){
      s_visited[i] = false;
      t_visited[i] = false;
    }

    s_queue.push_back(s);
    s_visited[s] = true;
    s_parent[s] = -1;
    t_queue.push_back(t);
    t_visited[t] = true;
    t_parent[t] = -1;

    while (!s_queue.empty() && !t_queue.empty()){
      breadthfirstsearch(&s_queue, s_visited, s_parent);
      breadthfirstsearch(&t_queue, t_visited, t_parent);

      intersectnode = isintersecting(s_visited, t_visited);
      if (intersectnode != -1){
        std::cout << "Path exists between " << s << " and " << t << std::endl;
        std::cout << "Intersection at node: " << intersectnode << std::endl;

        printpath(s_parent, t_parent, s, t, intersectnode);

        exit(0);
      }
    }
    return -1;
  }
};


int main() {
  int n = 15;    // No of vertices in Graph
  int s  = 0;    // source vertex
  int t = 14;    // target vertex

  Graph g(n);

  // Add Edges
  g.addedge(0, 4); 
  g.addedge(1, 4); 
  g.addedge(2, 5); 
  g.addedge(3, 5); 
  g.addedge(4, 6); 
  g.addedge(5, 6); 
  g.addedge(6, 7); 
  g.addedge(7, 8); 
  g.addedge(8, 9); 
  g.addedge(8, 10); 
  g.addedge(9, 11); 
  g.addedge(9, 12); 
  g.addedge(10, 13); 
  g.addedge(10, 14); 
  if (g.bidirectionalsearch(s, t) == -1) std:: cout << "Path don't exist between " << s << " and " << t << "\n"; 
  
  return 0; 
}