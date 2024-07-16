// Problem Link : https://leetcode.com/problems/gas-station/description/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,tank=0,route=0;
        for(int i=0;i<gas.size();i++){
            tank+=gas[i]-cost[i];
            route+=gas[i]-cost[i];
            if(tank<0) tank=0,start=i+1;
        }
        return (route<0)?-1:start;
    }
};
