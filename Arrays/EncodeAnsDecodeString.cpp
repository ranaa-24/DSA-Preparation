#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //<len>#<string>... will take the length of each string and append in the begining.. so that we can extract the string later
    string encode(vector<string> &strs)
    {
        string cypher = "";

        for (string &str : strs)
        {
            int len = str.length();
            cypher += to_string(len) + "#" + str;
        }

        return cypher;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        int i = 0;
        while (i < s.length())
        {
            int j = i;

            while (s[j] != '#')
                j++; // note ' ' is imp. cant comp.a char(s[j]) with as ""(string)

            // we got the dilim (j is pointing on the dilim)
            // get the len, which is present i to j-1
            int len = stoi(s.substr(i, j - i));

            // now extract the actual string (j+1 to len size)
            i = j + 1;
            ans.push_back(s.substr(i, len));
            i = i + len;
        }

        return ans;
    }
};

int main()
{
    //
    return 0;
}
