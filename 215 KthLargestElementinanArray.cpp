class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            // priority_queue<int, vector<int>, greater<int>> minHeap;
    
            // for(int i = 0; i < k; ++i)
            //     minHeap.push(nums[i]);
            
            // for(int i = k; i < nums.size(); ++i) {
            //     minHeap.push(nums[i]);
            //     minHeap.pop();
            // }
    
            // return minHeap.top();
    
            // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    
            // return nums[k - 1];
    
            nth_element(nums.begin(), nums.begin() + nums.size() - k, nums.end());
    
            return nums[nums.size() - k];
        }
    };