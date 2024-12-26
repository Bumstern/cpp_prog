#include <iostream>
#include <string>
#include "long_int.h"
using namespace std;


UnsignedLongInt::UnsignedLongInt() {
    std::cout << "Default Constructor" << std::endl;
    digits = new int[size];

    for (int i = 0; i < size; i++) 
        digits[i] = 0;
}

UnsignedLongInt::~UnsignedLongInt() {
    std::cout << "Destructor" << std::endl;
    delete[] digits;
}

UnsignedLongInt::UnsignedLongInt(std::string x) {
    std::cout << "Transform Constructor with " + x << std::endl;
    digits = new int[size];
    for (int i = 0; i < size; i++)
        digits[i] = 0;

    fill_digits_with_string(x);
}

UnsignedLongInt::UnsignedLongInt(const UnsignedLongInt& other) {
    cout << "Copy Constructor with " + other.to_str() << endl;
    digits = new int[size];

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }
}

UnsignedLongInt::UnsignedLongInt(UnsignedLongInt&& other) {
    cout << "Move Constructor with " + other.to_str() << endl;
    digits = other.digits;
    other.digits = nullptr;
}

void UnsignedLongInt::fill_digits_with_string(std::string x) {
    int digit_i = 0;
    for (int i = (int)x.size(); i > 0; i -= 9) {
        if (i < 9) {
            digits[digit_i] = atoi(x.substr(0, i).c_str());
        }
        else
            digits[digit_i] = atoi(x.substr(i - 9, 9).c_str());
        ++digit_i;
    }
}

string UnsignedLongInt::gen_zeros(string s) const {
    int zeros_num = size - (int)s.size() - 1;
    string zeros = "";
    for (int i = 0; i < zeros_num; ++i) {
        zeros += "0";
    }
    return zeros + s;
}

std::string UnsignedLongInt::to_str() const {
    std::string res = "";
    int non_null_blk_id = -1;
    for (int i = 0; i < size; ++i) {
        res = gen_zeros(std::to_string(digits[i])) + res;
        non_null_blk_id = digits[i] > 0 ? i : non_null_blk_id;
    }
    if (non_null_blk_id == -1)
        return "0";

    res = res.substr(res.find_first_not_of('0'), res.size());

    return res;
}

UnsignedLongInt& UnsignedLongInt::operator=(const UnsignedLongInt& other) {    
    std::cout << "Assign Operator with other" << std::endl;

    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }

    return *this;
}

UnsignedLongInt& UnsignedLongInt::operator=(std::string x) {
    std::cout << "Assign Operator with string " + x << std::endl;
    for (int i = 0; i < size; i++)
        digits[i] = 0;
    fill_digits_with_string(x);
    return *this;
}

bool operator<(const UnsignedLongInt& left, const UnsignedLongInt& right) {
    if (left == right) return false;

    for (int i = left.size - 1; i >= 0; --i) {
        if (left.digits[i] == 0 && right.digits[i] == 0)
            continue;
        if (left.digits[i] < right.digits[i])
            return true;
        else
            return false;
    }
}

bool operator==(const UnsignedLongInt& left, const UnsignedLongInt& right) {
    for (int i = 0; i < left.size; ++i) {
        if (left.digits[i] != right.digits[i])
            return false;
    }
    return true;
}

UnsignedLongInt operator+(UnsignedLongInt left, const UnsignedLongInt& right) {
    cout << "Plus to " + left.to_str() << endl;
    int carry = 0;
    for (int i = 0; i < left.size; ++i) {
        left.digits[i] += carry + right.digits[i];
        carry = (left.digits[i] >= left.base ? 1 : 0);
        if (carry > 0)
            left.digits[i] -= left.base;
    }
    return left;
}

UnsignedLongInt operator-(UnsignedLongInt left, const UnsignedLongInt& right) {
    cout << "Minus to " + left.to_str() << endl;
    int carry = 0;
    for (int i = 0; i < left.size; ++i) {
        left.digits[i] -= carry + right.digits[i];
        carry = (left.digits[i] < 0 ? 1 : 0);
        if (carry)  
            left.digits[i] += left.base;
    }
    return left;
}
