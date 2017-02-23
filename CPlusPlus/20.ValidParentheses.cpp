class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        map<char, char> hit = {{'(',')'}, {'[',']'}, {'{','}'}};
        for (char& x : s)
        {
            if (stack.empty())
            {
                stack.push_back(x);
            }
            else
            {   
                if (hit[stack.back()] == x)
                {
                    stack.pop_back();
                }
                else
                {
                    stack.push_back(x);
                }
                    
            }
        }
        if (stack.empty())
            return true;
        else 
            return false;
    }
};