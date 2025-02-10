class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int prefixMul = 1;
            int sufixMul = 1;
            int maxi = INT_MIN;
            int n = nums.size();
    
            //TL;DR: at moment either prefix or suffix canbe the ans..
            // in all cases: even -ves (the whole pre/suffix), odd -ves, when contains 0, we should not carry the 0 mul on pre/suff
            for(int i=0; i<n; i++){
                prefixMul *= nums[i];
                sufixMul *= nums[n-i-1];
                maxi = max(maxi, max(prefixMul, sufixMul));
    
                if(!prefixMul) prefixMul = 1;
                if(!sufixMul) sufixMul = 1;
            }
    
            return maxi;
        }
    };