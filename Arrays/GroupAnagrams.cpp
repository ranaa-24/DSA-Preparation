#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp; // will store the sorted string and corrosponding the original strings
        vector<vector<string>> ans;
        for (string s : strs)
        {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        for (auto &s : mp)
        {
            ans.push_back(s.second);
        }

        return ans;
    }
};