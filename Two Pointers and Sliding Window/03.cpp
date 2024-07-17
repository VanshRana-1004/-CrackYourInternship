// Problem Link : https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            // Incrementing mid as well low because all the 2's before current were already shifted to the end or high index therefore the current will be either 1 or 0 that's why we can also increment mid
            if(nums[mid]==0) swap(nums[mid],nums[low]),low++,mid++; 
            else if(nums[mid]==1) mid++;
            else swap(nums[mid],nums[high]),high--;
        }
    }
};
