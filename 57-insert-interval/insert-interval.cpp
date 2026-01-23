class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();

        vector<vector<int>> result;

        while(i<n){
            if(intervals[i][1] < newInterval[0]){ // add non overlapping intervals
                 result.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){ // new interval will come before interval and we just need to store the new interval
                break;
            }
            else{ // merge and iterate
                newInterval[0] = min(intervals[i][0] , newInterval[0]);
                newInterval[1] = max(intervals[i][1] , newInterval[1]);                
            }
            i++;
        }

        result.push_back(newInterval); //  i is at the new interval position

        //push elements after the new interval
        while(i<n){
               result.push_back(intervals[i]);
               i++;
        }
        return result;
    }
};