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
    std::sort(input.begin(),input.end());
    int length = input.size();
    double median;
    if (length % 2 == 0) { // if vector length is even, calculate the average of the two middle elements
        median = (input[length/2 - 1]+ input[length / 2]) / 2.0;
    }
    else {
        median = input[length / 2]; // sets median to middle value if vector length is odd
    }
    return median;
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