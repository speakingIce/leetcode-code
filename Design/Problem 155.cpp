155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

设计一个“最小栈”。除了有push、pop、top操作之外，这个栈还能够返回栈中元素的最小值。
我使用单链表来进行实现。
结点有val成员表示元素值，next成员表示下一个结点的地址。
head是头指针，当只有head指针的时候，列表为空。
push时，在head处进行插入；pop时，在head处进行删除（删除的时候仅仅需要将head向前移动一个结点即可）。
为了返回列表中的最小值，我们可以暴力搜索单链表，但是这样做比较耗时。
取而代之，我们在结点中增加成员变量minSoFar，代表从当前结点开始到列表的末尾处，结点元素的最小值。
这样我们在O(1)的时间内即可得到列表的最小值。
class node{
public:
    int val;
    int minSoFar;
    node* next;
    node(){
        next = NULL;
    }
};

class MinStack {
private:
    node* head;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        head = new node();
    }
    
    void push(int x) {
        node* newNode = new node();
        newNode->val = x;
        newNode->next = head->next;
        newNode->minSoFar = (head->next == NULL)? x: min(head->next->minSoFar, x);
        head->next = newNode;
    }
    
    void pop() {
        node* tmp = head;
        head = head->next;
        delete tmp;
    }
    
    int top() {
        return head->next->val;
    }
    
    int getMin() {
        return head->next->minSoFar;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
