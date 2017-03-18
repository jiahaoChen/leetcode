class Solution {
public:
    string addBinary(string a, string b) {
        int an = a.size();
        int bn = b.size();
        int carry = 0;
        string ret = "";
        int maxn = an > bn? an: bn;
        for (int i = 1; i <= maxn || carry; ++i)
        {
            int count = 0;
            if (i <= bn && b[bn-i] == '1')  count++;
            if (i <= an && a[an-i] == '1')  count++;
            if (carry) count++;
            string append = count%2 == 1? "1":"0";
            carry = count>=2? 1:0;
            ret = append+ret;
        }
        return ret;
    }
};