/*
Majority Element

Given an array of size n, find the majority element. The majority element is the
element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist
in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int> &nums) {
        int count = 0, len = nums.size(), target = 0;

        for (int i = 1; i < len; i++) {
            if (count == 0) target = nums[i];
            if (target == nums[i])
                count++;
            else
                count--;
        }
    }
};