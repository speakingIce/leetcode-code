382. Linked List Random Node
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? 
Example: 
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

给出一个单链表的头结点head，返回一个随机节点的值，这个链表可能非常大。
使用水塘抽样算法即可解决该问题。
从左到右地扫描，设当前扫描了n个元素，则我们以1/n的概率保留第n个元素，(1-n)/n的概率保留之前的元素，则最终所有的元素被保留的概率都是相同的。
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
    ListNode* node;
    int randomValue;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand((unsigned)time(NULL));
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int randomValue;
        
        int scanedSize = 0;
        
        ListNode* tmpNode = node;
        
        while(tmpNode != NULL){
            ++scanedSize;
            int randInt = rand() % scanedSize;
            if(randInt < 1){
                randomValue = tmpNode->val;
            }
            tmpNode = tmpNode->next;
        }
        
        return randomValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
