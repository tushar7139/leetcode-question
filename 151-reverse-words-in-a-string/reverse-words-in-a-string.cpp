class Solution {
public:
    string reverseWords(string s) {
     int n = s.length();
     string ans="";
     reverse(s.begin(),s.end());
     string word="";
     for(int i=0;i <n; i++)
        {
            if (s[i] != ' ') {
                word = s[i] + word;
            } else if (word.length() > 0) {
                if (ans.length() > 0) ans+=" ";
                ans +=  word;
                word = "";
            }
        }

         // Add the last word if there's any left after the loop
        if (word.length() > 0) {
            if (ans.length() > 0) ans += " ";
            ans += word;
        }

         return ans;
     }
    
    };


