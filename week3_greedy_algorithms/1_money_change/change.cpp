#include <iostream>

int get_change(int m) {
  int remainder = m;
  int coins = 0;
  if(m >= 10){
    coins += remainder/10;
    remainder = remainder % 10;
  }

  if(m >= 5){
    coins += remainder/5;
    remainder = remainder % 5;
  }

  if(m >= 1){
    coins += remainder/1;
    remainder = remainder % 1;
  }
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
