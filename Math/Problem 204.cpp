204. Count Primes
Count the number of prime numbers less than a non-negative number, n.
Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
使用筛法。
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for(int i = 2; i * i < n; i++){
            if(!isPrime[i]) continue;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++)if(isPrime[i])
            count++;
        return count;
    }
};
