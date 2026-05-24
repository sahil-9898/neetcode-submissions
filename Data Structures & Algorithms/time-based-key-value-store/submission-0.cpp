class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> arr = mp[key];
        string res = "";
        int start = 0;
        int end = arr.size() - 1;;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            pair<string, int> entry = arr[mid];
            if (entry.second == timestamp) {
                return entry.first;
            }
            if (entry.second > timestamp) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
                res = entry.first;
            }
        }
        return res;
    }
};
