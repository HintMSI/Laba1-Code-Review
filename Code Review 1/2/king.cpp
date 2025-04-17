/* ����������� ������� 2 */
#include "king.h"

int n = 0; // ����������� ����������, �� ����������

//FIXME ��� ������ �������� � ��������� �����, � ���������� � ���������

//FIXME �������� �� ���������� ������ � �������:13,17,22,23,46,43,65,66 
//FIXME �������� ��������� else � �������:28,44
void Solve(vector<vector<int>>& field1, vector<vector<int>>& field2, vector<vector<char>>& path) {
    int max = 0;
    field2[n - 1][n - 1] = field1[n - 1][n - 1];

    for (int i = n - 2; i >= 0; --i) {
        field2[i][n - 1] = field2[i + 1][n - 1] + field1[i][n - 1];
        path[i][n - 1] = 'U';  
    }
    for (int j = n - 2; j >= 0; --j) {
        field2[n - 1][j] = field2[n - 1][j + 1] + field1[n - 1][j];
        path[n - 1][j] = 'L';  

    // ���������� ���������� �����
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            if (field2[i + 1][j] > field2[i][j + 1]) {
                max = field2[i + 1][j];
                path[i][j] = 'U';
            }else {
                max = field2[i][j + 1];
                path[i][j] = 'L';  
            }
            field2[i][j] = max + field1[i][j];
        }
    }
}
//FIXME �������� �� �������� ��������
void PrintPath(vector<vector<char>>& path, string& directions) {
    int i = 0;
    int j = 0;
    while (i < n - 1 || j < n - 1) {
        if (path[i][j] == 'U') {
            directions = directions + "U ";
            ++i;
        }else if (path[i][j] == 'L') {
            directions = directions + "L ";
            ++j;
        }
    }
    reverse(directions.begin(), directions.end());  
}
//FIXME ��������� �������� �������� �����
bool ValidateInputFile(ifstream& inputFile) {
    if (!inputFile.is_open()) {
        cout << "������: �� ������� ������� ���� ��� ������." << endl;
        return false;  
    }

    inputFile >> n;
    if (n <= 1 || n >= 80) {
        cout << "������: ������ ����� ������ ���� � �������� �� 2 �� 79." << endl;
        return false;
    }

    int value;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> value;
            if (value < 1 || value > 100) {
                cout << "������: �������� �� ����� ������ ���� � �������� �� 1 �� 100." << endl;
                return false;
            }
        }
    }

    return true;
}