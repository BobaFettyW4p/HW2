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
    // To determine which is faster, I created a quick benchmarking program (please see SortBenchmarking.cpp)
    // Sample output from my benchmarking program indicated that using std::sort was considerably faster
    // While std::partial_sort has a faster theoretical runtime, its operations have a higher computational overhead associated with them
    // Thus, while std::partial_sort is re-arranging fewer elements, it will take longer to re-arrange compared to std::sort, especially for our median function, which must re-arrange half of all the elements to perform the needed operations
    // If we needed to isolate a much smaller subset (say, if our vector was one million elements in length, and we only needed the first 10 sorted elements), at that point, std::partial_sort could become faster
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
    // error handling to ensure the function is not called when n is set to 0
    if (n != 0) {
    std::cout << "Enter " << n << " elements. Hit enter after entering each element:" << "\n";
    for (int i=0; i<n; i++) {
        double value;
        std::cin >> value;
        input.push_back(value);
    }

    double result = median(input);
    std::cout << "The median is: " << result << "\n";
    }
    //error handling if user tries to set a vector size of 0
    else {
        std::cout << "No elements in the vector to calculate the median.";
    }
    return 0;
}