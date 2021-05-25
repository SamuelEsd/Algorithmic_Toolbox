#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  int actual = 0;
  int max = -1;
  int count = 0;
  int refils = 0;
  while(actual+tank < dist or count < stops.size()){
    int distancia_prox_gas = stops[count]-actual;
    if(distancia_prox_gas <= tank){
      max = count;
    }
    else{
      if(max != -1){
        actual = stops[max];
	refils += 1;
	max = -1;
	count -= 1;
      }
      else{
	return max;
      }
    }
    count += 1;
  }
  if (actual+tank < dist ){
    return -1;
  }
  // write your code here
  return refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    stops.push_back(d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
