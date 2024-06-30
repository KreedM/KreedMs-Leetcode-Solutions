class Solution {
public:
    bool isValid(string s) {
        stack<char> closeFirst;

        for(const char& c : s) {
            switch(c) {
                case '(': closeFirst.push(')'); break;
                case '[': closeFirst.push(']'); break;
                case '{': closeFirst.push('}'); break;
                case ')':
                case ']':
                case '}': 
                    if(closeFirst.empty() || closeFirst.top() != c)
                        return false;
                    else
                        closeFirst.pop();
            }
        }

        return closeFirst.empty();
    }
};