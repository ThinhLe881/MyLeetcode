class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.empty())
            return encodedText;

        int n = encodedText.size();
        int cols = (n + rows - 1) / rows;
        string res;

        for(int start = 0; start < cols; start++){
            int r = 0, c = start;

            while(r<rows && c<cols) {
                res += encodedText[r*cols + c];
                r++; c++;
            }
        }

        while(!res.empty() && res.back() == ' ')
            res.pop_back();
        
        return res;
    }
};