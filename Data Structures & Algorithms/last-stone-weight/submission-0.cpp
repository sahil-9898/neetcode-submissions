class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 2,3,6,2,4
        // 6,3,2,2,4
        priority_queue<int> pq;
        for (int i: stones) {
            pq.push(i);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x) {
                pq.push(y-x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
