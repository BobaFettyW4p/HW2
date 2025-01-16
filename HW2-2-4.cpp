#include <iostream>
#include <vector>
#include <algorithm>


// we are passing the value by reference instead of directly 
// since we do not need the original vector once it is passed here, this is more efficient
// if we didn't, we would create a function-scope copy of the vector to operate on instead
// if we needed the original vector for another purpose, for example if we wanted to output the user's inputted vector as well as the median, we would need to do this.
auto median(auto& input) {
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