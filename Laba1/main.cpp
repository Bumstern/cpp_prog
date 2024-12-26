#define _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "string"
#include <fstream>
#include <format>
#include <set>
#include "func_1.h"
using namespace std;


bool is_number(string s, bool is_float = false) {
	string::const_iterator it = s.begin();
	bool is_first_char = true;
	while (it != s.end()) {
		if (!isdigit(*it))
			// Если это float, то разрешена точка
			if (is_float && (char)*it == '.') {
				++it;
				is_first_char = false;
				continue;
			}
			// Если число отрицательное
			else if (is_first_char && (char)*it == '-') {
				++it;
				is_first_char = false;
				continue;
			}
			else
				// Все другие варианты запрещены
				break;

			++it;
			is_first_char = false;
	}
	return !s.empty() && it == s.end();
}


void create_sum_func(string type1, string type2) {
	double value1, value2;
	string inpt_value;
	do {
		cout << "Введите первое значение: ";
		cin >> inpt_value;
	} while (!is_number(inpt_value, (type1 != "int")));
	value1 = stod(inpt_value);
	do {
		cout << "Введите второе значение: ";
		cin >> inpt_value;
	} while (!is_number(inpt_value, (type2 != "int")));
	value2 = stod(inpt_value);

	string program_template =
		"#include <iostream>\n"
		"int f(void) {\n"
		"%s val1 = %f;\n"
		"%s val2 = %f;\n"
		"std::cout << val1 + val2 << std::endl;\n"
		"std::cout << val1 * val2 << std::endl;\n"
		"return 0;\n"
		"}\n";
	FILE* fptr = fopen("func_1.cpp", "w");
	fprintf(fptr, program_template.c_str(), type1.c_str(), value1, type2.c_str(), value2);
	fclose(fptr);
}


bool check_input(string value) {
	set<string> approved_types = { "int", "float", "double" };
	return (bool)(approved_types.find(value) != approved_types.end());
}


int main(void) {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");

	string type1, type2;
	cout << "Разрешенные типы данных: int, float, double" << endl;
	do {
		cout << "Введите первый тип: ";
		cin >> type1;
	} while (!check_input(type1));
	do {
		cout << "Введите второй тип: ";
		cin >> type2;
	} while (!check_input(type2));
	
	create_sum_func(type1, type2);
	
	f();

	return 0;
}
