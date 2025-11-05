class Solution {
public:
    // Step 1: Build LPS (Longest Prefix Suffix) array
    void compute_LPS(string pattern, vector<int>& lps) {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while (i < pattern.size()) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Step 2: Find all occurrences using KMP
    vector<int> KMP(string &text, string &pattern) {
        vector<int> ans;
        if (pattern.empty()) return ans;

        int n = text.length();
        int m = pattern.length();
        vector<int> lps(m, 0);
        compute_LPS(pattern, lps);

        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j); // Match found
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return ans;
    }

    // Step 3: Return first match index
    int strStr(string haystack, string needle) {
        vector<int> matches = KMP(haystack, needle);
        if (matches.empty()) return -1;
        return matches[0];
    }
};