547. Friend Circles
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends. 
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students. 
Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

给出一个nxn的矩阵，M[i][j]==1代表i和j是直接的好朋友。求朋友圈（直接好友和间接好友）的个数。
明显可以使用并查集算法来进行解题。
class Solution {
private:
    vector<int> pre;
    vector<int> setSize;
    void init(int n){
        pre = vector<int>(n);
        setSize = vector<int>(n);
        for(int i = 0; i < n; i++) pre[i] = i, setSize[i] = 1;
    }
    int find(int curr){
        int tmpCurr = curr;
        while(curr != pre[curr]) curr = pre[curr];
        while(tmpCurr != pre[tmpCurr]){
            int tmpPre = pre[tmpCurr];
            pre[tmpCurr] = curr;
            tmpCurr = tmpPre;
        }
        return curr;
    }
    int merge(int i, int j){
        int rootI = find(i), rootJ = find(j);
        if(rootI == rootJ) return 0;
        if(setSize[rootI] < setSize[rootJ]){
            pre[rootI] = rootJ;
            setSize[rootJ] += setSize[rootI];
        }else{
            pre[rootJ] = rootI;
            setSize[rootI] += setSize[rootJ];
        }
        return 1;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        init(n);
        int numOfFriendCircle = n;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(M[i][j]) numOfFriendCircle -= merge(i, j);
        
        return numOfFriendCircle;    
    }
};
