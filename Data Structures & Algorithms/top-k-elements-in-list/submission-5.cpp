class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n: nums) {
            mp[n]++;
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (pair<const int, int> &entry:mp) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> res;
        for (int i=0; i<k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
