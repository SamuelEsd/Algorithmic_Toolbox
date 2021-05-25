#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  int mid;
  while(left <= right){

    mid = floor(((right-left)/2))+left;
    if(a[mid] == x){
      return mid;
    }
    else{
      if(a[mid] > x){
	right = mid-1;
      }
      else{
	left = mid+1;
      }
    }
  }
  return -1;
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }


  // for (int i = 0; i < m; ++i) {
  //   //replace with the call to binary_search when implemented
  //   std::cout << linear_search(a, b[i]) << ' ';
  // }

  // std::cout << "\n";
  
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }



  /// pruebas
  // srand( (unsigned)time(NULL) );
  // while(true){
  
  //   vector<int> entrada(rand() % 100);
  //   for(int i = 0; i < entrada.size(); i++){
  //     entrada[i] = rand() % 100 +1 ;
  //   }

  //   sort(entrada.begin(),entrada.end());
  //   entrada.erase( unique( entrada.begin(), entrada.end() ), entrada.end() );

  
  //   for (auto i : entrada){
  //     std::cout << i << " ";
  //   }

  
  //   vector<int> are_in(rand() % 100);
  //   for(int i = 0; i < are_in.size(); i++){
  //     are_in[i] = rand() % 100 +1 ;
  //   }

  //   std::cout << "\n";
  //   for (auto i : are_in){
  //     std::cout << i << " ";
  //   }
  

  //   std::cout << "\n";
  //   vector<int> linear(0); 
  //   for (int i = 0; i < are_in.size(); ++i) {
  //     linear.push_back(linear_search(entrada, are_in[i]));
  //     //replace with the call to binary_search when implemented
  //     std::cout << linear[i] << " ";
  //   }
  //   std::cout << "\n";

  //   vector<int> binary(0); 
  //   for (int i = 0; i < are_in.size(); ++i) {
  //     //replace with the call to binary_search when implemented
  //     binary.push_back(binary_search(entrada, are_in[i]));
  //     std::cout << binary[i] << ' ';
  //   }
    
  //   std::cout << "\n";
  //   if (linear != binary){
  //     return 0;
  //   }
  // }  

}
