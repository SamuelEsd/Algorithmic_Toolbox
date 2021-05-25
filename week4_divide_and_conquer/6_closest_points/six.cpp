#include <bits/stdc++.h>

using std::vector;
using std::cin;
using std::cout;

double distance(vector<double> a, vector<double> b){
  double square_sum = pow(a[0]-b[0],2)+pow(a[1]-b[1],2);
  return sqrt(square_sum);
}

int main(){
  long n;
  cin >> n;

  vector<vector<double>> points;
  points.resize(n);

  for(int i = 0; i < n; i++){
    double x,y;
    cin >> x >> y;
    points[i] = {x,y};
  }
  
  sort(points.begin(),points.end(), [](vector<double> a, vector<double> b){
      return a[0] < b[0];
    });

  for(auto p : points){
    cout << p[0] << " " << p[1] << "\n";
  }
    
  
  return 0;
}
