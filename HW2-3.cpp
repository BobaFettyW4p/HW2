#include <iostream>
#include <vector>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <string>

class PascalsTriangle {
public:
    PascalsTriangle(int height) : height(height) {}

    void generateAndPrint() {
        std::vector<std::vector<int>> triangle;

        // Generate Pascal's Triangle
        for (int i = 0; i < height; ++i) {
            triangle.push_back(generateRow(i, triangle));
        }

        // Determine field width for alignment
        int maxVal = triangle[height - 1][height / 2];
        int fieldWidth = fmt::to_string(maxVal).length() + 1;

        // Print Pascal's Triangle
        for (int i = 0; i < height; ++i) {
            printRow(triangle[i], i, fieldWidth);
        }
    }

private:
    int height;

    // Generate a row based on the previous rows
    std::vector<int> generateRow(int rowIndex, const std::vector<std::vector<int>>& triangle) {
        std::vector<int> row(rowIndex + 1, 1);

        for (int j = 1; j < rowIndex; ++j) {
            row[j] = triangle[rowIndex - 1][j - 1] + triangle[rowIndex - 1][j];
        }

        return row;
    }

    // Print a row of Pascal's Triangle
    void printRow(const std::vector<int>& row, int rowIndex, int fieldWidth) {
        int totalWidth = (height - rowIndex - 1) * fieldWidth / 2;
        std::cout << std::string(totalWidth, ' ');

        for (int val : row) {
            std::cout << fmt::format("{:>{}}", val, fieldWidth);
        }

        std::cout << "\n";
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
