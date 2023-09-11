class Solution {
public:
 
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> groups;
    vector<vector<int>> result;

    for (int i = 0; i < groupSizes.size(); ++i) {
        int size = groupSizes[i];

        if (groups.find(size) == groups.end()) {
            groups[size] = {i};  // Initialize a new group
        } else {
            groups[size].push_back(i);  // Add the person to the existing group
        }

        if (groups[size].size() == size) {
            result.push_back(groups[size]);
            groups.erase(size);  // Remove the group from the map
        }
    }

    return result;
}
};