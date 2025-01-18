#include <iostream>
#include <vector>
#include <algorithm>


// we are passing the value by reference instead of directly 
// since we do not need the original vector once it is passed here, this is more efficient
// if we didn't, we would create a function-scope copy of the vector to operate on instead
// if we needed the original vector for another purpose, for example if we wanted to output the user's inputted vector as well as the median, we would need to do this.
template <typename T>
auto median(T& input) -> typename T::value_type {
    auto length = input.size();

    std::nth_element(input.begin(), input.begin() + length / 2, input.end());

    if (length % 2 != 0) {
        return input[length / 2];
    }
    else {
        std::nth_element(input.begin(), input.begin() + length / 2 - 1, input.end());
        return (input[length / 2 - 1] + input[length / 2]) / 2.0;
    }
}

int main() {
    // Initialize an empty vector to store user-provided elements
    // and an integer to store the total number of desired elements in the vector
    std::vector<double> input;
    int n;

    std::cout << "Enter the number of elements in the vector: ";
    std::cin >> n;
    //n is set to 0, we'll get a segfault if we call the median function, this logic prevents this
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