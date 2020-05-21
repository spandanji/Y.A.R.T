#include <chrono>
#include <iostream>
#include <vector>

auto main() -> int {
    unsigned int n = 0;
    std::cin >> n;
    auto start = std::chrono::steady_clock::now();
    std::vector<uint8_t> primes(n + 1, 1);
    primes[1] = 0;
    for (unsigned int i = 2; i * i <= n; i++) {
        if (primes[i] != 0u) {
            unsigned int j = i * i;
            while (j <= n) {
                primes[j] = 0;
                j += i;
            }
        }
    }
    unsigned long sum = 0;
    for (unsigned int i = 1; i <= n; i++) {
        if (primes[i] != 0u) {
            sum += i;
        }
    }
    std::cout << "Time: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start)
        .count()
        << "ms\n";
    std::cout << "Sum: " << sum << '\n';
}
