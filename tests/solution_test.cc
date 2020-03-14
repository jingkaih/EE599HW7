#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(ShortestDistanceShould, ReturnDistance) {
  std::map<int, std::set<int>> vertices{
  {1, {2, 3}},
  {2, {1, 3, 4, 5}},
  {3, {1, 2, 4}},
  {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int, int> actual = g.BFS_ShortestDistance(1);
  std::map<int, int> expected = {std::make_pair(1,0),std::make_pair(2,1),std::make_pair(3,1),std::make_pair(4,2),std::make_pair(5,2)};
  EXPECT_EQ(expected, actual);
}

TEST(ActualShortestPathShould, ReturnPath) {
  std::map<int, std::set<int>> vertices{
  {1, {2, 3}},
  {2, {1, 3, 4, 5}},
  {3, {1, 2, 4}},
  {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int, std::vector<int>> actual = g.BFS_ActualShortestPath(1);
  std::map<int, std::vector<int>> expected = {std::make_pair(1,std::vector<int>({1})),std::make_pair(2,std::vector<int>({1,2})),std::make_pair(3,std::vector<int>({1,3})),std::make_pair(4,std::vector<int>({1,2,4})),std::make_pair(5,std::vector<int>({1,2,5}))};
  EXPECT_EQ(expected, actual);
}


TEST(FindRootsShould, ReturnAllRoots) {
  std::map<int, std::set<int>> vertices{
  {0, {}},
  {1, {0}},
  {2, {1}},
  {3, {1}},
  {4, {}},
  {5, {2, 4}},
  {6, {3, 4}},
  {7, {5, 6}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.FindRoots();
  std::vector<int> expected = {7};
  EXPECT_EQ(expected, actual);
}

TEST(TopoSortShould, ReturnTopologicalSort) {
  std::map<int, std::set<int>> vertices{
  {0, {}},
  {1, {0}},
  {2, {1}},
  {3, {1}},
  {4, {}},
  {5, {2, 4}},
  {6, {3, 4}},
  {7, {5, 6}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.TopoSort();
  std::vector<int> expected = {7,6,3,5,4,2,1,0};
  EXPECT_EQ(expected, actual);
}

TEST(IfPassThroughShould, ReturnVector) {
  std::map<int, std::set<int>> vertices{
  {0, {1, 4, 5}},
  {1, {0, 2, 3}},
  {2, {1, 3, 8}},
  {3, {1, 2}},
  {4, {0}}, 
  {5, {0, 6}},
  {6, {5, 7, 8}},
  {7, {6, 8}},
  {8, {2, 6, 7}}
  };

  Graph g(vertices);
  std::vector<bool> actual = g.IfPassThrough(0, 8);
  std::vector<bool> expected = {true,true,true,false,false,true,true,false,true};
  EXPECT_EQ(expected, actual);
}