#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define ll long long

ll get_change_aux(ll m, std::vector<ll> &data){
  if(data[m] != -1){
    std::cout << "data " << data[m] << "\n m " << m << "\n";
    return data[m];
  }
  else{
    std::vector<int> nums = {2};//{253,27,214,340,158,92,52,126,466,431,95};
    ll min = 3000000000;
    for (auto i :  nums){
      if (i <= m){ 
	min = std::min(min, 1+ get_change_aux(m-i,data));
      }
    }
    data[m] = min;
    return min;
  }
}

ll get_change(ll m, std::vector<int> &nums) {
  std::vector<ll> data(m+1,-1);
  data[0] = 0;
  
  ll result = get_change_aux(m,data);
  if (result == 3000000000){
    return -1;
  }
  return result;
}

int main() {
  int m;
  std::cin >> m;
  std::vector<int> nums = {1,3,4};
  std::cout << get_change(m,nums) << '\n';
}
