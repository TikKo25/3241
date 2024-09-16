#include <iostream>

int main() {
	int student1, student2, student3;
	std::cout << "Stp1: ";
	std::cin >> student1;
	std::cout << "Stp2: ";
	std::cin >> student2;
	std::cout << "Stp3: ";
	std::cin >> student3;
	if (student1 >= 0 && student1 <= 100000) {
		student1 = student1;
	}
	else if (student1 <= 0 || student1 >= 100000) {
		std::cout << "Stp1: ";
		std::cin >> student1;
	}
	if (student2 >= 0 && student2 <= 100000) {
		student2 = student2;
	}
	else if (student2 <= 0 || student2 >= 100000) {
		std::cout << "Stp2: ";
		std::cin >> student2;
	}
	if (student3 >= 0 && student3 <= 100000) {
		student3 = student3;
	}
	else if (student3 <= 0 || student3 >= 100000) {
		std::cout << "Stp3: ";
		std::cin >> student3;
	}
	int max, min;
	if (student1 >= student2 && student1 >= student3) {
		max = student1;
	}
	else if (student2 >= student1 && student2 >= student3) {
		max = student2;
	}
	else {
		max = student3;
	}
	if (student1 <= student2 && student1 <= student3) {
		min = student1;
	}
	else if (student2 <= student1 && student2 <= student3) {
		min = student2;
	}
	else {
		min = student3;
	}
	int difference= max - min;
	std::cout << "Difference: "
	<< difference << std::endl;
	return 0;
}