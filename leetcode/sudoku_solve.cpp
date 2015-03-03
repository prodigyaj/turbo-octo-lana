class Solution {
public:
    bool row[10][10];
    bool col[10][10];
    bool box[3][3][10];
    bool mem[10][10];
    char b[10][10];
    bool done = false;
    bool check(int r,int c,int val)
    {
    	//Hashed Checking, for rows and columns instead of iterative
        if(row[r][val]==false && col[c][val]==false && box[(r/3)][c/3][val]==false)
            return true;
        return false;
    }
    
    void set (int r,int c,int val,bool set_val)
    {
        row[r][val]=set_val;
        col[c][val]=set_val;
        box[r/3][c/3][val]=set_val;
    }
    
    void solve(int cur)
    {
        if(cur==81)
        {
            done = true;
            return;
        }
        
        int x = cur%9;
        int y = cur/9;
        if(mem[x][y]==false)
            solve(cur+1);
        else
        {
            for(int i=1;i<=9;i++)
            {
                if(check(x,y,i)==true)
                {
                    set(x,y,i,true);
                    b[x][y] = i+48;
                    solve(cur+1);
                    set(x,y,i,false);
                    if(done == true)break;
                }
            }
        }
        
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        memset(&row,0,sizeof(row));
        memset(&col,0,sizeof(col));
        memset(&box,0,sizeof(box));
        memset(&mem,0,sizeof(mem));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                if(board[i][j] == '.')
                {
                    mem[i][j] = true;
                    b[i][j] = board[i][j];
                }
                else
                {
                    row[i][board[i][j]-48]=true;
                    col[j][board[i][j]-48]=true;
                    box[i/3][j/3][board[i][j]-48]=true;
                    b[i][j] = board[i][j];
                }
        solve(0);
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                board[i][j] = b[i][j];
    }
};