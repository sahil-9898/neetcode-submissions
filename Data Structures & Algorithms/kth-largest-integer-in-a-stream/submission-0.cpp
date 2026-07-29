class KthLargest {
private:
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto x: nums) {
            pq.push(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp(pq);
        for (int i=0;i<k-1;i++) {
            temp.pop();
        }
        return temp.top();
    }
};
// 3,3,2,1
// 3,3,3,2,1 ->
// 5,3,3,3,2,1 -> 
