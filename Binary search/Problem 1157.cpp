1157. Online Majority Element In Subarray
Implementing the class MajorityChecker, which has the following API:
MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the given array arr;
int query(int left, int right, int threshold) has arguments such that: 
0 <= left <= right < arr.length representing a subarray of arr;
2 * threshold > right - left + 1, ie. the threshold is always a strict majority of the length of the subarray
Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right] that occurs at least threshold times, or -1 if no such element exists.
 
Example:
MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // returns 1
majorityChecker.query(0,3,3); // returns -1
majorityChecker.query(2,3,2); // returns 2
 
Constraints:
1 <= arr.length <= 20000
1 <= arr[i] <= 20000
For each query, 0 <= left <= right < len(arr)
For each query, 2 * threshold > right - left + 1
The number of queries is at most 10000
给出一个数组arr[n]，需要实现一个数据结构“MajorityChecker”，它有一个接口query(left, right, threshold)；
我们需要对这个query返回一个在arr[left-right]范围内，出现次数至少为threshold的数值。
题目为了保证这个值的唯一性，让threshold的取值足够大。
思想很简单，我们对每一个元素，存储它们所有在数组arr中出现的下标在一个下标数组中；
这样一来，对一个query，对所有可能的值，我们用二分法在下标数组中找到一个上边界和下边界，即可计算出该值的出现次数。
class MajorityChecker {
private:
    int len;
    map<int, vector<int> > numToIndeces;

public:
    MajorityChecker(vector<int>& arr) {
        len = arr.size();        
        for(int i = 0; i < len; i++){
            if(numToIndeces.find(arr[i]) == numToIndeces.end()){
                numToIndeces[arr[i]] = vector<int>();
            }    
            numToIndeces[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(auto iter = numToIndeces.begin(); iter != numToIndeces.end(); iter++){
            
            int currLen = iter->second.size();
            if(currLen < threshold) continue;
            
            int lb = 0, rb = currLen - 1;
            int leftResult, rightResult;
            bool findLeft = false, findRight = false;
            while(lb <= rb){
                leftResult = (lb + rb) >> 1;
                if(iter->second[leftResult] < left){
                    lb = leftResult + 1;
                }else{
                    if(leftResult == 0 || iter->second[leftResult - 1] < left){
                        findLeft = true;
                        break;
                    }else{
                        rb = leftResult - 1;
                    }
                }
            }
            lb = 0, rb = currLen - 1;
            while(lb <= rb){
                rightResult = (lb + rb) >> 1;
                if(iter->second[rightResult] > right){
                    rb = rightResult - 1;
                }else{
                    if(rightResult == currLen - 1 || iter->second[rightResult + 1] > right){
                        findRight = true;
                        break;
                    }else{
                        lb = rightResult + 1;
                    }
                }
            }
            if(!findLeft || !findRight) continue;
            if(rightResult - leftResult + 1 >= threshold){
                return iter->first;
            }
        }
        return -1;        
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
