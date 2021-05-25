#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;

bool isPartitionable(vector<bool> used, vector<int> values, vector<int> partitions, int completed, int index){
  int partitionSize = used.size() / partitions.size()+1;
  if(partitions[completed] == partitionSize){
    completed++;
    if(completed == partitions.size()){
      return true;
    }
    return isPartitionable(used, values,partitions,completed,index);
  }
  int temp = partitions[completed] + values[index];
  if(temp > partitionSize){
    return false;
  }
  for (int i = index; i >= 0; i--){
    if (used[i]){
      continue;
    }
    used[index] = true;
    if(isPartitionable(used, values,partitions,completed,index-1)){
      return true;
    }
    used[index = false];
  }
  
}

int partition3(vector<int> &A) {
  int sum = 0;
  if(A.size()%3 != 0 || A.size() < 3){
    return 0;
  }
  for(int i = 0; i < A.size(); i++){
    sum += A[i];
  }
  if(sum%3 != 0){
    return 0;
  }
  vector<int> partitions(3-1,0);
  vector<bool> used(false,A.size());

  int completed = 0;
  while(completed != 3-1){
    
    partitions[]
  }

  sort(A.begin(),A.end());

  if(A[A.size()-1] > sum/3){
    return 0;
  }
  


  //write your code here
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
