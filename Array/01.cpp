// Problem Link : https://leetcode.com/problems/game-of-life/
vector<vector<int>> dir={{1,1},{-1,-1},{-1,1},{1,-1},{0,-1},{1,0},{0,1},{-1,0}};
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0],y=j+dir[k][1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(board[x][y]==-1 || board[x][y]==1) cnt++;
                    }
                }
                if(board[i][j]==1 && (cnt>3 || cnt<2)) board[i][j]=-1;
                if(board[i][j]==0 && cnt==3) board[i][j]=2; 
            }
        }        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=1;
                if(board[i][j]==-1) board[i][j]=0;
            }
        }
    }
};
