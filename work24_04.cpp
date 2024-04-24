// Белоушко Елизавета ПИ 1 курс
// 14. Записать числа из Input.txt в память, используя вектор.
// Просмотрев список один раз, поменять крайние числа каждой тройки местами.
// Записать в стандартный список и вывести в Output.txt

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	ifstream input("Input.txt");
	ofstream output("Output.txt");
	if (!input.is_open()) {
		cout << "Не удалось открыть файл Input.txt" << endl;
		return 0;
	}
	if (!output.is_open()) {
		cout << "Не удалось открыть файл Output.txt" << endl;
		return 0;
	}

	output << "Даны числа: ";
	vector<int> numbers;
	int num;
	while (input >> num) {
		output << num << " "; 
		numbers.push_back(num);
	}
	output << endl;
	
	list<int> numbers_list(numbers.begin(), numbers.end()); 

	int n;
	for (auto n = numbers_list.begin(); n != numbers_list.end();) {
		auto first_num = n++;
		if (n != numbers_list.end()) {
			auto second_num = n++;
			if (n != numbers_list.end()) {
				auto third_num = n++;
				swap(*first_num, *third_num);
			}
		}
	}	

	output << "Новая последовательность: ";
	for (const auto& n : numbers_list) {
		output << n << " "; 
	}
	output << endl;

	input.close();
	output.close();

	system("pause");
	return 0;
}