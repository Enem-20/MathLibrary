#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

// Функция для вывода матрицы
inline void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "Matrix:\n";
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

// Функция для создания матрицы с заданным размером и начальным значением
inline std::vector<std::vector<int>> createMatrix(int rows, int cols, int startValue = 0) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = startValue++;
        }
    }
    return matrix;
}

// Сложение двух матриц
inline std::vector<std::vector<int>> addMatrices(
    const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        throw std::invalid_argument("Матрицы должны быть одинакового размера для сложения!");
    }

    size_t rows = matrix1.size();
    size_t cols = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Вычитание двух матриц
inline std::vector<std::vector<int>> subtractMatrices(
    const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        throw std::invalid_argument("Матрицы должны быть одинакового размера для вычитания!");
    }

    size_t rows = matrix1.size();
    size_t cols = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}

// Деление двух матриц (поэлементное)
inline std::vector<std::vector<int>> divideMatrices(
    const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        throw std::invalid_argument("Матрицы должны быть одинакового размера для деления!");
    }

    size_t rows = matrix1.size();
    size_t cols = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrix2[i][j] == 0) {
                throw std::domain_error("Деление на ноль в матрице недопустимо!");
            }
            result[i][j] = matrix1[i][j] / matrix2[i][j];
        }
    }

    return result;
}

// Умножение двух матриц (матричное)
inline std::vector<std::vector<int>> multiplyMatrices(
    const std::vector<std::vector<int>>& matrix1,
    const std::vector<std::vector<int>>& matrix2) {
    if (matrix1[0].size() != matrix2.size()) {
        throw std::invalid_argument("Количество столбцов первой матрицы должно совпадать с количеством строк второй!");
    }

    size_t rows = matrix1.size();
    size_t cols = matrix2[0].size();
    size_t common = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            for (size_t k = 0; k < common; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

#endif
