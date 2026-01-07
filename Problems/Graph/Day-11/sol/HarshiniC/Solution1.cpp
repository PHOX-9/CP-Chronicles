/*
Problem: Kefa and Park
Kefa lives in a park represented as a tree. Some vertices have cats. Kefa wants to visit leaf nodes (restaurants) but cannot go through more than m consecutive vertices with cats. Count the number of leaf nodes Kefa can visit.

Approach:
1. Represent the tree using an adjacency list.
2. Use DFS starting from the root (vertex 1).
3. Keep track of consecutive cats along the path.
4. If consecutive cats exceed m, stop DFS on that path.
5. If a leaf node is reached and the path is valid, count it.

Time Complexity: O(n) 
Space Complexity: O(n) 

Example:
Input:
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
Output:
2
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<int> hasCat;
int n, m;
int dfs(int node, int parent, int consecutiveCats) {
    if (hasCat[node]) consecutiveCats++;
    else consecutiveCats = 0;
    if (consecutiveCats > m) return 0; 
    bool isLeaf = true;
    int count = 0;
    for (int child : adj[node]) {
        if(child != parent) {
            isLeaf = false;
            count += dfs(child, node, consecutiveCats);
       }
    }
    if (isLeaf) return 1; 
    return count;
}

int main() {
    cin >> n >> m;
    hasCat.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> hasCat[i];
    adj.resize(n + 1);
    for (int i=0;i<n - 1;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, 0, 0) << endl;
    return 0;
}
