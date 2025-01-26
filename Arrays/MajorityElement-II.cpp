#include <bits/stdc++.h>
using namespace std;

// minimum count of a ele should be floor(n/3) + 1     // if n = 11, ele should appear 3 + 1 = 4times
// and max number of element with (n/3)+1 freq in size n will be 2.  [4+4] + 4 (if one more ele with 4 freq added the size of the arr also increases)

class Solution
{
public:
    // TC: O(n) SC: O(N)
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        int minFreq = (int)n / 3 + 1;
        for (int &n : nums)
        {
            mp[n]++;
            if (mp[n] == minFreq)
                ans.push_back(n);
            if (ans.size() == 2)
                break;
        }

        return ans;
    }
};

// substituing moore's voting algo same way as in MajorityElement-I

class Solution
{
public:
    // TC: O(n) SC: O(1)
    vector<int> majorityElement(vector<int> &nums)
    {
        int eleCount1 = 0, ele1 = NULL, eleCount2 = 0, ele2 = NULL;
        int n = nums.size();
        // NOTE: the are all if-else-if, order is imp.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                eleCount1++; // increase and moveon, ie, we wont allow ele2 to hold the same ele if its eleCount2 is 0.
            else if (nums[i] == ele2)
                eleCount2++;
            else if (eleCount1 == 0)
            {
                ele1 = nums[i];
                eleCount1 = 1;
            }
            else if (eleCount2 == 0)
            {
                ele2 = nums[i];
                eleCount2 = 1;
            }
            else
            {
                eleCount1--;
                eleCount2--;
            }
        }

        // we've got the elemets which over leads.. but not sure if these ele satisfy >n/3 frq.
        vector<int> ans;
        int minFreq = n / 3 + 1;
        eleCount1 = eleCount2 = 0;
        for (int &n : nums)
        {
            if (n == ele1)
                eleCount1++;
            else if (n == ele2)
                eleCount2++;
        }

        if (eleCount1 >= minFreq)
            ans.push_back(ele1);
        if (eleCount2 >= minFreq)
            ans.push_back(ele2);

        return ans;
    }
};
