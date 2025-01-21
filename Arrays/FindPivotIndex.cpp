// known as equilibrium index
#include <bits/stdc++.h>
class Solution {
public:
    // curr ith idx of pre is the left sum and, (totSum - pre[i] - nums[i]) gives the right sum
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = 0;     // first elements pre sum is always 0
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int totSum = pre[n-1] + nums[n-1];      // note: last ele of pre stores the sum till that ele, so adding the last element we get total sum
        for(int i=0; i<n; i++){
            int leftSum = pre[i];
            int rightSum = totSum - pre[i] - nums[i];

            if(leftSum == rightSum) return i;
        }

        return -1;
    }
};

int main(){return 0;}