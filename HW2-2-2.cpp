#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Calculates median of a given input vector
 * 
 * @param vector<double> a vector of doubles
 * @return an int that is the mathematical median of the values of the input vector
 */
double median(std::vector<double>& input) {
    int length = input.size();

    // We will now use std::partial_sort to sort the vector and find the median
    // With std::partial_sort, we only need to sort the first half of the vector as opposed to sorting the entire vector (which we did with std::sort)
    // assuming the computational overhead of the 2 methods is similar, this means std::partial_sort is more efficient for calculating the median
    std::partial_sort(input.begin(), input.begin() + length / 2 + 1, input.end());

    if ( length % 2 == 0) {
        return (input[length / 2 - 1] + input[length / 2]) / 2.0;
    }
    else {
        return input[length / 2];
    }
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

    double result = median(input);
    std::cout << "The median is: " << result << "\n";
    return 0;
}