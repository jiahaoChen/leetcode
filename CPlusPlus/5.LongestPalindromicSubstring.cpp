/*
algorithm first check the middle char, and then spread out
   left++ [start(all same char)] right++
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;

        int start = 0, right, left, maxLeft = 0, len = 1;

        while (start < n && n - start > len/2)
        {
            left = right = start;
            while(right < n-1 && s[right] == s[right+1])
                right++;
            start = right+1;
            while(left > 0 && right < n-1 && s[right+1] == s[left-1])
            {
                right++;
                left--;
            }
            if(right-left+1>len)
            {
                len = right-left+1;
                maxLeft = left;
            }
        }
        return s.substr(maxLeft, len);
    }
};

// second brush answer
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int maxLen = 0;
        int minStart = 0;
        for (int i = 0; i < n; ++i) {
            int left = i-1;
            int right = i+1;
            int len = 1;
            int start = i;
            while (i < n && s[i] == s[i+1]) {
                len++;
                right++;
                i++;
            }
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                } else {
                    start = left;
                    len+=2;
                    left--;
                    right++;
                }
            }
            if (len > maxLen) {
                maxLen = len;
                minStart = start;
            }
        }
        return s.substr(minStart, maxLen);
    }
};