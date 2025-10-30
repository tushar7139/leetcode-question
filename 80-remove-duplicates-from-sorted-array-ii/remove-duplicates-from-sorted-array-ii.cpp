class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0, j = 1, c = 1;
        while(j<nums.size()) {
            if(nums[i] == nums[j]){
                if(c==1){
                    i++;
                    nums[i]=nums[j];
                    c++;
                }
            }
            else{
                i++;
                nums[i] = nums[j];
                c=1;
            }
            j++;
        }
        return i+1;
    }
};