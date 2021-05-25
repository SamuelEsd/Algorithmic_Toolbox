#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while (n >= 1) {
//     sequence.push_back(n);
//     if (n % 3 == 0) {
//       n /= 3;
//     } else if (n % 2 == 0) {
//       n /= 2;
//     } else {
//       n = n - 1;
//     }
//   }
//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }

vector<int> get_sequence(vector<int> &values){
  int i = values.size()-1;
  vector<int> sequence;
  while(values[i] != 0){
    
    if ((i+1)%3 == 0){
      if(values[((i+1)/3)-1] == values[i]-1){
	sequence.push_back(i+1);
	i = ((i+1)/3)-1;
	continue;
      }
    }

    if ((i+1)%2 == 0){
      if(values[((i+1)/2)-1] == values[i]-1){
	sequence.push_back(i+1);
	i = ((i+1)/2)-1;
	continue;
      }
    }
    
    if(i-1 >= 0){
      if(values[i-1] == values[i]-1){
	sequence.push_back(i+1);
	i -= 1;
	continue;
      }
    }
  }
  sequence.push_back(1);
  std::reverse(sequence.begin(),sequence.end());
  return sequence;
}

vector<int> optimal_sequence(int n){
  int num = 1;
  vector<int> values(n,1000001);
  values[0] = 0;
  for(int i = 0; i < n; i++){
    if(values[i] == -1){
      continue;
    }
    if(i+1 < n){
      values[i+1] = (values[i+1] > values[i]+1)? values[i]+1 : values[i+1];
    }
    int j = ((i+1)*2)-1;
    if (j < n){
      values[j] = (values[j] > values[i]+1)? values[i]+1 : values[j];
    }
    j = ((i+1)*3)-1;
    if (j < n){
      values[j] = (values[j] > values[i]+1)? values[i]+1 : values[j];
    }
  }
  return get_sequence(values);
  // return values;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() -1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  // std::cout << sequence[n-1];
  std::cout << "\n";
}

// int main() {
//   int n = 1;
//   while(n < 1000){
//     std::cout << "N = " << n << "\n";
//     vector<int> sequence = optimal_sequence(n);
//     std::cout << sequence.size() -1 << std::endl;
//     for (size_t i = 0; i < sequence.size(); ++i) {
//       std::cout << sequence[i] << " ";
//     }
//     // std::cout << sequence[n-1];
//     std::cout << "\n\n";
//     n++;
//   }
// }
