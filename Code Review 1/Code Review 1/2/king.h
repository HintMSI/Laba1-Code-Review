/* Продолжение задания 2 */
#ifndef KING_H
#define KING_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Для reverse
#include <fstream>    

using namespace std;

extern int n;

void Solve(std::vector<std::vector<int>>& field1, std::vector<std::vector<int>>& field2, std::vector<std::vector<char>>& path);
void PrintPath(std::vector<std::vector<char>>& path, std::string& directions);
bool ValidateInputFile(std::ifstream& inputFile);

#endif  