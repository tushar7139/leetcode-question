class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool pos = true;
        string ans;
        bool is = false;
        
        for(int i = 0; i < n; i++) {
            // Skip leading whitespace
            if(s[i] == ' ' && !is) continue;

            // Handle Sign
            if((s[i] == '-' || s[i] == '+') && !is) {
                pos = (s[i] == '+');
                i++;
                
                // Skip leading zeros after sign
                while(i < n && s[i] == '0') {
                    i++;
                }
                i--;
                is = true;
                continue;
            }
            
            // Handle cases with no sign but leading zeros
            if(!is) {
                while(i < n && s[i] == '0') {
                    i++;
                }
                i--;
                is = true;
                continue;
            }

            // Collect digits
            if(s[i] >= '0' && s[i] <= '9') {
                is = true;
                ans += s[i];
            } else {
                break;
            }
        }

        int m = ans.length();
        if(m == 0) return 0;
        
        // Quick check for length-based overflow
        if(ans.length() > 10) return pos ? INT_MAX : INT_MIN;

        long long a = 0;
        int i = m - 1;
        
        // Convert string to long long
        while(i >= 0) {
            long double k = pow(10, m - i - 1);
            a += (long long)k * (ans[i] - '0');
            i--;
        }
      
        // Clamp to Integer Limits
        if(pos && a >= INT_MAX) return INT_MAX;
        if(!pos && (-a) <= INT_MIN) return INT_MIN;

        return pos ? (int)a : (int)-a;
    }
};