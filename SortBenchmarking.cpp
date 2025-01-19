#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// Function 1: Sort the entire array and find the median
double medianSort(std::vector<double>& input) {
    std::sort(input.begin(), input.end());
    int length = input.size();
    double median;
    if (length % 2 == 0) { // If vector length is even
        median = (input[length / 2 - 1] + input[length / 2]) / 2.0;
    } else {
        median = input[length / 2]; // Middle value if odd
    }
    return median;
}

// Function 2: Use partial_sort to find the median
double medianPartial(std::vector<double>& input) {
    int length = input.size();
    std::partial_sort(input.begin(), input.begin() + length / 2 + 1, input.end());
    if (length % 2 == 0) {
        return (input[length / 2 - 1] + input[length / 2]) / 2.0;
    } else {
        return input[length / 2];
    }
}

// Benchmark template
template <typename Func>
double benchmark(Func func, std::vector<double> input, int iterations = 100) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        std::vector<double> temp = input; // Copy input to avoid modifying the original data
        func(temp);
    }

    auto end = high_resolution_clock::now();
    return duration<double, std::milli>(end - start).count() / iterations;
}

int main() {
    // Generate random data
    const int dataSize = 10000; // Size of the input vector
    std::vector<double> data(dataSize);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1000.0);

    for (auto& val : data) {
        val = dis(gen);
    }

    int iterations = 100; // Number of iterations for the benchmark

    // Benchmark medianSort
    double timeSort = benchmark(medianSort, data, iterations);
    std::cout << "medianSort Average Time: " << timeSort << " ms\n";

    // Benchmark medianPartial
    double timePartial = benchmark(medianPartial, data, iterations);
    std::cout << "medianPartial Average Time: " << timePartial << " ms\n";

    return 0;
}
