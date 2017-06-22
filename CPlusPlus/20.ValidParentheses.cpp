class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        vector<char> stack;
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
                case '}':
                    if (!stack.empty() && stack.back() == '{')
                        stack.pop_back();
                    else
                        return false;
                break;
                case ']':
                    if (!stack.empty() && stack.back() == '[')
                        stack.pop_back();
                    else
                        return false;
                break;
                case ')':
                    if (!stack.empty() && stack.back() == '(')
                        stack.pop_back();
                    else
                        return false;
                break;
                default:
                    stack.push_back(s[i]);
                break;
            }
        }
        if (stack.empty()) return true;
        else return false;
    }
};