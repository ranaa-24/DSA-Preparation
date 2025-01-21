#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=6qXO72FkqwM

// Swap the last peak with a first smaller value from the end (ie, this smaller value has the lowest weightage to swap),
// when we ware came the small ele from the last that means we climbed a peak,
//  we have to reverse this peak to get the next permutaions [reverse swaIndex+1 (peak) to last] (o/w the value will be learger)

// 1. find the first decreaseing elemetnt from the last,       3, 7, 5, 2, 0    ->3
// 2. if no decreasing ele is found, all ele are in drcresing order, its the last permutation, return reversing whole array.
// 3. if ele found: swap the first decresed element (here 3) with the first larger element than 3 (here 5) --> 5, 7, 3, 2, 0
// 4. reverse all the elements after that ele index

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int swapIdx = -1;
        int n = nums.size();
        // 1. get the swap index (first smaller ele from the end)
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                swapIdx = i;
                break;
            }
        }

        // no swap ele found means.. number is decreasing [3 2 1]  => [1, 2, 3]
        if (swapIdx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. swap the smaller ele x with next greater ele than x
        for (int i = n - 1; i > swapIdx; i--)
        {
            if (nums[i] > nums[swapIdx])
            {
                swap(nums[i], nums[swapIdx]);
                break;
            }
        }

        // 3. reverse the part from swapIdx+1 to end (why? try to visualize with graph diagram)
        reverse(nums.begin() + swapIdx + 1, nums.end());
    }
};

int main() { return 0; }