// Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1323543054/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0,n=s.length();
        for(char ch='A';ch<='Z';ch++){
            int len=0,c=k,i=0,j=0;
            while(j<n){
                while(j<n && s[j]!=ch && c>0) j++,c--;
                while(j<n && s[j]==ch) j++;
                if(c==0){
                    len=max(len,j-i);
                    while(i<j && s[i]==ch) i++;
                    c++;
                    i++; 
                }
            }
            len=max(len,j-i);
            // cout<<ch<<" "<<len<<endl;
            ans=max(ans,len);
        }
        return ans;
    }
};
