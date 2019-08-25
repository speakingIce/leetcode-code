1139. Largest 1-Bordered Square

Medium

57

20

Favorite

Share
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
 
Example 1:
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:
Input: grid = [[1,1,0,0]]
Output: 1
 
Constraints:
1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1

给定一张方格纸，其中每一个单元格为1或者0，求最大的一个square，该square的边缘都是1。
这道题可以使用DP的思想，对每一个方格，记录该方格左边一共有连续多少个位1的方格（包括它自己），以及上边一共有多少连续的方格（包括它自己）；

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int> > left(n, vector<int>(m, 0)), up(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            int consec = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    consec++;
                    left[i][j]  = consec;
                }else{
                    consec = 0;
                }
            }
        }
        for(int j = 0; j < m; j++){
            int consec = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1){
                    consec++;
                    up[i][j] = consec;
                }else{
                    consec = 0;
                }
            }
        }
        int maxSize = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int currMaxPossible = min(left[i][j], up[i][j]);
                if(currMaxPossible <= maxSize) continue;
                for(int k = currMaxPossible; k >= maxSize + 1; k--){
                    if(left[i - (k - 1)][j] >= k && 
                       up[i][j - (k - 1)] >= k){
                        maxSize = k;
                        break;
                    }
                }
            }
        }
        return maxSize * maxSize;
    }
};
