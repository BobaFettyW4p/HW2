#include <iostream>
#include <vector>
#include <algorithm>


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

    std::cout << "Squared values: ";
    for (double value : squaredValues) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    return 0;
}
