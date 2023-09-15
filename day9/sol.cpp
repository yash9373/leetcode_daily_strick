class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // Define a function to calculate the Manhattan distance between two points.
        auto manhattan_distance = [](const vector<int>& p1, const vector<int>& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };

        int n = points.size();
        vector<tuple<int, int, int>> edges;  // (distance, u, v) tuples
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = manhattan_distance(points[i], points[j]);
                edges.emplace_back(distance, i, j);
            }
        }

        // Sort edges by distance
        sort(edges.begin(), edges.end());

        // Initialize disjoint-set data structure
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);  // Initialize parent to the indices

        // Helper functions for disjoint-set operations
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unionSets = [&](int x, int y) {
            int root_x = find(x);
            int root_y = find(y);
            if (root_x != root_y) {
                parent[root_x] = root_y;
            }
        };

        int min_cost = 0;
        int num_edges_added = 0;

        // Kruskal's algorithm
        for (const auto& [distance, u, v] : edges) {
            if (find(u) != find(v)) {
                unionSets(u, v);
                min_cost += distance;
                ++num_edges_added;
                if (num_edges_added == n - 1) {
                    break;  // MST is complete
                }
            }
        }

        return min_cost;
    }
};
