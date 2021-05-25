#include <bits/stdc++.h>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  vector<vector<int>> matrix(str1.size()+1, vector<int>(str2.size()+1));
  int i = 0;
  for(int row = 0; row < str1.size()+1; row++){
    for(int col = 0; col < str2.size()+1; col++){
      if(row == 0){
	matrix[row][col] = col;
	continue;
      }
      if(col == 0){
	matrix[row][col] = row;
	continue;
      }
      int up = matrix[row][col-1]+1;
      int side;
      if(str1[row-1] == str2[col-1]){
        side = matrix[row-1][col-1];
      }
      else{
	side = matrix[row-1][col-1]+1;
      }
      int down = matrix[row-1][col]+1;
      matrix[row][col] = min(up,min(side,down));
    }
  }

  
  // for(int x = 0; x < str1.size()+1; x++){
  //   for(int y = 0; y < str2.size()+1; y++){
  //     cout << matrix[x][y] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << str1.size()-1 << " " << str2.size()-1 << "\n";
  return matrix[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
