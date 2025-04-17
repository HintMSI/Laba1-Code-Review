/* Продолжение задания 3 */
#ifndef K_DIGITS_H
#define K_DIGITS_H

using namespace std;
//FIXME был убрана библиотека vector,тк нигде не использовалась
#include <iostream>

double CalculateValidKDigitNumbers(int base, int digits);
bool ReadIntInRange(const string& prompt, int& value, int min, int max);

#endif