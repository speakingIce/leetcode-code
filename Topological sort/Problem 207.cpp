207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Example 1:
Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        
        vector<vector<int> > adjacentArray(numCourses);
        
        int len = prerequisites.size();
        
        for(int i = 0; i < len; i++){
            inDegree[prerequisites[i][1]]++;
            adjacentArray[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        stack<int> zeroDegreeVertices;
        int remainingVertices = numCourses;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                zeroDegreeVertices.push(i);
            }
        }
        
        while(!zeroDegreeVertices.empty()){
            int curr = zeroDegreeVertices.top();
            zeroDegreeVertices.pop();
            remainingVertices--;
            for(int i = 0; i < adjacentArray[curr].size(); i++){
                int j = adjacentArray[curr][i];
                inDegree[j]--;
                if(inDegree[j] == 0) 
                    zeroDegreeVertices.push(j);
            }
        }
        return remainingVertices == 0;
    }
};
