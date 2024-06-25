class Solution {
public:

    string encode(vector<string>& strs) {
        int len = 0;
        for(const string& str : strs)
            len += numDigits(str.length()) + 1 + str.length();

        string s(len, ';');

        int index = 0;
        for(const string& str : strs) {
            len = str.length();
            do {
                s[index++] = '0' + len % 10;
                len /= 10;
            } while(len);

            ++index;

            for(const char& c : str)
                s[index++] = c;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        int len = s.length(), numChars = 0, tens = 1;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ';') {
                strs.push_back(string(numChars, ' '));

                for(int j = 0; j < numChars; ++j)
                    strs.back()[j] = s[++i];
                
                numChars = 0;
                tens = 1;
            }
            else {
                numChars += tens * (s[i] - '0');
                tens *= 10;
            }  
        }

        return strs;
    }

private:

    int numDigits(int n) {
        int digits = 0;

        do {
            ++digits;
            n /= 10;
        } while(n);

        return digits;
    }
};
