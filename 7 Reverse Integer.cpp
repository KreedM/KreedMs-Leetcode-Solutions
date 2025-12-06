class Solution {
public:
    int reverse(int x) {
        int reversed = 0, digit;

        while(x) {
            digit = x % 10;

            if(reversed != 0) {
                if(reversed < 0) {
                    if(((INT_MIN - digit) / 10) > reversed)
                        return 0;
                }
                else if(((INT_MAX - digit) / 10) < reversed)
                    return 0;
            }

            reversed = 10 * reversed + digit;

            x /= 10;
        }

        return reversed;
    }
};