1171. Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.
 
(Note that in the examples below, all sequences are serializations of ListNode objects.)
Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
 
Constraints:
The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.

给出一个单链表，每个节点中存储有一个整数值。不停地进行操作，每次操作为去掉链表的一个子链表，该子链表的值之和为0。
注意到了问题和连续和相关，所以自然地想到考虑连续和的性质；
令sum[i] = arr0 + arr1 + ... + arr(i-1)
则如果发现一个数对(i, j)，使得sumi == sumj，则我们找到了一个和为0的子链表。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    map<int, ListNode*> intToNode;
    map<int, int> sumVis;
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        intToNode[1] = head;
        sumVis[head->val] = 1;
        ListNode* traversePointer = head;
        int ind = 1;
        int sum = head->val;
        
        if(sum == 0){
            head = traversePointer->next;
        }
        
        while(traversePointer->next != NULL){
            traversePointer = traversePointer->next;
            ind++;
            intToNode[ind] = traversePointer;
            sum += traversePointer->val;
            
            if(sum == 0){
                head = traversePointer->next;
                continue;
            }            
            
            if(sumVis[sum] != 0){
                intToNode[sumVis[sum]]->next = traversePointer->next;
                sumVis[sum] = ind;
            }else{
                sumVis[sum] = ind;
            }
        }
        if(sum == 0){
            head = traversePointer->next;
        }
        
        traversePointer = head;
        sum = 0;
        while(traversePointer != NULL){
            sum += traversePointer->val;
            if(sumVis[sum] != 0){
                traversePointer->next = intToNode[sumVis[sum]]->next;
            }
            traversePointer = traversePointer->next;
        }
        
        return head;
    }
};
