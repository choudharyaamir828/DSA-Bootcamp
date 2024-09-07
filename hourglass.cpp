#include <iostream>
#include <vector>
using namespace std;


int findMaxHourglassSum( vector<vector<int>>& matrix) {
    int maxSum = INT_MIN; 

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows - 2; ++i) {
        for (int j = 0; j < cols - 2; ++j) {
            
            int top = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2];
            int middle = matrix[i+1][j+1];
            int bottom = matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2];

            int hourglassSum = top + middle + bottom;

            // check maximum 
            if (hourglassSum > maxSum) {
                maxSum = hourglassSum;
            }
        }
    }

    return maxSum;
}

int main() {
    // Define a 6x6 matrix
    vector<vector<int>> arr = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1}
    };

    int ans = findMaxHourglassSum(arr);

    cout << "Maximum hourglass sum: " << ans << endl;

    return 0;
}