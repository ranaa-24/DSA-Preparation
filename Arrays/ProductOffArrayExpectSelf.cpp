#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    { // for each i (N) will does N-1 iterations =  TC : O(N^2)
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = 0;
            int currProd = 1;
            while (j < i)
            {
                currProd *= nums[j];
                j++;
            }
            j = i + 1;
            while (j < nums.size())
                currProd *= nums[j++];

            ans.push_back(currProd);
        }

        return ans;
    }
};

// O(N) solution
class Solution
{
    // calculate the prod of whole array and divide the current ele; that will remove that ele from total; Special Cases : 0s
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1;
        int countZero = 0; // if more that 1 that whole ans arr will be 0, if we are in 0 than
        // other will make tha prod as 0

        for (int n : nums)
        {
            if (n != 0)
                prod *= n;
            else
                countZero++;
        }

        if (countZero > 1)
            return vector<int>(nums.size(), 0);

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (countZero)
            {                                     // if there is 0 in the vect.
                ans[i] = nums[i] == 0 ? prod : 0; // if curr i is 0 than the whole prod is ans
                // if not than this 0 will make others prod 0
            }
            else
            { // if there is no 0 than we hv to calculat the ans for each
                ans[i] = prod / nums[i];
            }
        }

        return ans;
    }
};

int main() { return 0; }


// prefix and postfix prod
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // pre will store the prod till i (0 to i-1), ans post will store the prod n-1 till i+1
        // 1[2 3 4]1  = pre = [1, 2, 6]  = post = [12 , 6, 1]
            //indicating: prefix of first ele is 1, second ele 2, [pre of 4 is 6(3*2)];
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = 1; //0th ele prefix is 1
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] * nums[i-1]; // curr pre is curr pre * pre ele
        }

        post[n-1] = 1;
        for(int i = n-2; i>= 0; i--){
            post[i] = post[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++){
            ans[i] = pre[i] * post[i];  // each i in pre and post contain its previos and next prod
        }

        return ans;
    }
};