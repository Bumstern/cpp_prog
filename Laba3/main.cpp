#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <string>
#include <algorithm>
#include <numeric>
#include "long_int.h"
using namespace std;


int main() {
	// Task 1
	vector<UnsignedLongInt> v1(rand() % 500 + 500);
	for (auto elem : v1) 
		elem = to_string(rand() % 1000000 + 1000000);
	
	// Task 2
	vector<UnsignedLongInt>::iterator b = v1.end() - 200; 
	vector<UnsignedLongInt>::iterator e = v1.end();
	vector<UnsignedLongInt> v2(b, e);
	cout << v2.size() << endl;

	// Task 3
	int n = rand() % 30 + 20;
	sort(v1.begin(), v1.end());
	list<UnsignedLongInt> list1(v1.end() - n, v1.end());
	
	// Task 4
	sort(v2.begin(), v2.end());
	list<UnsignedLongInt> list2(v2.begin(), v2.begin() + n);

	// Task 5
	v1.erase(v1.end() - n, v1.end());
	v2.erase(v2.begin(), v2.begin() + n);

    // Task 6
    UnsignedLongInt sum = accumulate(list1.begin(), list1.end(), UnsignedLongInt("0"));
    UnsignedLongInt average = to_string(stoi(sum.to_str()) / (int)list1.size());
    list<UnsignedLongInt> greater_than_avg, less_equal_avg;
    partition_copy(
        list1.begin(), list1.end(),
        back_inserter(greater_than_avg), back_inserter(less_equal_avg),
        [average](const UnsignedLongInt& x) { return average < x; }
    );
    list1.clear();
    list1.splice(list1.end(), greater_than_avg);
    list1.splice(list1.end(), less_equal_avg);

    // Task 7
    list2.remove_if([](const UnsignedLongInt& x) { return stoi(x.to_str()) % 2 != 0; });

    // Task 8
    vector<UnsignedLongInt> v3;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));

    // Task 9
    if (list1.size() > list2.size()) {
        auto diff = list1.size() - list2.size();
        auto it = next(list1.begin(), diff);
        list1.erase(list1.begin(), it);
    }
    else if (list2.size() > list1.size()) {
        auto diff = list2.size() - list1.size();
        auto it = next(list2.begin(), diff);
        list2.erase(list2.begin(), it);
    }
    list<pair<UnsignedLongInt, UnsignedLongInt>> list3;
    transform(
        list1.begin(), list1.end(), list2.begin(), back_inserter(list3),
        [](const UnsignedLongInt& a, const UnsignedLongInt& b) { return make_pair(a, b); }
    );

    // Task 10
    list<pair<UnsignedLongInt, UnsignedLongInt>> list4;
    transform(
        v1.begin(), v1.begin() + min(v1.size(), v2.size()), v2.begin(), back_inserter(list4),
        [](UnsignedLongInt& a, UnsignedLongInt& b) { return make_pair(a, b); }
    );
	
	return 0;
}
