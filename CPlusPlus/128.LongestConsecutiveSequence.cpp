class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> record(nums.begin(),nums.end());
        int res = 1;
        for (int i : nums) {
            if (record.find(i) == record.end()) continue;
            record.erase(i);
            int prev = i - 1;
            int next = i + 1;
            while(record.find(prev) != record.end()) record.erase(prev--);
            while(record.find(next) != record.end()) record.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};