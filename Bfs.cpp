#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

void add_edge (vector<vector<int>>& adj, int origin, int destiny){
    adj[origin].push_back(destiny);
}

vector<int> BFS(vector<vector<int>>& adj, int starting_v){
    int v = adj.size();
    vector<bool> visited(v, false);
    vector<int> res;
    queue<int> q;
    visited[starting_v] = true;

    q.push(starting_v);

    while(!q.empty()){

        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    
    return res;
}

int main(){
    
    int qtt_vertex = 4;
    vector<vector<int>> adj;
    vector<int> bfs = BFS(adj, 0);
    return 0;
}
