#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cout;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    return 0;
  }
}

vector<string> removeSpaces(const string &s){
  vector<string> result;
  int i = 0;
  string temp = "";
  while(i < s.size()){
    if(s[i] == ' '){
      result.push_back(temp);
      temp = "";
    }
    else{
      temp += s[i];
    }
    i++;
  }
  return result;
}

// 5-8+7*4-8+9
long long get_maximum_value(const string &exp) {
  vector<string> ops;
  vector<long long> nums;
  for(int i = 0; i < exp.size(); i++){
    if(i%2 == 0){
      nums.push_back(stoll(exp.substr(i,1)));
    }
    else{
      ops.push_back(exp.substr(i,1));
    }
  }
  int n = nums.size();
  vector<vector<long long>> max_matrix(n,vector<long long>(n,0));
  vector<vector<long long>> min_matrix(n,vector<long long>(n,0));

  for (int i = 0; i < n; i++)
  {
    max_matrix[i][i] = nums[i];
    min_matrix[i][i] = nums[i];
  }

  for(int k = n-2; k > -1; k--){
    for (int i = 0; i <= k; i++)
    {
      int j = i+((n-1)-k);
      //cout << "(" << i << "," << j << ") ";
      long long max_temp = LONG_LONG_MIN;
      long long min_temp = LONG_LONG_MAX;
      for(int l = i; l < j; l++){
        long long a = eval(max_matrix[i][l],max_matrix[l+1][j],ops[l][0]);
        long long b = eval(max_matrix[i][l],min_matrix[l+1][j],ops[l][0]);
        long long c = eval(min_matrix[i][l],max_matrix[l+1][j],ops[l][0]);
        long long d = eval(min_matrix[i][l],min_matrix[l+1][j],ops[l][0]);

        max_temp = max(max_temp,max(a,max(b,max(c,d))));
        min_temp = min(min_temp,min(a,min(b,min(c,d))));
      }
      max_matrix[i][j] = max_temp;
      min_matrix[i][j] = min_temp;
    }
    
  }

  return max_matrix[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
