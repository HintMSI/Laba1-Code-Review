/* Продолжение задания 1 */
#ifndef BACKPACK_H
#define BACKPACK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

void InsertSort(std::vector<int>& weights, std::vector<int>& values, std::vector<int>& indices);

int Backpack(int maxWeight, std::vector<int>& weights, std::vector<int>& values, int numArtifacts, std::vector<std::vector<int>>& dp);

void FindSelectedItems(int maxWeight, int numArtifacts, const std::vector<int>& weights, std::vector<std::vector<int>>& dp, std::vector<int>& selectedArtifacts);

bool ReadInputFromFile(const std::string& filename, int& numArtifacts, int& maxWeight,std::vector<int>& weights, std::vector<int>& values);

#endif 