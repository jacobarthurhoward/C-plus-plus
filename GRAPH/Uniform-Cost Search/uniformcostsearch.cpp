#include <bits/stdc++.h>
#include <vector>

std::vector<std::vector<int> > graph;
std::map<std::pair<int, int>, int> cost; 

std::vector<int>uniformcostsearch(std::vector<int> goal, int start){
  std::vector<int> answer;
  std::priority_queue<std::pair<int, int> > queue;
  for (int i = 0; i < goal.size(); i++)
    answer.push_back(INT_MAX);
  queue.push(std::make_pair(0, start));
  std::map<int, int> visited;

  int count = 0;
  while (queue.size() > 0){
    std::pair<int, int> p = queue.top();
    queue.pop();
    p.first *= -1; // Get the original value
    if (find(goal.begin(), goal.end(), p.second) != goal.end()){
      int index = find(goal.begin(), goal.end(), p.second) - goal.begin();
      
      if (answer[index] == INT_MAX) count++;
      if (answer[index] > p.first) answer[index] = p.first;
      
      queue.pop();

      if (count == goal.size()) return answer;
    }

  /* Check for the non visited nodes
  which are adjacent to present node */
    if (visited[p.second] == 0)

    /* value is multiplied by -1 so 
    that least priority is at the top */
      for (int i = 0; i < graph[p.second].size(); i++)
        queue.push(std::make_pair((p.first + cost[std::make_pair(p.second, graph[p.second][i])]) * -1, graph[p.second][i]));
    visited[p.second] = 1;
  }
  return answer;
}


int main() {
  graph.resize(7);

  // Add Edges
  graph[0].push_back(1);
  graph[0].push_back(3);
  graph[3].push_back(1);
  graph[3].push_back(6);
  graph[3].push_back(4);
  graph[1].push_back(6);
  graph[4].push_back(2);
  graph[4].push_back(5);
  graph[2].push_back(1);
  graph[5].push_back(2);
  graph[5].push_back(6);
  graph[6].push_back(4);

  // Add Costs
  cost[std::make_pair(0, 1)] = 2; 
  cost[std::make_pair(0, 3)] = 5; 
  cost[std::make_pair(1, 6)] = 1; 
  cost[std::make_pair(3, 1)] = 5; 
  cost[std::make_pair(3, 6)] = 6; 
  cost[std::make_pair(3, 4)] = 2; 
  cost[std::make_pair(2, 1)] = 4; 
  cost[std::make_pair(4, 2)] = 4; 
  cost[std::make_pair(4, 5)] = 3; 
  cost[std::make_pair(5, 2)] = 6; 
  cost[std::make_pair(5, 6)] = 3; 
  cost[std::make_pair(6, 4)] = 7;

  // Goal State
  std::vector<int> goal;

  // Set Goal
  goal.push_back(6);

  // Get Answer
  std::vector<int> answer = uniformcostsearch(goal, 0);

  // Print Answer
  std::cout << "Minimum cost from 0 to 6 is = " << answer[0] << std::endl;

  return 0;

}