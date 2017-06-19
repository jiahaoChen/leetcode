class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        int j = 0;
        int wordBegin = 0;
        int n = s.size();
        while (true) {
            while(i < n && s[i] == ' ') i++;
            if (i >= n) break;
            if(j) s[j++] = ' ';
            wordBegin = j;
            //move to the head
            while(i < n && s[i] != ' ') s[j++] = s[i++];
            reverse(s, wordBegin, j-1);
        }
        s.resize(j);
        reverse(s, 0, j-1);
    }

    void reverse(string& s, int begin, int end) {
        while(begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
};