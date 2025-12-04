class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool odd = (nums1.size() + nums2.size()) % 2 == 1;

        int half = (nums1.size() + nums2.size() + 1) / 2;

        if(odd) {
            if(nums1.size() == 0)
                return nums2[half - 1];
            else if(nums2.size() == 0)
                return nums1[half - 1];
        }
        else {
            if(nums1.size() == 0)
                return (nums2[half - 1] + nums2[half]) / 2.0;
            else if(nums2.size() == 0)
                return (nums1[half - 1] + nums1[half]) / 2.0;
        }

        int l = 0, r = nums1.size() - 1, mid, other;
        while(l <= r) {
            cout << l << " " << r << endl;
            mid = (r + l) / 2;

            other = half - (mid + 1) - 1;

            if(other < -1)
                r = mid - 1;
            else if(other >= (int)nums2.size())
                l = mid + 1;
            else {
                int left1 = nums1[mid];
                int right1 = ((mid + 1) == nums1.size()) ? (1e6 + 1) : nums1[mid + 1];
                int left2 = (other == -1) ? (-1e6 - 1) : nums2[other];
                int right2 = ((other + 1) == nums2.size()) ? (1e6 + 1) : nums2[other + 1];

                if(left1 > right2)
                    r = mid - 1;
                else if(left2 > right1)
                    l = mid + 1;
                else {
                    if(odd)
                        return max(left1, left2);
                    else
                        return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
        }

        if(odd)
            return nums2[half - 1];
        else {
            if(half < nums2.size())
                return (nums2[half - 1] + min(nums2[half], nums1[0])) / 2.0;
            else
                return (nums2[half - 1] + nums1[0]) / 2.0;
        }
    }
};