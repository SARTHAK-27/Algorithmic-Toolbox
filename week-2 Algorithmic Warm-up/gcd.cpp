#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int euclid_gcd(int a, int b) {
    int divisor = a >= b ? a : b;
    int dividend = a <= b ? a : b;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << euclid_gcd(a, b) << std::endl;
  return 0;
}
