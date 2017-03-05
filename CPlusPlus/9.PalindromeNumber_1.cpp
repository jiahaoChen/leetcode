class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x && !(x%10))) return false;
        
        int reveNum = 0;
        while(x>reveNum)
        {
            reveNum = reveNum*10+x%10;
            x = x/10;
        }
        return (x==reveNum) || (x==reveNum/10);
    }
};