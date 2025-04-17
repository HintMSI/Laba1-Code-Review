//FIXME ���������� ������� �� �� ���-������

/*�������� ����� N ����������.�������� ����(�i) � ��������(di) ����������.�����
*������� ����� ������������ ��������� �����, ����� ��������� �� ��� �� �������� Z ��, � ��
*����� �������� ��������� ������������.��������, ��� ������� �����������.������� �����
*����� ������ �����, ������� ����� �����.�������� ������ ��������� � ��������� �����, �
*������ ������ ������� N � Z, � �� ������ ������ �������� �����(� ��), � ������� - ��������
*�������.������� ��� �� ��������� ��� � ����� �������� ����������.
*/
#include "backpack.h"
//FIXME ������� �������� ����������

//FIXME ����� ������ �����������,������� �� ��������� �����

//FIXME �� ���� ��������� �� ������� �� �������� ������ � �����,
// ������� �������� ������������ ������

//FIXME � ��������� ���� ����� ��������� �������� ��������� ��� � ����� ��������,
// ���� �� ���� � �������� ������������ ������
int main() {
	int numArtifacts = 0;
	int	maxWeight = 0;
	std::vector<int> artifactWeights = {}; 
	std::vector<int> artifactValues = {};

	if (!ReadInputFromFile("backpack.txt", numArtifacts, maxWeight, artifactWeights, artifactValues)) {
		return 1; 
	}

	std::vector<std::vector<int>> dp(numArtifacts + 1, std::vector<int>(maxWeight + 1));

	int maxValue = Backpack(maxWeight, artifactWeights, artifactValues, numArtifacts, dp);

	std::vector<int> selectedArtifacts;
	FindSelectedItems(maxWeight, numArtifacts, artifactWeights, dp, selectedArtifacts);

	int totalWeight = 0;
	int totalValue = 0;
	for (int idx : selectedArtifacts) {
		totalWeight += artifactWeights[idx - 1]; 
		totalValue += artifactValues[idx - 1];
	}

	std::cout << "������������ ��������� ��������� �����, ��������� � ������: " << maxValue << std::endl;
	std::cout << "��������� ���: " << totalWeight << " ��" << std::endl;
	std::cout << "��������� ��������: " << totalValue << std::endl;

	std::cout << "��������� ��������� (���������� ������): ";
	for (int i = selectedArtifacts.size() - 1; i >= 0; --i) {
		std::cout << selectedArtifacts[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}