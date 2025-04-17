/* Продолжение задания 3 */
#include "k_digits.h"
//FIXME было множество переименований переменных,тк были не по код стайлу

//FIXME учитывал префиксную запись в строках:11
double CalculateValidKDigitNumbers(int base, int digits) {
	int countEndsWithNonZero = base - 1;
	int countEndsWithSingleZero = 1;
	int countWithTwoOrMoreZeros = 0;

	for (int digit = 2; digit <= digits; ++digit) {
		int prevEndsWithNonZero = countEndsWithNonZero;
		int prevEndsWithSingleZero = countEndsWithSingleZero;
		int prevWithTwoOrMoreZeros = countWithTwoOrMoreZeros;

		countEndsWithNonZero = (prevEndsWithNonZero + prevEndsWithSingleZero) * (base - 1);
		countEndsWithSingleZero = prevEndsWithNonZero;
		countWithTwoOrMoreZeros = prevWithTwoOrMoreZeros * base + prevEndsWithSingleZero;
	}

	return countEndsWithNonZero + countEndsWithSingleZero;
}
// Добавлена ф-ция для проверки правильности ввода с клавиатуры
bool ReadIntInRange(const string& prompt, int& value, int min, int max) {
	while (true) {
		cout << prompt;
		cin >> value;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка: введите корректное число.\n";
			continue;
		}

		if (value < min || value > max) {
			cout << "Ошибка: значение должно быть в диапазоне от " << min << " до " << max << ".\n";
			continue;
		}

		return true;
	}
}