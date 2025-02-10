// TC: O(M+N) sc: O(1)

class Solution
{
public:
    void merge(vector<int> &n1, int m, vector<int> &n2, int n)
    {
        int i = m - 1, j = n - 1;
        int k = (m + n) - 1;

        while (i >= 0 && j >= 0)
        {
            if (n1[i] > n2[j])
            {
                n1[k] = n1[i];
                i--, k--;
            }
            else
            {
                n1[k] = n2[j];
                k--, j--;
            }
        }

        // if there are extra ele in n2 push all.. but if there is extra in n1 then nothing to change they are already smaller..
        while (j >= 0)
        {
            n1[k] = n2[j];
            k--, j--;
        }
    }
};