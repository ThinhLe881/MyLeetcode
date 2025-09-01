class Solution {
public:
    bool isPalindrome(string s) {
        if (s == " ") {
            return true;
        }

        size_t pL = 0, pR = s.size()-1;
        bool fl_skip = false;

        while (pL < pR) {
            fl_skip = false;

            if (!isalnum(s[pL])) {
                pL++;
                fl_skip = true;
            }
            if (!isalnum(s[pR])) {
                pR--;
                fl_skip = true;
            }
            if (fl_skip) {
                continue;
            }
            if (tolower(s[pL]) != tolower(s[pR])) {
                return false;
            }

            pL++;
            pR--;
        }

        return true;
    }
};