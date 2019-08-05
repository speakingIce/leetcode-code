720. Longest Word in Dictionary
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string. 
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Note: 
All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

给定一个字符串列表，找出一个其中长度最大的且字典序最小的字符串，它能够由列表中的其它字符串一个字符一个字符增加地构成。
使用Trie的数据结构，先将所有的字符串插入到Trie中，然后搜索每一个string，如果搜索中的沿路上的每一个节点都能代表一个单词则叶节点代表的单词满足“一个字符一个字符增加”的条件。
const int charTypeNum = 26;
class trieNode{
public:
    trieNode* nextTrieNode[charTypeNum];
    string word;
    trieNode(){
        word = "";
        for(int i = 0; i < charTypeNum; i++){
            nextTrieNode[i] = NULL;
        }
    }
};

class trie{
public:
    trieNode* root;
    trie(){
        root = new trieNode();
    }
    void insert(string str){
        trieNode* insertPointer = root;
        for(int i = 0; i < str.size(); i++){
            if(insertPointer->nextTrieNode[str[i] - 'a'] == NULL){
                insertPointer->nextTrieNode[str[i] - 'a'] = new trieNode();
            }
            insertPointer = insertPointer->nextTrieNode[str[i] - 'a'];
        }
        insertPointer->word = str;
    }
    int countWordsAlongTheWay(string str){
        trieNode* searchPointer = root;
        int cnt = 0;
        for(int i = 0; i < str.size(); i++){
            searchPointer = searchPointer->nextTrieNode[str[i] - 'a'];
            if(searchPointer->word.size() != 0){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        trie myTrie;
        for(int i = 0; i < words.size(); i++){
            myTrie.insert(words[i]);
        }
        int maxLen = -1;
        string ans = "";
        for(int i = 0; i < words.size(); i++){
            int currLen = words[i].size();
            if((currLen > maxLen || (currLen == maxLen && words[i] < ans)) 
               && currLen == myTrie.countWordsAlongTheWay(words[i])){
                ans = words[i];
                maxLen = currLen;
            }
        }
        return ans;
    }
    当然，我们在建完树之后，可以使用DFS，由Trie的根结点开始对整棵树进行搜索，保存最优的答案。
};
