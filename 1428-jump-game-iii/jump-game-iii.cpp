class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>>adj (n);
        vector<bool>vis(n, false);
        for(int i=0; i<n; i++){
            if(i+arr[i] < n){
                adj[i].push_back(i+arr[i]);
            }
            if(i-arr[i] >= 0){
                adj[i].push_back(i-arr[i]);
            }
        }
        queue<int>q;
        q.push(start);
        vis[start] = true;
        while(!q.empty()){
            int nodeInd = q.front();
            q.pop();
            for(auto neigh: adj[nodeInd]){
                if(arr[neigh] == 0) return true;
                if(!vis[neigh]){
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
        }
        return false;
    }
};