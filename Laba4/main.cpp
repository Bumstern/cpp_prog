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

    std::cout << "������� 1:" << std::endl;
    mat1.print();

    std::cout << "������� 2:" << std::endl;
    mat2.print();

    SparseMatrix result = mat1 + mat2;
    std::cout << "����� ������:" << std::endl;
    result.print();

    SparseMatrix product = mat1 * mat2;
    std::cout << "������������ ������:" << std::endl;
    product.print();

    SparseMatrix transposed = mat1.transpose();
    std::cout << "����������������� ������� 1:" << std::endl;
    transposed.print();

    SparseMatrix powered = mat1.pow(2);
    std::cout << "������� 1 � ��������:" << std::endl;
    powered.print();



    SparseVector vec1(5);
    vec1.set(0, 1.0);
    vec1.set(2, 2.0);
    vec1.set(4, 3.0);

    SparseVector vec2(5);
    vec2.set(2, 4.0);
    vec2.set(2, 5.0);

    cout << "������ 1:" << endl;
    vec1.print();

    cout << "������ 2:" << endl;
    vec2.print();
    
    SparseVector sum_res = vec1 + vec2;
    cout << "����� ��������: " << endl;
    sum_res.print();

    SparseVector prod_res = vec1 * 10;
    cout << "������������ ������� �� �����: " << endl;
    prod_res.print();

    double dot_res = vec1.dot(vec2);
    cout << "������������ ������� �� ������: " << dot_res << endl;

    SparseVector vec_temp(3);
    vec_temp.set(1, 22);
    vec_temp.set(2, 55);
    SparseVector vec_mat_mul = mat1 * vec_temp;
    cout << "������������ ������� �� ������: " << endl;
    vec_mat_mul.print();

    return 0;
}

