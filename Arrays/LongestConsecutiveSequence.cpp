#include <bits/stdc++.h>
using namespace std;

class Solution
{ // O(NlogN)
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.empty() ? 0 : 1;
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int consecutiveEle = 1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1] - 1)
                consecutiveEle++;
            else if (nums[i] == nums[i + 1])
                continue; // only considering how many unique consiquitive ele are there [0 1 1 2] = 3
            else
                consecutiveEle = 1;
            maxi = max(maxi, consecutiveEle);
        }

        return maxi;
    }
};

class Solution
{
public:
    // by checking size of each sequence staring with some x
    // for a ele x, if there exixt a (x-1) that means its not the starting of the seq..
    // if not then its a starting of seq, and will further check if (X+1) exist and will grow the size as long x++ exists..
    // TC: O(N+N) = O(N) each ele will visited atmost twice (1 for that ele 2nd for starting to this ele)
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st;
        for (auto i : nums)
        {
            st.insert(i);
        }
        int maxSeqSize = 0;
        for (int x : st)
        { // * traverse the set only to get rid of duplicates
            if (st.count(x - 1))
                continue;
            else
            { // x-1 doest exist so, its the starting of the seq and check how further we can grow with this x
                int seqSize = 1;
                int curr = x;
                while (st.count(curr + seqSize))
                { // x+1 exisits, grow!!
                    seqSize++;
                }
                maxSeqSize = max(maxSeqSize, seqSize);
            }
        }

        return maxSeqSize;
    }
};

int main() { return 0; }