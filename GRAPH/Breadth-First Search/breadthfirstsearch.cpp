// BFS Traversal
// From a given vertex (s)
// Traverses vertices reachable from s.
/* Breadth-First Search:
------------------------
  We have a Graph of V Vertices, and E edges
  Each Vertex V represents a Node or a Point in the Graph

  Breadth-First Search starts from a given Vertex (S)
  and traverses all verices reachable from (S).

  It does this by keeping (a/an):
    -> Adjacency List
    -> Visited Vertices List
    -> 

  While the queue is n
  Get all adjacent vertices of the dequeued vertex s.
  If an adjacent has not been visisted, then mark it visited and enqueue it. */
#include <iostream>
#include <list>

using namespace std;

class Graph{
  int V;                                             // # of Vertices
  list <int> *adj;                                   // Adjacency List
public:
  Graph(int V){this->V = V; adj=new list<int>[V];}   // Constructor
  void addEdge(int v, int w){adj[v].push_back(w);}   // Adds an Edge [Vertex (v) and (w)]
  void bfs(int s);                                   // Start State (s)
};

void Graph::bfs(int s){
  bool *visited = new bool[V];                       // Initialize Boolean Array (visited)
  for (int i = 0; i < V; i++) visited[i] = false;    // All Vertices -> Not visited
  list<int> queue;                                   // BFS FIFO queue
  visited[s] = true;                                 // Current Node -> Visited = true
  queue.push_back(s);                                // Add Visited Node to queue
  list<int>::iterator i;                             // i is used to get all adjacent vertices of a vertex

  while(!queue.empty()){         
    s = queue.front();           
    cout << s << " ";            
    queue.pop_front();         
    
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
      if (!visited[*i]){ visited[*i] = true; queue.push_back(*i);}
  }
}

// Driver Program
int main(){
  Graph g(4);    // Create Graph of 4 Vertices
  
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  
  cout << "Breadth First Search:" << endl;
  cout << "Starting at Vertex 2" << endl;
  g.bfs(2); // Should Output 2 0 3 1
}