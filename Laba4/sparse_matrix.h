#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include "sparse_vector.h"

class SparseMatrix {
private:
    // �������� ������� � ������� ��������� (������, �������) -> ��������
    std::map<std::pair<int, int>, double> data;
    int rows, cols;

public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    // ��������� ��������
    void set(int row, int col, double value) {
        if (row >= rows || col >= cols || row < 0 || col < 0)
            throw std::out_of_range("������� ��� ���������");
        if (value != 0)
            data[{row, col}] = value;
        else
            data.erase({ row, col });
    }

    // ��������� ��������
    double get(int row, int col) const {
        if (row >= rows || col >= cols || row < 0 || col < 0)
            throw std::out_of_range("������� ��� ���������");
        auto it = data.find({ row, col });
        return it != data.end() ? it->second : 0.0;
    }

    // ����������������
    SparseMatrix transpose() const {
        SparseMatrix result(cols, rows);
        for (const auto& entry : data) {
            const auto& key = entry.first;
            double value = entry.second;
            result.set(key.second, key.first, value);
        }
        return result;
    }

    // �������� ������
    SparseMatrix operator+(const SparseMatrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("������� ������ �� ���������");

        SparseMatrix result(rows, cols);
        for (const auto& entry : data) {
            const auto& key = entry.first;
            double value = entry.second;
            result.set(key.first, key.second, value);
        }

        for (const auto& entry : other.data) {
            const auto& key = entry.first;
            double value = entry.second;
            result.set(key.first, key.second, result.get(key.first, key.second) + value);
        }

        return result;
    }

    // ��������� ������
    SparseMatrix operator*(const SparseMatrix& other) const {
        if (cols != other.rows)
            throw std::invalid_argument("������� ������ �� ��������� ���������");

        SparseMatrix result(rows, other.cols);

        for (const auto& entryA : data) {
            const auto& keyA = entryA.first;
            double valueA = entryA.second;
            for (int k = 0; k < other.cols; ++k) {
                double valueB = other.get(keyA.second, k);
                if (valueB != 0)
                    result.set(keyA.first, k, result.get(keyA.first, k) + valueA * valueB);
            }
        }

        return result;
    }

    // ��������� ������� �� ������
    SparseVector operator*(const SparseVector& vec) const {
        if (cols != vec.get_size())
            throw std::invalid_argument("������� ������� � ������� �� ��������� ���������");

        SparseVector result(rows);
        for (const auto& entry : data) {
            int row = entry.first.first;
            int col = entry.first.second;
            result.set(row, result.get(row) + entry.second * vec.get(col));
        }
        return result;
    }

    // ���������� � �������
    SparseMatrix pow(int exponent) const {
        if (rows != cols)
            throw std::invalid_argument("������� ������ ���� ����������");
        if (exponent < 0)
            throw std::invalid_argument("������������� ������� �� ��������������");

        SparseMatrix result(rows, cols);
        SparseMatrix base = *this;

        // ������� ��������� �������
        for (int i = 0; i < rows; ++i)
            result.set(i, i, 1);

        while (exponent) {
            if (exponent % 2 == 1)
                result = result * base;
            base = base * base;
            exponent /= 2;
        }

        return result;
    }

    // ����� �������
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif SPARSE_MATRIX_H