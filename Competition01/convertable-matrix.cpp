#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-10;

void GaussionElimination(vector<vector<double>> &matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int lead = 0;
  for (int r = 0; r < rows; ++r,lead++) {
    if (cols <= lead)
      break;
    
    int i = r;
    while (abs(matrix[i][lead]) < eps)
      if (rows == ++i) {
        i = r;
        if (cols == ++lead) return;
      }
    swap(matrix[i], matrix[r]);
    
    double lv = matrix[r][lead];
    for (int j = 0; j < cols; ++j)
      matrix[r][j] /= lv;
    
    for (i = 0; i < rows; ++i)
      if (i != r) {
        lv = matrix[i][lead];
        for (int j = 0; j < cols; ++j)
          matrix[i][j] -= lv * matrix[r][j];
      }
  }
}

void printMatrix(const vector<vector<double>> &matrix) {
  for (const auto &row: matrix) {
    for (double val: row)
      cout << int(val) << ' ';
    cout << endl;
  }
}

int main() {
  int rows, cols;
  cin >> rows >> cols;
  vector<vector<double>> matrix;
  matrix.resize(rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int t;
      cin >> t;
      matrix[i].push_back(t);
    }
  }
  GaussionElimination(matrix);
  printMatrix(matrix);
  return 0;
}
