# EE599HW7Q3
Keep recording the path and renew it to the child
# EE599HW7Q4
I implemented 3 functions. One for finding all roots, one for topological sort and one for making topological sort more understandable.

I created a copy of edge map in order to implement kahn algorithm.
# EE599HW7Q5
In Q5, I used BFS and recorded all paths that from the start to the end.

I didn't use any data structure to check if a node was visited or not, I simply recorded the distance from one node to the start.

By checking the recorded distance of one's child and seeing if it is larger, smaller than or equal to 'parent distance + 1',

I can know if there is a multiple path.


# Time complexity
In Q3, BFS_ShortestDistance and BFS_ActualShortestPath both have a O(v+e) where v stands for vertices and e stands for edges.

In Q4, FindRoots and TopoSort are both O(v+e).

In Q5, ths function has a O(v+e).

# gtest
In Q3, I tested my function over the graph given by the professor in the graph class implementation.

In Q4 and Q5, I tested my function over the example graph in each question.