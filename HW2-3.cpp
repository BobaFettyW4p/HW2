#include <iostream>
#include <vector>
#define FMT_HEADER_ONLY
#include<fmt/format.h>
#include <string>

// this initializes my class PascalsTriangle
// I think this is a big improvement on my original program because it increases readability
// the additional of a public method generateAndPrint improves readability and maintains functionality of my original classless version
// The addition of two private methods generateRow and printRow are helper methods for the public generateAndPrint function and improve readability
// Creating a PascalsTriangle class also makes the script more extendable in the event we wanted to further manipulate our Pascals Triangle after creating it (for example, if we wanted to square all the values and then print the triangle)
class PascalsTriangle {
public:
    PascalsTriangle(int height) : height(height) {}

    void generateAndPrint() {
        std::vector<int> prevRow;

        for (int i = 0; i < height; ++i) {
            std::vector<int> currentRow = generateRow(prevRow);
            printRow(currentRow, i);
            prevRow = currentRow;
        }
    }

private:
    int height;

    std::vector<int> generateRow(const std::vector<int>& prevRow) {
        std::vector<int> row;
        row.push_back(1);

        for (size_t i = 1; i < prevRow.size(); ++i) {
            row.push_back(prevRow[i - 1] + prevRow[i]);
        }

        if (!prevRow.empty()) {
            row.push_back(1);
        }

        return row;
    }

    void printRow(const std::vector<int>& row, int rowIndex) {
        int totalWidth = 4 * height;
        std::string rowString;

        for (int val : row) {
            rowString += fmt::format("{:3} ", val);
        }

        int padding = (totalWidth - rowString.size()) / 2;
        std::cout << std::string(padding, ' ') << rowString << "\n";
    }
};

int main() {
    int height;
    std::cout << "Enter the height of Pascal's Triangle: ";
    std::cin >> height;

    PascalsTriangle triangle(height);
    triangle.generateAndPrint();

    return 0;
}
