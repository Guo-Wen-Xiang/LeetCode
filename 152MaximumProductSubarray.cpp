/*
152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

/* Solution 1: dynamic programming
Time complexity: O(n)
Space complexity: O(n)
Use two dp arrays to store data, dpMin[i] represents the minimum product of subarrays that end up with nums[i], and dpMax[i] represents
the maximum product of subarrays which end up with nums[i]. And we use another quantity ans to store the maximum product of the whole array,
due to the subarray may not end up with the end.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size(), ans = nums[0];
        vector<int> dpMin(n, 0), dpMax(n, 0);
        dpMin[0] = nums[0], dpMax[0] = nums[0];
        for(int i=1; i<n; i++){
            dpMax[i] = max(max(dpMin[i-1]*nums[i], dpMax[i-1]*nums[i]), nums[i]);
            dpMin[i] = min(min(dpMin[i-1]*nums[i], dpMax[i-1]*nums[i]), nums[i]);
            ans = max(ans, dpMax[i]);
        }
        return ans;
    }
};

/* Solution 2: dynamic programming
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int ans = nums[0], dpMin = nums[0], dpMax = nums[0];
        for(int i=1; i<nums.size(); i++){
            int temp = dpMax;
            dpMax = max(max(dpMin*nums[i], dpMax*nums[i]), nums[i]);
            dpMin = min(min(dpMin*nums[i], temp*nums[i]), nums[i]);
            ans = max(ans, dpMax);
        }
        return ans;
    }
};