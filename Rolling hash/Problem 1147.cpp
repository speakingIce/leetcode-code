1147. Longest Chunked Palindrome Decomposition
Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:
Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.
 
Example 1:
Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".
Example 2:
Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".
Example 3:
Input: text = "antaprezatepzapreanta"
Output: 11
Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)".
Example 4:
Input: text = "aaa"
Output: 3
Explanation: We can split the string on "(a)(a)(a)".
 
Constraints:
text consists only of lowercase English characters.
1 <= text.length <= 1000

整块回文串。
从两侧同时向中间进行扫描。两侧的字符串每增加一个新字符则做一次比较；
但是这样一来时间复杂度就是O(n^2)
为了对算法进行优化，我们可以加入两个小技巧：
1. 字符串哈希
我们在扫描的过程中不断计算两侧的字符串的字符串哈希值，如果字符串的哈希值不相等则根本不需要进行比较
2. 两侧字符串的首位和末尾的比较
如果两端的字符串相同，则它们的首部和尾部必须分别相同；反之，如果首部或者尾部不完全相同，则两字符串一定不同
在进行比较之前进行上述的两个判断，可以节省很多时间。

class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.size();
        int ll = 0, lr = 0, rl = len - 1, rr = len - 1;
        int ans = 0;
        unsigned long long h1 = 0, h2 = 0, w = 1;
        while(rl > lr){
            h1 = h1 * 131ULL + text[lr];
            h2 = text[rl] * w + h2;
            char lln = text[ll], lrn = text[lr];
            char rln = text[rl], rrn = text[rr];
            w *= 131ULL;
            if(h1 == h2 && lln == rln && lrn == rrn){
                bool isMatch = true;
                for(int i = 1; i < lr - ll; i++){
                    if(text[ll + i] != text[rl + i]){
                        isMatch = false;
                        break;
                    }
                }
                if(isMatch){
                    ans += 2;
                    ll = lr = lr + 1;
                    rr = rl = rl - 1;
                    h1 = 0, h2 = 0, w = 1;
                    continue;
                }
            }
            rl--, lr++;
        }
        if(ll == rr || (lr - ll + 1 > 0 && ll < rr)){
            ans++;
        }
        return ans;
    }
};
