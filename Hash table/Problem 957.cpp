957. Prison Cells After N Days
There are 8 prison cells in a row, and each cell is either occupied or vacant.
Each day, whether the cell is occupied or vacant changes according to the following rules:
If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)
 

Example 1:
Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:
Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 
Note:
cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9
有8个相邻的cell，取值为1或者0。给出它们的初始取值，其第二天的取值总是第一天的cells[i] = not(cells[i - 1] xor cells[i + 1]), cells[0] = cells[7] = 0.
求N天后的cells的取值情况。
我们对cells的取值的变化情况进行观察：
首先，cells[0]和cells[7]的取值在第1天后都是确定的，为0；
然后，第i天的cells[1, 3, 5]的取值完全由第i-1天的cells[2, 4, 6]确定，第i天的cells[2, 4, 6]的取值完全由第i-1天的cells[1, 3, 5]确定；
所以，第i天的cells[1, 3, 5]的取值完全由第i-2天的cells[1, 3, 5]确定，第i天的cells[2, 4, 6]的取值完全由第i-2天的cells[2, 4, 6]确定；
所以，一定存在一个周期，找出该周期即可。
class Solution {
private:
    map<int, int> hashForCycle;
    int vectorToInt(vector<int> vec){
        int base = 1;
        int res = 0;
        for(int i = 0; i < 8; i++){
            res += vec[i] * base;
            base *= 2;
        }
        return res;
    }
    vector<int> intToVector(int num){
        vector<int> res(8);
        for(int i = 0; i < 8; i++){
            res[i] = num % 2;
            num /= 2;
        }
        return res;
    }
    void nextPrison(vector<int>& cells){
        queue<int> que;
        que.push(0);
        for(int i = 1; i <= 6; i++)
            que.push(!(cells[i - 1] xor cells[i + 1]));        
        que.push(0);
        for(int i = 0; i < 8; i++){ 
            cells[i] = que.front();
            que.pop();
        }
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        nextPrison(cells);
        if(N == 1) return cells;
        int cycleLen = 0;
        int h = vectorToInt(cells);
        hashForCycle[h] = 1;
        vector<int> vec;
        vec.push_back(h);
        while(true){
            cycleLen++;
            nextPrison(cells);
            h = vectorToInt(cells);
            if(hashForCycle[h]){
                break;
            }
            hashForCycle[h] = 1;
            vec.push_back(h);
        }
        return intToVector(vec[(N - 1) % cycleLen]);
    }
};
