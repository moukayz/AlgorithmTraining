/*
Rotate Array

Given an array, rotate the array to the right by k steps, where k is
non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways
to solve this problem. Could you do it in-place with O(1) extra space?
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    unsigned gcd(unsigned u, unsigned v) {
        while (v != 0) {
            unsigned r = u % v;
            u = v;
            v = r;
        }
        return u;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        int step = gcd(n, k);
        for (int i = 0; i < step; i++) {
            auto pre = nums[i];
            int j = i;
            for (; j != (i + k) % n; j = (n - k + j) % n) {
                nums[j] = nums[(n - k + j) % n];
            }
            nums[j] = pre;
        }
    }

    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6};
    Solution().rotate2(nums, 2);
    for_each(nums.begin(), nums.end(), [](const int x) { cout << x << " "; });
    cout << "\n";
}