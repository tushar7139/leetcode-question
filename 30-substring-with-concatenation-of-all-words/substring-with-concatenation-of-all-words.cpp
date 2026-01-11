class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int wordlen=words[0].size();
        int m=words.size();
        int totallen=m*wordlen;   // n also fine 
        vector<int>ans;
        if(m==0){
            return ans;
        }
        unordered_map<string,int>need;
        for(auto x:words){
            need[x]++;

        }

        for(int offset=0;offset<wordlen;offset++){
            unordered_map<string,int>window;
             int count=0;
             int left=offset;

             for(int right=offset;right+wordlen<=n;right+=wordlen){
                string word=s.substr(right,wordlen);

                if(need.count(word)){
                    window[word]++;
                    count++;
                
                //shrink1 
                while(window[word]>need[word]){
                    string leftword=s.substr(left,wordlen);
                    window[leftword]--;
                    left+=wordlen;
                    count--;

                }
                if(count==m){
                    ans.push_back(left);
                }
            }
             else{
                window.clear();
                count=0;
                left=right+wordlen;
             }
            }
        }
        return ans;
        
    }
};