#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int>> matrix(w.size()+1, vector<int>(W+1,0));
  for (int obj = 0; obj <= w.size(); obj++)
  {
    for (int wei = 0; wei <= W; wei++)
    {
      if(obj == 0 || wei == 0){
        matrix[obj][wei] =  0;
      }
      else{
        int max = matrix[obj-1][wei];
        if(w[obj-1] <= wei){
          if (w[obj-1] > max)
          {
            max = w[obj-1];
          }
          if (w[obj-1] != wei && matrix[obj-1][wei-w[obj-1]]+w[obj-1] > max)
          {
            max = matrix[obj-1][wei-w[obj-1]]+w[obj-1];
          }
        }
        matrix[obj][wei] = max;
      }
    }
  }
  return matrix[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
