class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length(), wordLen;

        vector<bool> segmentable(len, false); segmentable[0] = true;

        bool eq;
        for(int i = 0; i < len; ++i) {
            if(!segmentable[i])
                continue;

            for(const string& word : wordDict) {
                wordLen = word.length();

                if(i + wordLen > len)
                    continue;
                
                eq = true;
                for(int j = i; j < i + wordLen; ++j) {
                    if(s[j] != word[j - i]) {
                        eq = false;
                        break;
                    }
                }

                if(eq) {
                    if(i + wordLen == len)
                        return true;
                    
                    segmentable[i + wordLen] = true;
                }
            }
        }

        return false;
    }
};