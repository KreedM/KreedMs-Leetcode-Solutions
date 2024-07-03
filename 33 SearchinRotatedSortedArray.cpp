class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;

        while(end > start) {
            mid = (start + end) / 2;

            if(target == nums[mid])
                return mid;
            
            if(nums[mid] < nums[end]) {
                if(target > nums[end] || target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else {
                if(target > nums[mid] || target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return target == nums[start] ? start : -1;
    }
};