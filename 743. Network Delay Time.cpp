/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
*/

class Solution {
public:
    vector<int> dijkstraAlgo(vector<vector<pair<int,int>>>& adj, int v, int src){
        vector<int> dis(v, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if(d > dis[node]) continue;

            for(auto& e : adj[node]){
                int adjNode = e.first;
                int adjD = e.second;
                if(dis[node] + adjD < dis[adjNode]){
                    dis[adjNode] = dis[node] + adjD;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& it : times){
            int i = it[0]-1; int j = it[1]-1; int dis = it[2];
            adj[i].push_back({j, dis});
        }

        vector<int> distance = dijkstraAlgo(adj, n, k-1);
        
        int ans = 0;
        for(int dis : distance){
            if(dis == INT_MAX) return -1;
            ans = max(ans, dis);
        }
        return ans;
    }
};