#include <iostream>
#include <unordered_map>
#include <cmath>
#include "sparse_vector.h"
#include "sparse_matrix.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    SparseMatrix mat1(3, 3);
    mat1.set(0, 0, 1);
    mat1.set(1, 1, 2);
    mat1.set(2, 2, 3);

    SparseMatrix mat2(3, 3);
    mat2.set(0, 1, 4);
    mat2.set(1, 2, 5);

    std::cout << "Матрица 1:" << std::endl;
    mat1.print();

    std::cout << "Матрица 2:" << std::endl;
    mat2.print();

    SparseMatrix result = mat1 + mat2;
    std::cout << "Сумма матриц:" << std::endl;
    result.print();

    SparseMatrix product = mat1 * mat2;
    std::cout << "Произведение матриц:" << std::endl;
    product.print();

    SparseMatrix transposed = mat1.transpose();
    std::cout << "Транспонированная матрица 1:" << std::endl;
    transposed.print();

    SparseMatrix powered = mat1.pow(2);
    std::cout << "Матрица 1 в квадрате:" << std::endl;
    powered.print();



    SparseVector vec1(5);
    vec1.set(0, 1.0);
    vec1.set(2, 2.0);
    vec1.set(4, 3.0);

    SparseVector vec2(5);
    vec2.set(2, 4.0);
    vec2.set(2, 5.0);

    cout << "Вектор 1:" << endl;
    vec1.print();

    cout << "Вектор 2:" << endl;
    vec2.print();
    
    SparseVector sum_res = vec1 + vec2;
    cout << "Сумма векторов: " << endl;
    sum_res.print();

    SparseVector prod_res = vec1 * 10;
    cout << "Произведение вектора на число: " << endl;
    prod_res.print();

    double dot_res = vec1.dot(vec2);
    cout << "Произведение вектора на вектор: " << dot_res << endl;

    SparseVector vec_temp(3);
    vec_temp.set(1, 22);
    vec_temp.set(2, 55);
    SparseVector vec_mat_mul = mat1 * vec_temp;
    cout << "Произведение матрицы на вектор: " << endl;
    vec_mat_mul.print();

    return 0;
}

