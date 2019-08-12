1129. Shortest Path with Alternating Colors

Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.
Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.
Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).
 
Example 1:
Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
Output: [0,1,-1]
Example 2:
Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
Output: [0,1,-1]
Example 3:
Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
Output: [0,-1,-1]
Example 4:
Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
Output: [0,1,2]
Example 5:
Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
Output: [0,1,1]
 
Constraints:
1 <= n <= 100
red_edges.length <= 400
blue_edges.length <= 400
red_edges[i].length == blue_edges[i].length == 2
0 <= red_edges[i][j], blue_edges[i][j] < n

给出一个有向图（有重边，有平行边），n个顶点，每条边有红蓝两色，输出从节点0到节点i(0<=i<=n-1)的最短路径的长度，且路径上的颜色必须交替。
可以看出是BFS解题的思路。我们在使用BFS时，假设当前的节点是curr，此时需要遍历它的邻居时需要判断边的颜色；我们为每一个节点记录一个颜色，表示
上次经过的边的颜色。然后维护一个cost数组，这个数组既发挥visit数组的作用，也表示路径的长度。

class Solution {
private:
    const int RED = 0;
    const int BLUE = 1;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int> > > G(n);
        for(auto e : red_edges)
            G[e[0]].push_back(make_pair(e[1], RED));
        for(auto e: blue_edges)
            G[e[0]].push_back(make_pair(e[1], BLUE));
        
        vector<pair<int, int> > cost(n, make_pair(-1, -1)); 
        queue<pair<int, int> > que;
        que.push(make_pair(0, RED));
        que.push(make_pair(0, BLUE));
        cost[0].first = cost[0].second = 0;
        
        while(!que.empty()){
            pair<int, int> curr = que.front(); que.pop();
            for(auto e : G[curr.first]){
                if(e.second == curr.second) continue;
                if(e.second == RED && cost[e.first].first != -1) continue;
                if(e.second == BLUE && cost[e.first].second != -1) continue;
                if(e.second == RED) cost[e.first].first = cost[curr.first].second + 1;
                else cost[e.first].second = cost[curr.first].first + 1;
                que.push(make_pair(e.first, e.second));
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back((cost[i].first != -1 && cost[i].second != -1)? 
                          min(cost[i].first, cost[i].second): max(cost[i].first, cost[i].second));
        }
        return res;
    }
};
