#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // calculate total sum
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        int leftSum = 0; // maintain sum of left elements
        // single pass
        for (int i = 0; i < nums.size(); ++i) {
            // key: right sum can be found by
            // right = total - left - current
            int rightSum = totalSum - leftSum - nums[i];
            // found, return leftmost pivot
            if (leftSum == rightSum) return i;
            leftSum += nums[i]; // otherwise add current to left sum
        }
        return -1; // as per problem
    }
};