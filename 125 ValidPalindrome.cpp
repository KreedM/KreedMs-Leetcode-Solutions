class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length(), left = 0, right = len - 1;

        while(left < right) {
            if(!isalnum(s[left])) {
                ++left; 
                continue;
            }

            if(!isalnum(s[right])) {
                --right;
                continue;
            }

            if(tolower(s[left++]) != tolower(s[right--]))
                return false;
        }

        return true;
    }
};