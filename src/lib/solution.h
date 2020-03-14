#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
class Graph {
public:
  Graph(std::map<int, std::set<int>> &vertices) :
  edge_map_(vertices) {}
  std::map<int, std::set<int>> edge_map_;
  std::map<int, std::set<int>> edge_map_copy_ = edge_map_;//create a copy
  std::map<int, int> BFS_ShortestDistance(int);
  std::map<int, std::vector<int>> BFS_ActualShortestPath(int);
  std::vector<int> FindRoots();
  std::vector<int> TopoSort();
  bool IfIsRoot(int);
  std::vector<bool> IfPassThrough(int, int);
};


#endif