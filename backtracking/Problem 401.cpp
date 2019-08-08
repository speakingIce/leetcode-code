401. Binary Watch
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.
 
For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Example: 
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

有4个代表小时的bit以及6个代表分钟的bit，给出总共的bit数量，枚举所有的可能的时钟的显示情况。
将它当做十位的01字符串的枚举即可。
class Solution {
private:
    const int minBit = 6;
    const int hourBit = 4;
    const int minLim = 60;
    const int hourLim = 12;
    string intToHourNum(int hour){
        if(hour == 0) return "0";        
        string res ="";
        while(hour){
            res += hour % 10 + '0';
            hour /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string intToMinNum(int min){
        if(min == 0) return "00";
        string res ="";
        while(min){
            res += min % 10 + '0';
            min /= 10;
        }
        if(res.size() < 2)
            res += '0';
        reverse(res.begin(), res.end());
        return res;
    }
    string hourAndMinToClock(int hour, int min){
        return intToHourNum(hour) + ':' + intToMinNum(min);
    }
    void permutation(string currStr, int currPos, vector<string>& res, int totalBit){
        if(currPos == minBit + hourBit){
            int bitCnt = 0;
            int hour = 0;
            for(int i = 0; i < hourBit; i++){
                if(currStr[i] == '1')
                    hour += (int)pow(2, hourBit - 1 - i), bitCnt++;
            }
            if(hour >= hourLim) return;
            int min = 0;
            for(int i = 0; i < minBit; i++){
                if(currStr[i + hourBit] == '1')
                    min += (int)pow(2, minBit - 1 - i), bitCnt++;
            }
            if(min >= minLim) return;
            if(bitCnt == totalBit)
                res.push_back(hourAndMinToClock(hour, min));
            return;
        }
        permutation(currStr, currPos + 1, res, totalBit);
        currStr[currPos] = '1';
        permutation(currStr, currPos + 1, res, totalBit);
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> vec;
        permutation("0000000000", 0, vec, num);
        return vec;
    }
};
