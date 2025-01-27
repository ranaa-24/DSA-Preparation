#include <bits/stdc++.h>
using namespace std;

// slidig window wont work here, coz nums can have negative numbers, we could nwver know when to shrink the window

class Solution
{ // TC: O(N) SC: O(N)
public:
    // preFix sum till i is X, then inorder to be a K in X, we need to chop of some elements with preSum (X-K) in X;
    // map should contain (0, 1) coz for some subarray that is eqaul to k, we remove only 0
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp; //<preSum, count>
        int preSum = 0;
        mp[0]++;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            preSum += nums[i];          // prefix sum till current idx
            int toChopOff = preSum - k; // to be a K in the preSum till now we need cutOut preSum-k
            if (mp.find(toChopOff) != mp.end())
                count += mp[toChopOff];
            mp[preSum]++; // update the preSum count till curr Indx
        }
        return count;
    }
};