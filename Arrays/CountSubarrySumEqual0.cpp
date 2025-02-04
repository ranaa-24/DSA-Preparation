class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> mp; //<presum, idx>
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLen = i + 1;
                continue;
            }

            if (mp.count(sum))
            { // if same sum found prev. then for that idx till i is sum 0
                maxLen = max(maxLen, i - mp[sum]);
            }
            else
            {
                mp[sum] = i; // will not update the map if already there is a entry
            }
        }

        return maxLen;
    }
};