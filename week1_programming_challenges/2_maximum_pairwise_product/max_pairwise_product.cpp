#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    long long max1 = 0;
    long long max2 = 0;
    for (int first = 0; first < n; ++first) {
      if(numbers[max1] < numbers[first]){
	max1 = first;
      }
    }
    if (max1 == 0){
      max2 = 1;
    }
    for (int second = 0; second < n; ++second) {
      if(second != max1 && numbers[max2] < numbers[second]){
	max2 = second;
      }
    }


    return numbers[max1]*numbers[max2];
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
