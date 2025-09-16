class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n1 = grid.size();         
        int n2 = grid[0].size();            
        queue<pair<pair<int,int>,int>> n3;
        vector<vector<int>> test(n1, vector<int>(n2, 0));
        for(int i=0;i<n1;i++) 
            for(int j=0;j<n2;j++)
                if(grid[i][j]==2){       
                    n3.push({{i,j},0});   
                    test[i][j]=2;        
                }
        int result=0; 
        int dr[4]={-1,0,1,0}; 
        int dc[4]={0,1,0,-1};  
        while(!n3.empty()){
            auto [p,check]=n3.front(); 
            n3.pop();
            result=max(result,check);    
            for(int k=0;k<4;k++){
                int r=p.first+dr[k], c=p.second+dc[k];
                if(r>=0&&c>=0&&r<n1&&c<n2&&grid[r][c]==1&&!test[r][c]){
                    test[r][c]=2;        
                    n3.push({{r,c},check+1}); 
                }
            }
        }
        for(int i=0;i<n1;i++) 
            for(int j=0;j<n2;j++)
                if(grid[i][j]==1 && test[i][j]!=2) 
                    return -1;          

        return result; 
    }
};
