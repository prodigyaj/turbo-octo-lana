class Solution {
public:
    int minPathSum(vector<vector<int> > &g) {
        
        int x = g.size()-1,y=g[0].size()-1;
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[i].size();j++)
            {
                int temp=0;
                
                if(i-1>=0)temp = g[i-1][j];
                if(j-1>=0)
                {
                    if(temp == 0)
                        temp = g[i][j-1];
                    else
                        temp = min(temp,g[i][j-1]);
                }
                g[i][j] = g[i][j] + temp;
            }
            
            return g[x][y];
        
        
    }
};
