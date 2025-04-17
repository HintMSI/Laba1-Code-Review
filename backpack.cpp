/* Продолжение задания 1 */
#include "backpack.h"
//FIXME В названиях методов изменана первая буква на заглавную

//FIXME Соблюдена префиксная запись в строках:4,17,18,35,59,70

//FIXME Соблюдена табуляция для else в строках:23,26
void InsertSort(std::vector<int>& weights, std::vector<int>& values, std::vector<int>& indices) {
    for (int i = 1; i < weights.size(); ++i) {
        int temp = i;
        while (temp - 1 >= 0 && weights[temp] < weights[temp - 1]) {
            std::swap(weights[temp], weights[temp - 1]);
            std::swap(values[temp], values[temp - 1]);
            std::swap(indices[temp], indices[temp - 1]);
            temp--;
        }
    }
}

int Backpack(int maxWeight, std::vector<int>& weights, std::vector<int>& values, int numArtifacts, std::vector<std::vector<int>>& dp) {
    for (int i = 0; i <= numArtifacts; ++i) {
        for (int w = 0; w <= maxWeight; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }else if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[numArtifacts][maxWeight];
}

void FindSelectedItems(int maxWeight, int numArtifacts, const std::vector<int>& weights, std::vector<std::vector<int>>& dp, std::vector<int>& selectedArtifacts) {
    int w = maxWeight;
    for (int i = numArtifacts; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedArtifacts.push_back(i); 
            w -= weights[i - 1];  
        }
    }
}

// FIXME добавлена функция на проверку входного файла,тк начальных услових соблюдено не было
bool ReadInputFromFile(const std::string& filename, int& numArtifacts, int& maxWeight, std::vector<int>& weights, std::vector<int>& values) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return false;
    }

    std::string line = "";
    std::getline(file, line);
    std::istringstream ss(line);
    ss >> numArtifacts >> maxWeight;

    std::getline(file, line);
    std::istringstream weightStream(line);
    weights.resize(numArtifacts);
    for (int i = 0; i < numArtifacts; ++i) {
        weightStream >> weights[i];
        if (weights[i] <= 0) {
            std::cerr << "Ошибка: вес должен быть положительным." << std::endl;
            return false;
        }
    }

    std::getline(file, line);
    std::istringstream valueStream(line);
    values.resize(numArtifacts);
    for (int i = 0; i < numArtifacts; ++i) {
        valueStream >> values[i];
        if (values[i] < 0) {
            std::cerr << "Ошибка: стоимость не может быть отрицательной." << std::endl;
            return false;
        }
    }

    return true;
}