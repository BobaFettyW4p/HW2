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

    // We will now use std::nth_element to find the median
    // this arranges the vector so the element at the specified index is at its correct position.
    // I would presume this is more efficient than either the std::sort or std::partial_sort since fewer operations are spent re-arranging elements
    std::nth_element(input.begin(), input.begin() + length / 2 , input.end());
    if ( length % 2 != 0) { // if the vector has an odd number of elements, we simply need to return the middle element
        return input[length / 2];
    }
    else { // if the vector length is even, we need to place the other middle element in its correct postion, then return the average of both middle elements
        std::nth_element(input.begin(), input.begin() + length / 2, input.end());
        
        return (input[length / 2 - 1]+ input[length / 2]) / 2.0;
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