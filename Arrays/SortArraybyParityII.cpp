class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& nums) {
            // the lat index of the nums will always be odd index, since same number of odd n even values..
            int n = nums.size();
            int i=0, j=n-1;
            // i th pos will contain even num
            // j th pos will contain odd num
    
            while(i < n && j >= 0){
                if(nums[i]%2 == 0) i += 2;
                else if(nums[j]%2 == 1) j -= 2;
                else swap(nums[i], nums[j]);
            }
    
            return nums;
        }
    };