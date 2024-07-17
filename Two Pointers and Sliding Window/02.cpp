// Problem Link : https://leetcode.com/problems/maximum-number-of-visible-points/
// Pre-requist : Basic Trigonometric knowledge to calculate arc (OR window size)
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
        int x=loc[0],y=loc[1];
        vector<double> store;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0],y1=points[i][1];
            if(x1==x && y1==y) continue;
            double rad=atan((double)((double)(y1-y)/(double)(x1-x)));
            double ang=(double)((double)rad*(double)180)/(double)(M_PI);
            if(y1>=y){
                if(x1>=x) store.push_back(ang);     // Ist Quadrant
                else store.push_back(ang+180);      // IInd Quadrant
            }
            else{
                if(x1>=x) store.push_back(ang+360);  // IIIrd Quadrant
                else store.push_back(ang+180);      // IVth Quadrant
            }
        }
        sort(store.begin(),store.end());
        double k=double(angle); // window
        int n=store.size();
        int ans=points.size()-n;
        int ind=0;
        while(ind<n && store[n-1]+k>=store[ind]+360) store.push_back(store[ind]+360),ind++; // append all starting points which lies under window from last points.
        int i=0,j=0,c=0,cur=0;
        n=store.size();
        while(j<n){
            while(j<n && store[i]+k>=store[j]) j++;
            cur=max(cur,j-i);
            i++;
        }
        return ans+cur;
    }
};
