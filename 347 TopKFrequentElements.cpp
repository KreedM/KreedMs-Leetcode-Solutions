class Solution {
public:
    struct CompSecond {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurences;
        for(const int& num : nums)
            ++occurences[num];

        priority_queue<pair<int, int>, vector<pair<int, int>>, CompSecond> heap;
        for(const pair<int, int>& occurence : occurences) {
            heap.push(occurence);
            
            if(heap.size() > k)
                heap.pop();
        }

        vector<int> mostFrequent; mostFrequent.reserve(k);
        while(!heap.empty()) {
            mostFrequent.push_back(heap.top().first);
            
            heap.pop();
        }

        return mostFrequent;
    }
};