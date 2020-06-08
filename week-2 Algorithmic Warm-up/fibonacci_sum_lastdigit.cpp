#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_pisano_period_length(long long m) {
    long long F1 = 0, F2 = 1, F = F1 + F2;
    for (int i = 0; i < m * m; i++) {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1) 
        return i + 1;
    }
}

long long fibonacci_sum_fast(long long n)
{
    long long remainder = n % get_pisano_period_length(10);
    if (n <= 1)
        return n;
    if(remainder <=0){
        return 0;
    }
    else{
    long long previous = 0;
    long long current = 1;
    long long result = remainder;
    long long sum = 1;

    for (long long i = 1; i < remainder; ++i)
    {
        result = (previous + current) % 10;
        previous = current;
        current = result;
        sum +=result;
    }
    return sum % 10;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);

}
