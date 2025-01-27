#include <iostream>
#include "Matrix.hpp"

int main() {
    // Создание двух матриц 3x3
    auto matrix1 = createMatrix(3, 3, 1);  // Матрица: 1 2 3; 4 5 6; 7 8 9
    auto matrix2 = createMatrix(3, 3, 10); // Матрица: 10 11 12; 13 14 15; 16 17 18

    // Сложение
    std::cout << "Addition:\n";
    printMatrix(addMatrices(matrix1, matrix2));

    // Вычитание
    std::cout << "\nSubtraction:\n";
    printMatrix(subtractMatrices(matrix1, matrix2));

    // Поэлементное деление
    try {
        std::cout << "\nDivision:\n";
        printMatrix(divideMatrices(matrix2, matrix1));
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    // Матричное умножение
    std::cout << "\nMultiplication:\n";
    printMatrix(multiplyMatrices(matrix1, matrix2));

    return 0;
}
