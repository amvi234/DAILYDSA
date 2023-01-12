class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(int row,int col,vector<string>&board,int n){
        int x=row;
        int y=col;
        for(int i=0;i<=x;i++){
			if(board[i][y]=='Q') return false;
		}
        x=row;
        y=col;
        while(x>=0&&y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;y--;
        }
        x=row;
        y=col;
        while(x>=0&&y<n){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;y++;
        }
        return true;

    }
    void solve(int row,vector<string>&board,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            
                if(isSafe(row,col,board,n)){
                    board[row][col]='Q';
                    solve(row+1,board,n);
                    board[row][col]='.';
                }
    }
    }
    vector<vector<string>> solveNQueens(int n) {
    
        vector<string>board;
        string s(n,'.');
		for(int i=0;i<n;i++) board.push_back(s);
        solve(0,board,n);
        return ans;
    }
};