class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size()-1, n=grid[0].size()-1;
        int layers = min(n+1,m+1)/2;
        for(int i=0; i<layers; i++){
            vector<int>v;
            for(int c=i; c<=(n-i); c++){
                v.push_back(grid[i][c]);
            }
            for(int r=i+1; r<=(m-i); r++){
                v.push_back(grid[r][n-i]);
            }
            for(int c=n-i-1; c>=i; c--){
                v.push_back(grid[m-i][c]);
            }
            for(int r=m-i-1; r>i; r--){
                v.push_back(grid[r][i]);
            }
            // for(auto itr: v){
            //     cout<<itr<<" ";
            // }
            // cout<<endl;
            int x = k % v.size();
            for(int i=0; i<x; i++){
                v.push_back(v[i]);
            }
            int j=x;
            for(int c=i; c<=(n-i); c++){
                grid[i][c] = v[j++];
            }
            for(int r=i+1; r<=(m-i); r++){
                grid[r][n-i] = v[j++];
            }
            for(int c=n-i-1; c>=i; c--){
                grid[m-i][c] = v[j++];
            }
            for(int r=m-i-1; r>i; r--){
                grid[r][i] = v[j++];
            }

        }
        return grid;
    }
};