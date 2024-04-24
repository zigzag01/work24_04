// �������� ��������� �� 1 ����
// 14. �������� ����� �� Input.txt � ������, ��������� ������.
// ���������� ������ ���� ���, �������� ������� ����� ������ ������ �������.
// �������� � ����������� ������ � ������� � Output.txt

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
		cout << "�� ������� ������� ���� Input.txt" << endl;
		return 0;
	}
	if (!output.is_open()) {
		cout << "�� ������� ������� ���� Output.txt" << endl;
		return 0;
	}

	output << "���� �����: ";
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

	output << "����� ������������������: ";
	for (const auto& n : numbers_list) {
		output << n << " "; 
	}
	output << endl;

	input.close();
	output.close();

	system("pause");
	return 0;
}