class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> groups;
        vector<int> result;
        for (int c : nums) {
            groups[c]++;
    }
        int size = nums.size();
        vector<vector<int>> buckets(size+1);
        for (auto& pair : groups) {
            buckets[pair.second].push_back(pair.first);
        }
for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
    for (int num : buckets[i]) {
        result.push_back(num);
        if (result.size() == k) break;
    }
}
    return result;
    }
};


