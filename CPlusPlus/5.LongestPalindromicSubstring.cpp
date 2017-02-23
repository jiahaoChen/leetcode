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