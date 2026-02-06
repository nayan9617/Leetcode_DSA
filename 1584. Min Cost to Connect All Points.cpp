/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/

class Solution {
public:
    int minCostSpanningTree(int n, vector<vector<pair<int, int>>> &adj){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(n, 0);
        pq.push({0, 0}); //{weight, node}

        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(vis[node]) continue;
            sum += wt;
            vis[node] = 1;
            for(auto &edge : adj[node]){
                int adjNode = edge.first;
                int adjWt = edge.second;

                if(!vis[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int wt = abs(points[i][0] - points[j][0]) 
                        + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        return minCostSpanningTree(n, adj);
    }
};