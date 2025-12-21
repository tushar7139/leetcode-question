class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, k = 0;
        string len;

        while (j <= chars.size()) {
            if (j == chars.size() || chars[j] != chars[i]) {
                chars[k++] = chars[i];

                if ((j - i) > 1) {
                    len = to_string(j - i);
                    for (char c : len) {
                        chars[k++] = c;
                    }
                }
                i = j;
            }
            j++;
        }
        return k;
    }
};