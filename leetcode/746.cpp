/*
Min Cost Climbing Stairs

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
indexed).

Once you pay the cost, you can either climb one or two steps. You need to find
minimum cost to reach the top of the floor, and you can either start from the
step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
cost[3]. Note: cost will have a length in the range [2, 1000]. Every cost[i]
will be an integer in the range [0, 999].
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len == 2) return 0;

        int pre1 = 0, pre2 = 0;
        for (int i = 2; i <= len; i++){
            auto tmp = pre1;
            pre1 =min(cost[i - 1] + pre1, cost[i - 2] + pre2);
            pre2 = tmp;
        }
        return pre1;
    }
};