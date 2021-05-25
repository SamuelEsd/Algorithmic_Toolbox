#include <iostream>
#include <vector>

using std::vector;

long long get_number_merge(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  int ave = left + (right - left) / 2;
  int inversions = 0;
  int count = left;
  int i = left;
  int j = ave+1;
  // alguno de los dos es menor que su límite
  while(i <= ave || j <= right){
    // si j ya llegó a su límite
    // o si aún no llega pero i tampoco e i es menor o igual a j 
    if(j > right || (i <= ave && a[i] <= a[j])){
      b[count++] = a[i++];
      continue;
    }
    // si i ya llegó a su límite
    // o si aún no llega pero j tampoco y j es menor estricto que i
    if(i > ave || (j <= right && a[j] < a[i])){
      if(i <= ave){
	      inversions += (ave+1)-i;
      }
      b[count++] = a[j++];
    }
  }
  count = left;
  while(count <= right){
    a[count] = b[count];
    count++;
  }
  return inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right < left + 1) return number_of_inversions;
  int ave = left + (right - left) / 2;
  //  std::cout << "ave: " << ave << "\n";
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  return get_number_merge(a,b,left,right) + number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
  // std::cout << "a: ";
  // for (auto i : a) {
  //   std::cout << i << " ";
  // }
  // std::cout <<  "\nb: ";
  // for (auto i : b) {
  //   std::cout << i << " ";
  // }  
  // std::cout << "\n";
}
