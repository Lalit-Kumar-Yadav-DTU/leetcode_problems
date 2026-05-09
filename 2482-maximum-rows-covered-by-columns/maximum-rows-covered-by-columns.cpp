class Solution {
    
    int row,col;

    void CountOneS(vector<vector<int>>& matrix,vector<int> &rowCount){

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++)if(matrix[r][c]==1)rowCount[r]++;
        }
    }
    int solve(int c,int numSelect,vector<int> &rowCount,vector<vector<int>>& matrix){

        if(c==col || numSelect==0){
            int covered=0;
            for(auto i:rowCount)if(i==0)covered++;
            return covered;
        }

        int notTake=solve(c+1,numSelect,rowCount,matrix);

        int take=0;
        vector<int> affectedRows;
        for(int r=0;r<row;r++){
            if(matrix[r][c]==1 && rowCount[r]>0){
                rowCount[r]--;
                affectedRows.push_back(r);
            }
        }
        take=solve(c+1,numSelect-1,rowCount,matrix);
        for(auto r:affectedRows)rowCount[r]++;

        return max(notTake,take);

    }
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        row=matrix.size();
        col=matrix[0].size();

        //counting total of 1s
        vector<int> rowCount(row,0);
        CountOneS(matrix,rowCount);

        return solve(0,numSelect,rowCount,matrix);
    }
};