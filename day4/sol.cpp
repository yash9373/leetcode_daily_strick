#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        // Initialize a vector of vectors to store the result
        std::vector<std::vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++) {
            // Resize the current row to have 'i + 1' elements
            result[i].resize(i + 1);

            // The first and last elements of each row are always 1
            result[i][0] = result[i][i] = 1;

            for (int j = 1; j < i; j++) {
                // Calculate the middle elements by summing the elements from the previous row
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        return result;
    }
};
