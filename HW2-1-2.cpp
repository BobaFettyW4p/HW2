#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>


/**
 * utilizes std::transform to double all values in a given input vector
 * 
 * @param vector<double> a vector of doubles
 * @return a vector<double> of equal length to the input vector, but with all values doubled
 */
std::vector<double> squareValues(const std::vector<double>& input) {
    std::vector<double> result(input.size());
    std::transform(input.begin(), input.end(), result.begin(), [](double x) {
        return x * x;
    });
    
    return result;
}

/**
 * Calculates the square root of the sum of values of the inputted vector
 * 
 * @param vector<double> this vector is originally modified by the squareValues function
 * @return returns an int that is the square root of the sum of the values of the input vector
 */
double calculateSquareRootOfSum(const std::vector<double>& squaredValues) {
    double sumOfSquares = std::accumulate(squaredValues.begin(), squaredValues.end(), 0.0);
    return std::sqrt(sumOfSquares);
}


int main() {
    //initialize an empty vector to store user-prompted elements
    //and an int to store the total number of desired elements in the vector
    std::vector<double> input;
    int n;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements. Hit enter after entering each element:" << "\n";
    for (int i = 0; i < n; ++i) {
        double value;
        std::cin >> value;
        input.push_back(value);
    }

    std::vector<double> squaredValues = squareValues(input);

    double result = calculateSquareRootOfSum(squaredValues);

    std::cout << "The square root of the sum of squared values is: " << result << "\n";

    return 0;
}
