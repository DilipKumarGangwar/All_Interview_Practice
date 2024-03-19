#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    bool isValid(int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;
        return true;
    }

    void minPointsUtil(vector<vector<int>> points, int i, int j, int row, int col, int tempEnergy, int deficiency, int &finalAns, vector<int> rowNbr, vector<int> colNbr) {
        if (!isValid(i, j, row, col))
            return;

        tempEnergy += points[i][j];

        if (tempEnergy <= 0) {
            deficiency += abs(tempEnergy);
            tempEnergy = 0;
        }
       // cout<<"def="<<deficiency;

        if (i == row - 1 && j == col - 1) {
            finalAns = min(deficiency, finalAns);
            return;
        }

        for (int x = 0; x < 2; x++) {
            minPointsUtil(points, i + rowNbr[x], j + colNbr[x], row, col, tempEnergy, deficiency, finalAns, rowNbr, colNbr);
        }
    }

public:
    int minPoints(vector<vector<int>> points, int M, int N) {
        vector<int> rowNbr = {0, 1};
        vector<int> colNbr = {1, 0};
        int tempEnergy = 0, deficiency = 0, finalAns = INT_MAX;
        minPointsUtil(points, 0, 0, M, N, tempEnergy, deficiency, finalAns, rowNbr, colNbr);
        return finalAns + 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int M = 3, N = 3;
    cout << "Minimum points required: " << sol.minPoints(points, M, N) << endl;
    return 0;
}
