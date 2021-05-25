#include <algorithm>
#include <iostream>
#include <vector>
//#include <pair>
#include <iomanip>
#include <utility>

using std::vector;
using std::pair;

double get_optimal_value(long long capacity, vector<long long> weights, vector<long long> values) {
  double value = 0.0;    
  vector<pair<double,double>> density_objects;
  for (int i = 0; i < weights.size(); i++){
    pair<double, double> density= std::make_pair((double)values[i]/(double)weights[i],i);
    density_objects.push_back(density);
  }

  std::sort(density_objects.begin(),density_objects.end());
  std::reverse(density_objects.begin(),density_objects.end());
  double capacity_available = capacity;

  for (int i = 0; i < density_objects.size() && capacity_available > 0; i++){
    if(weights[density_objects[i].second] <= capacity_available){
      value += values[density_objects[i].second];
      capacity_available -= weights[density_objects[i].second];
    }
    else{
      value += (capacity_available*values[density_objects[i].second])/weights[density_objects[i].second];
      capacity_available -= capacity_available;
    }
  }
  // write your code here

  return value;
}

int main() {
  long long n;
  long long capacity;
  std::cin >> n >> capacity;
  vector<long long> values(n);
  vector<long long> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(15);
  std::cout << optimal_value << std::endl;
  return 0;
}
