#include "solution.h"
//Question 3
std::map<int, int> Graph::BFS_ShortestDistance(int root)
{
  std::map<int, int> marks;
  std::map<int, int> distance;
  std::queue<int> q;
  q.push(root);
  marks[root] = 1;//1 means visited
  distance[root] = 0;
  while (!q.empty())
  {
    int cur = q.front();
    int dis_of_parent = distance[cur];
    q.pop();
    for (auto &n : edge_map_[cur])
    {
      if (!marks[n])
      {
        marks[n] = 1;
        distance[n] = dis_of_parent + 1;
        q.push(n);
      }
    }
  }
  return distance;
}
//Question 3
std::map<int, std::vector<int>> Graph::BFS_ActualShortestPath(int root)
{
  std::map<int, int> marks;
  std::map<int, std::vector<int>> shortest_path;
  std::queue<int> q;
  q.push(root);
  marks[root] = 1;//1 means visited
  shortest_path[root] = {root};
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (auto &n : edge_map_[cur])
    {
      if (!marks[n])
      {
        marks[n] = 1;
        shortest_path[n] = shortest_path[cur];
        shortest_path[n].push_back(n);
        q.push(n);
      }
    }
  }
  return shortest_path;
}
//Question 4
std::vector<int> Graph::FindRoots()
{
  std::map<int, bool> incoming_edge_;
  std::vector<int> roots;
  for(int i = 0; i < edge_map_.size(); i++)
  incoming_edge_.insert(std::make_pair(i, false));
  for(auto node: edge_map_)
  {
    for(auto x: node.second)
    incoming_edge_[x] = true;
  }
  for(auto x: incoming_edge_)
  {
    if(x.second == false)
    roots.push_back(x.first);
  }
  return roots;
}
//Question 4
bool Graph::IfIsRoot(int node)//this is a helper function. its main purpose is to find if a node has no incoming edges
{
  bool result = true;
  for(auto x : edge_map_copy_)
  {
    if(x.second.count(node) != 0)
    {
      result = false;
      break;
    }
  }
  return result;
}
//Question 4
std::vector<int> Graph::TopoSort()
{
  std::stack<int> next;
  std::vector<int> result;
  std::vector<int> roots = this->FindRoots();
  for(auto x : roots)
  next.push(x);

  while(result.size()!=edge_map_.size())
  {
    
    int cur = next.top();
    result.push_back(cur);
    next.pop();
    std::set<int> neighbors = edge_map_copy_[cur];
    edge_map_copy_[cur] = {};//remove all outgoing edges of cur
    for(auto neighbor : neighbors)
    {
      if(IfIsRoot(neighbor))//if neighbor has no incoming edges
      next.push(neighbor);
    }
  }
  return result;
}
//Question 5
std::vector<bool> Graph::IfPassThrough(int start, int end)
{
  std::map<int, int> node_dis_;//intiate with n INT8_MAX
  for(int i = 0; i < edge_map_.size(); i++)
  node_dis_.insert(std::make_pair(i, INT8_MAX));

  std::queue<int> q;

  std::map<int, std::vector< std::vector<int> > > multi_short_paths_;//Store all possible paths. Initiate with n empty record
  std::vector<std::vector<int>> null_path = {{}};
  for(int i = 0; i < edge_map_.size(); i++)
  multi_short_paths_[i] = null_path;

  std::vector<std::vector<int>> start_to_start = {{start}};
  multi_short_paths_[start] = start_to_start;

  q.push(start);
  node_dis_[start] = 0;

  while(!q.empty())
  {
    int cur = q.front();
    q.pop();
    int cur_dis_ = node_dis_[cur];
    for(auto child: edge_map_[cur])
    {

      if(cur_dis_ + 1 < node_dis_[child])//
      {
        q.push(child);
        node_dis_[child] = cur_dis_ + 1;
        multi_short_paths_[child] = multi_short_paths_[cur];
        for(auto &parent_path : multi_short_paths_[child])//child must inherit potentially existed multiple path form parent
        parent_path.push_back(child);
        
      }
      else if(cur_dis_ + 1 == node_dis_[child]) //find out that one of my child has already been visited
                                                //so he must have parent other than me and that guy is at same level with me
                                                //means an alternative path is generated from my side, so I will add this path to the path recorder
      {
        for(auto parent_path : multi_short_paths_[cur])
        {
          std::vector<int> cur_path = parent_path;
          cur_path.push_back(child);
          multi_short_paths_[child].push_back(cur_path);//double what we have. e.g.{{1,2,4}}--->{{1,2,4},{1,3,4}}
        }
      }

    }
  }

  std::vector<bool> result(edge_map_.size(), false);
  for(auto path : multi_short_paths_[end])
  {
    for(auto it = path.begin(); it!= path.end(); it++)
    {
      result[*it] = true;
    }
  }
  return result;
}