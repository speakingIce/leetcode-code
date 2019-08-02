Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
 
Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
 
Example:
Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

给出一个mxn的二维矩阵，其中的每一个元素代表单元格阶梯之高度，问下雨后在阶梯形成的凹陷中能存储的最大的下雨量。
我们使用BFS来解题。在优先队列中维护一些单元格，这些单元格组成一个border；初始地，border就由mxn的矩阵边界单元格组成。
然后进行BFS的过程，每一次找出border中的height最短的那个单元格，访问其邻居，将其邻居变成新的边界。
如果某一邻居的高度比它更短，则将该邻居的高度变为和它一样，并增加总储水量。

class cell {
public:
    int x, y, h;
    cell(int _x = -1, int _y = -1, int _h = 0) {
        x = _x, y = _y, h = _h;
    }
    bool operator<(const cell& c) const{
        return this->h < c.h;
    }
    bool operator>(const cell& c) const{
        return this->h > c.h;
    }
};

class Solution {
private:
    const int MAX_VALUE = 110; // max value of m and n.
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int trapRainWater(vector<vector<int>>& heightMap) { 
        
        if(heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;
        
        priority_queue <cell, vector<cell>, greater<cell> > border;
        int m = heightMap.size(), n = heightMap[0].size();
        int visit[MAX_VALUE][MAX_VALUE];
        memset(visit, 0, sizeof visit);
        for(int i = 0; i < n; i++){
            border.push(cell(0, i, heightMap[0][i]));
            border.push(cell(m - 1, i, heightMap[m - 1][i]));
            visit[0][i] = 1;
            visit[m - 1][i] = 1;
        }
        for(int j = 1; j < m - 1; j++){
            border.push(cell(j, 0, heightMap[j][0]));
            border.push(cell(j, n - 1, heightMap[j][n - 1]));
            visit[j][0] = 1;
            visit[j][n - 1] = 1;
        }
    
        int totalAmountOfRain = 0;
        while(!border.empty()){
            cell shortestCell = border.top(); border.pop();
            int currX = shortestCell.x,
                currY = shortestCell.y,
                currh = shortestCell.h;
            for(int dir = 0; dir < 4; dir++){
                int nx = currX + dx[dir],
                    ny = currY + dy[dir];
                if(nx < 0 || ny < 0 ||
                   nx >= m || ny >= n) continue;
                if(visit[nx][ny]) continue;
                
                if(heightMap[nx][ny] < currh){
                    totalAmountOfRain += currh - heightMap[nx][ny];
                    heightMap[nx][ny] = currh;
                }
                border.push(cell(nx, ny, heightMap[nx][ny]));
                visit[nx][ny] = 1;
            }
        }
        return totalAmountOfRain; 
    }        

};
