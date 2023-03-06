#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left + 1) + left;
}

template <typename T>
void clear_arr(T arr[], const int length, int key) {
	for (int i = 0; i < length; i++)
		if (arr[i] == key)
			arr[i] = 0;
}

int index_sum(int arr1[], int arr2[], const int length1, const int length2, int i) {
	if (i >= length1 || i >= length2 || i < 0) {
		std::cout << "ERROR\n";
		return 0;
	}
	else
		return arr1[i] + arr2[i];
}

template <typename T>
double mean_arr(T arr[], const int length) {
	T max = arr[0], min = arr[0];
	for (int i = 1; i < length; i++) {
		max = arr[i] > max ? arr[i] : max;
		min = arr[i] < min ? arr[i] : min;
	}
	return (double)(max + min) / 2.0;
}

void prime_range(int begin, int end) {
	int counter;
	for (int i = begin; i <= end; i++){
		counter = 0;
		for (int j = i; j >= 1; j--)
			if (i % j == 0)
				counter++;
		if (counter == 2) 
			std::cout << i << "  ";
	}
}

template <typename T>
void permute_arr(T arr[], const int length) {
	for (int i = 0; i < length / 2; i++)
		if (length % 2)
			std::swap(arr[i], arr[i + 1 + length / 2]);
		else
			std::swap(arr[i], arr[i + length / 2]);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1
	std::cout << "\t\tЗадача 1\n";
	const int size1 = 20;
	int arr1[size1];
	fill_arr(arr1, size1, 0, 10);
	std::cout << "Изначальный массив:\n";
	print_arr(arr1, size1);
	std::cout << "Введите ключевое значение -> ";
	std::cin >> n;
	clear_arr(arr1, size1, n);
	std::cout << "Измененный массив:\n";
	print_arr(arr1, size1);

	// Задача 2
	std::cout << "\n\t\tЗадача 2\n";
	int index, sum;
	const int sizeA = 20;
	int arr_A[sizeA];
	fill_arr(arr_A, sizeA, 0, 10);
	std::cout << "Изначальный массив A:\n";
	print_arr(arr_A, sizeA);
	const int sizeB = 10;
	int arr_B[sizeB];
	fill_arr(arr_B, sizeB, 10, 20);
	std::cout << "Изначальный массив B:\n";
	print_arr(arr_B, sizeB);
	std::cout << "Введите индекс для суммирования -> ";
	std::cin >> index;
	sum = index_sum(arr_A, arr_B, sizeA, sizeB, index);
	if (sum)
		std::cout << "A[" << index << "] + B[" << index  << "] = " << index_sum(arr_A, arr_B, sizeA, sizeB, index) << '\n';

	// Задача 3
	std::cout << "\n\t\tЗадача 3\n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, 1, 10);
	std::cout << "Изначальный массив:\n";
	print_arr(arr3, size3);
	std::cout << "Среднее арифметическое максимального и минимального элементов: " << mean_arr(arr3, size3) << '\n';

	// Задача 4
	std::cout << "\n\t\tЗадача 4\n";
	int begin, end;
	std::cout << "Введите начало диапазона -> ";
	std::cin >> begin;
	std::cout << "Введите начало диапазона -> ";
	std::cin >> end;
	std::cout << "Простые числа в диапазоне [" << begin << ".." << end << "]:\n";
	prime_range(begin, end);
	std::cout << '\n';

	// Задача 5
	std::cout << "\n\t\tЗадача 5\n";
	const int size5 = 11;
	int arr5[size5];
	fill_arr(arr5, size5, 0, 10);
	std::cout << "Изначальный массив:\n";
	print_arr(arr5, size5);
	permute_arr(arr5, size5);
	std::cout << "Измененный массив:\n";
	print_arr(arr5, size5);

	return 0;
}