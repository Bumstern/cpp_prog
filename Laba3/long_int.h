#ifndef LONG_INT_H
#define LONG_INT_H

#include <string>


class UnsignedLongInt {
  private:
    const int base = 1e9;
    const int size = 10; 

    int* digits;

    void fill_digits_with_string(std::string);
    std::string gen_zeros(std::string) const;

  public:
    UnsignedLongInt();
    UnsignedLongInt(std::string);
    UnsignedLongInt(const UnsignedLongInt&);
    UnsignedLongInt(UnsignedLongInt&&);
    ~UnsignedLongInt();

    std::string to_str() const;

    UnsignedLongInt& operator=(const UnsignedLongInt&);
    UnsignedLongInt& operator=(std::string);

    friend bool operator<(const UnsignedLongInt& left, const UnsignedLongInt& right);
    friend bool operator==(const UnsignedLongInt& left, const UnsignedLongInt& right);

    friend UnsignedLongInt operator+(UnsignedLongInt, const UnsignedLongInt&);
    friend UnsignedLongInt operator-(UnsignedLongInt, const UnsignedLongInt&);
};

#endif