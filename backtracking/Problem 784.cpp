784. Letter Case Permutation
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.

给出字符串S，枚举其中所有的大小写字母情况。
class Solution {
private:
    bool isLowercase(char c){
        return c >= 'a' && c <= 'z';
    }
    bool isUppercase(char c){
        return c >= 'A' && c <= 'Z';
    }
    void myPermutation(vector<string>& res, string currStr, int currPos, int totalLength){
        if(currPos == totalLength){
            res.push_back(currStr);
            return;
        }
        
        if(isLowercase(currStr[currPos])){
            currStr[currPos] = currStr[currPos] - 'a' + 'A';
            myPermutation(res, currStr, currPos + 1, totalLength);
            currStr[currPos] = currStr[currPos] - 'A' + 'a';
        }else if(isUppercase(currStr[currPos])){
            currStr[currPos] = currStr[currPos] - 'A' + 'a';
            myPermutation(res, currStr, currPos + 1, totalLength);
            currStr[currPos] = currStr[currPos] - 'a' + 'A';
        }
        
        myPermutation(res, currStr, currPos + 1, totalLength);
        
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> vec;
        
        myPermutation(vec, S, 0, S.size());
        
        return vec;
    }
};
