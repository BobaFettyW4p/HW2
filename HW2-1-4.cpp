#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

/**
 * Calculates the square root of the sum of squares of the values in the input vector
 * 
 * @param vector<double> a vector of doubles
 * @return The square root of the sum of the squares of the values in the input vector
 */
double calculateOriginDistance(const std::vector<double>& input) {
    double sumOfSquares = std:: accumulate(
        input.begin(),
        input.end(),
        0.0,
        [](double acc, double value) {
            return acc + value * value;
        }
    );
    return std::sqrt(sumOfSquares);
}

int main() {
    // Initialize an empty vector to store user-provided elements
    // and an integer to store the total number of desired elements in the vector
    std::vector<double> input;
    int n;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements. Hit enter after entering each element:" << "\n";
    for (int i=0; i<n; i++) {
        double value;
        std::cin >> value;
        input.push_back(value);
    }

    double result = calculateOriginDistance(input);
    std::cout << "The square root of the sum of squared values is: " << result << "\n";

    return 0;
}