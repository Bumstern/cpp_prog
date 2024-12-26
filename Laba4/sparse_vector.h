#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>


class SparseVector {
private:
    std::map<int, double> data;
    int size;

public:
    SparseVector(int size) : size(size) {}

    int get_size() const {
        return size;
    }

    // ��������� ��������
    void set(int index, double value) {
        if (index >= size || index < 0)
            throw std::out_of_range("������ ��� ���������");
        if (value != 0)
            data[index] = value;
        else
            data.erase(index);
    }

    // ��������� ��������
    double get(int index) const {
        if (index >= size || index < 0)
            throw std::out_of_range("������ ��� ���������");
        auto it = data.find(index);
        return it != data.end() ? it->second : 0.0;
    }

    // �������� ��������
    SparseVector operator+(const SparseVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("������� �������� �� ���������");

        SparseVector result(size);
        for (const auto& entry : data)
            result.set(entry.first, entry.second);

        for (const auto& entry : other.data)
            result.set(entry.first, result.get(entry.first) + entry.second);

        return result;
    }

    // ��������� ������������
    double dot(const SparseVector& other) const {
        if (size != other.size)
            throw std::invalid_argument("������� �������� �� ���������");

        double result = 0;
        for (const auto& entry : data) {
            if (other.data.count(entry.first)) {
                result += entry.second * other.data.at(entry.first);
            }
        }
        return result;
    }

    // ��������� �� ������
    SparseVector operator*(double scalar) const {
        SparseVector result(size);
        for (const auto& entry : data)
            result.set(entry.first, entry.second * scalar);
        return result;
    }

    // ����� �������
    void print() const {
        for (int i = 0; i < size; ++i)
            std::cout << get(i) << " ";
        std::cout << std::endl;
    }
};
#endif // !SPARSE_VECTOR_H