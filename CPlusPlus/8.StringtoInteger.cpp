class Solution {
public:
    int myAtoi(string str) {
        int ret = 0, i = 0, sign = 1;
        while(str[i] == ' ') ++i;
        if (str[i] == '-' || str[i] == '+')
            sign = str[i++] == '-'?-1:1;
        
        while (str[i] >= '0' && str[i] <= '9') {
            if (ret > INT_MAX/10 || (ret == INT_MAX/10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            ret = ret*10 + (str[i++] -'0');
        }
        
        return ret*sign;
    }
};