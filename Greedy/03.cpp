// Problem Link : https://leetcode.com/problems/non-overlapping-intervals/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int i=0,j=1,ans=0;
        while(j<inter.size()){
            if(inter[i][1]<=inter[j][0]) i=j,j++;
            else if(inter[i][1]>inter[j][0]){
                ans++;
                if(inter[i][1]>inter[j][1]) i=j,j++;
                else j++;
            }
        }
        return ans;
    }
};
