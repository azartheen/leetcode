/*
Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int c,g,sz;
        c=g=nums[0];
        sz=nums.size()-1;
        // kadane's algorithm
        for(int i=1;i<=sz;i++){
            c=max(nums[i],c+nums[i]);
            if(c>g) g=c;
        }
        return g;
    }
};