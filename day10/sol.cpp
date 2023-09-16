class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Define directions for moving (up, down, left, right)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Create a vector to store the minimum efforts required to reach each cell
        vector<vector<int>> minEfforts(rows, vector<int>(cols, INT_MAX));
        
        // Create a min heap (priority queue) to explore cells with the smallest effort first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        minEfforts[0][0] = 0;
        
        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            
            int x = cell.first;
            int y = cell.second;
            
            if (x == rows - 1 && y == cols - 1) {
                return effort;
            }
            
            for (const auto& dir : directions) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;
                
                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[new_x][new_y]));
                    
                    if (new_effort < minEfforts[new_x][new_y]) {
                        minEfforts[new_x][new_y] = new_effort;
                        pq.push({new_effort, {new_x, new_y}});
                    }
                }
            }
        }
        
        return -1; // This should not happen if there is a valid path
    }
};