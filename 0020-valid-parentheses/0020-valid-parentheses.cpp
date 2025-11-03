class Solution {
public:
    bool isValid(string s) {
        stack<char> st_brackets;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st_brackets.push(ch);
                continue;
            }

            if (!st_brackets.empty() && 
                isPairBrackets(st_brackets.top(), ch)) {
                st_brackets.pop();
            } else {
                return false;
            }
            
        }

        return st_brackets.empty();
    }

    bool isPairBrackets(char open_br, char close_br) {
        if ((open_br == '(' && close_br == ')') ||
            (open_br == '{' && close_br == '}') ||
            (open_br == '[' && close_br == ']')) {
                return true;
            }
        
        return false;
    }
};