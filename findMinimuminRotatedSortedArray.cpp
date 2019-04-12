/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1

Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if(nums[low]<=nums[high])
            return nums[low];
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            if(nums[mid]<nums[mid-1])
                return nums[mid];
            if(nums[mid]<nums[high]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};
/*class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        for(int n:nums)
            ans = min(n, ans);
        return ans;
    }
};*/
