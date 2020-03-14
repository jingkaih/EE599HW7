#include <iostream>
#include "src/lib/solution.h"

int main()
{
    // std::map<int, std::set<int>> vertices{
    // {1, {2, 3}},
    // {2, {1, 3, 4, 5}},
    // {3, {1, 2, 4}},
    // {4, {2, 3, 4}}
    // };
    // Graph g(vertices);
    // std::map<int, int> result = g.BFS_ShortestDistance(1);
    // std::map<int, std::vector<int>> shortestpath = g.BFS_ActualShortestPath(1);
    // for(auto x : result)
    // {
    //     std::cout <<'{'<<x.first<<','<<x.second<<'}'<<std::endl;
    // }

    // for(auto x : shortestpath)
    // {
    //     std::cout <<'{'<<x.first<<','<<'[';
    //     for(auto y: x.second)
    //     std::cout <<y<<',';
    //     std::cout <<']'<<'}'<<std::endl;
    // }


    //Q4

    // std::map<int, std::set<int>> new_vertices{
    // {0, {}},
    // {1, {0}},
    // {2, {1}},
    // {3, {1}},
    // {4, {}},
    // {5, {2, 4}},
    // {6, {3, 4}},
    // {7, {5, 6}}
    // };
    // Graph q4(new_vertices);
    // std::vector<int> roots = q4.FindRoots();

    // for(auto x : roots)
    // std::cout <<x<<' ';
    // std::cout << std::endl;

    // std::vector<int> topological = q4.TopoSort();
    // for(auto x : topological)
    // std::cout << x <<' ';



    //Q5
    // std::map<int, std::set<int>> new_new_vertices{
    // {0, {1, 4, 5}},
    // {1, {0, 2, 3}},
    // {2, {1, 3, 8}},
    // {3, {1, 2}},
    // {4, {0}}, 
    // {5, {0, 6}},
    // {6, {5, 7, 8}},
    // {7, {6, 8}},
    // {8, {2, 6, 7}}
    // };

    // Graph q5(new_new_vertices);
    // std::vector<bool> multipath = q5.IfPassThrough(0, 8);
    // for(auto x : multipath){
    //     std::cout<<x<<' ';
    //}
}