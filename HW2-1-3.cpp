#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>

/**
 * Calculates the square root of the sum of squared values of a vector using std::inner_product
 * 
 * @param vector<double> user-inputted vector of doubles
 * @return the square root of the sum of the square values of the input vector
 */
double calculateSquareRootOfSum(const std::vector<double>& input) {
    double sumOfSquares = std::inner_product(input.begin(), input.end(), input.begin(), 0.0);
    return std::sqrt(sumOfSquares);
}

int main() {
    // Initialize an empty vector to store user-prompted elements
    // and an int to store the total number of desired elements in the vector
    std::vector<double> input;
    int n;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements. Hit enter after entering each element:\n";
    for(int i=0; i < n; i++) {
        double value;
        std::cin >> value;
        input.push_back(value);
    }

    double result = calculateSquareRootOfSum(input);
    std::cout << "The square root of the sum of squared values is: " << result << "\n";

    return 0;
}