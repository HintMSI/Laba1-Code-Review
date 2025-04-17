//FIXME оформление условия не по код-стайлу

/*Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
*выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
*общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
*ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
*первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
*находок.Вывести так же суммарный вес и общую ценность результата.
*/
#include "backpack.h"
//FIXME поменял названия переменных

//FIXME убрал лишние комментарии,которые не объясняли зачем

//FIXME не было выполнено по условие об исходных данных в файле,
// поэтому пришлось дорабатывать логику

//FIXME в начальном коде также просилось выводить суммарный вес и общую ценность,
// чего не было и пришлось дорабатывать логику
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

	std::cout << "Максимальная возможная стоимость вещей, уместимых в рюкзак: " << maxValue << std::endl;
	std::cout << "Суммарный вес: " << totalWeight << " кг" << std::endl;
	std::cout << "Суммарная ценность: " << totalValue << std::endl;

	std::cout << "Выбранные артефакты (порядковые номера): ";
	for (int i = selectedArtifacts.size() - 1; i >= 0; --i) {
		std::cout << selectedArtifacts[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}