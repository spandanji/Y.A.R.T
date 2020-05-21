#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

auto segmented_seive(const uint64_t &n) -> uint64_t {
    auto sqrt_n = static_cast<uint64_t>(std::sqrt(n));
    const uint64_t seive_size = std::max(sqrt_n, static_cast<uint64_t>(32768));

    std::vector<uint64_t> primes;
    std::vector<uint64_t> multiples;
    std::vector<uint_fast8_t> is_prime(sqrt_n + 1, 1);
    std::vector<uint_fast8_t> seive(seive_size);

    uint64_t sum = 2;
    uint64_t is_prime_i = 3;
    uint64_t seive_i = 3;
    uint64_t num = 3;

    for (uint64_t lower_limit = 0; lower_limit <= n; lower_limit += seive_size) {
        std::fill(seive.begin(), seive.end(), 1);
        uint64_t upper_limit = lower_limit + seive_size - 1;
        upper_limit = std::min(upper_limit, n);

        while (is_prime_i * is_prime_i <= upper_limit) {
            if (is_prime[is_prime_i] != 0u) {
                for (uint64_t j = is_prime_i * is_prime_i; j <= sqrt_n;
                        j += is_prime_i) {
                    is_prime[j] = 0;
                }
            }
            is_prime_i += 2;
        }

        while (seive_i * seive_i <= upper_limit) {
            if (is_prime[seive_i] != 0u) {
                primes.push_back(seive_i);
                multiples.push_back(seive_i * seive_i - lower_limit);
            }
            seive_i += 2;
        }

        for (uint64_t i = 0; i < primes.size(); i++) {
            uint64_t j = multiples[i];
            for (uint64_t k = primes[i] * 2; j < seive_size; j += k) {
                seive[j] = 0;
            }
            multiples[i] = j - seive_size;
        }

        for (; num <= upper_limit; num += 2) {
            if (seive[num - lower_limit] != 0u) {
                sum += num;
            }
        }
    }

    return sum;
}

auto main() -> int {
    uint64_t n = 0;
    std::cin >> n;
    auto start = std::chrono::steady_clock::now();
    auto sum = segmented_seive(n);
    auto end = std::chrono::steady_clock::now();
    std::cout << "TIME: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                start)
        .count()
        << "ms\n";
    std::cout << "SUM: " << sum << '\n';
}
