class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // sort based on the first time span
        sort(intervals.begin(), intervals.end());
        vector<int> currMergedInterval = intervals[0];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= currMergedInterval[1])
            { // overlapped
                // marge
                if (currMergedInterval[1] < intervals[i][1])
                    currMergedInterval[1] = intervals[i][1];
            }
            else
            { // non overlapping
                ans.push_back(currMergedInterval);
                currMergedInterval = intervals[i];
            }
        }
        // we r updating the ans when interval inst overlapping.. but what if all elements are overlapping / the last element was over lapping? we must push the last margedInterval..
        ans.push_back(currMergedInterval);
        return ans;
    }
};

// same logic other way..

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // sort based on the first time span
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            // create a new interval when there these is no interval or a new non ovrlapping interval found
            if (ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            { // when overLapping, update the second time span
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};