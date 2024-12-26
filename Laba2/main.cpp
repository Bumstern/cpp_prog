#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include "long_int.h"
using namespace std;

UnsignedLongInt f(UnsignedLongInt a, UnsignedLongInt b) {
	UnsignedLongInt c; 
	c = a + b;
	return c;
}

void ff(UnsignedLongInt& c) {
	c = "5";
}

void init_m(UnsignedLongInt* m) {
	for (int i = 0; i < 3; ++i) {
		m[i] = to_string(i);
	}
}

int main() {
	UnsignedLongInt a;
	UnsignedLongInt b(static_cast<string>("1230000000000"));
	UnsignedLongInt c = static_cast<string>("1000000000000000");
	UnsignedLongInt d;
	UnsignedLongInt e(static_cast<string>("330000000000"));
	UnsignedLongInt temp("12321");
	UnsignedLongInt g(move(temp));
	cout << g.to_str() << endl;

	d = c + c;
	a = "555";

	cout << a.to_str() << endl;
	cout << b.to_str() << endl;
	cout << c.to_str() << endl;
	cout << d.to_str() << endl;

	UnsignedLongInt* p = new UnsignedLongInt("333");
	cout << p->to_str() << endl;

	UnsignedLongInt m[3];
	init_m(m);
	cout << m[1].to_str() << endl;

	cout << f(a, b).to_str() << endl;

	ff(c);
	cout << c.to_str() << endl;

	vector<UnsignedLongInt> v(5);
	list<UnsignedLongInt> l(5);

	for (auto elem : v){
		elem = to_string(rand() % 1000);
		cout << elem.to_str() << endl;
	}
	
	for (auto elem : l) {
		elem = to_string(rand() % 500 + 50000);
		cout << elem.to_str() << endl;
	}

  return 0;
}
