#include "libKnapsack.h"

Item::Item() : price{ -1 }, weight{ -1 }, name{""} {}

Item::Item(int p, int w, std::string n) : price{ p }, weight{ w }, name{ n } {}
void Item::ConcName(std::string n)
{
	if (this->name == "") {
		this->name = n;
	}
	else {
		this->name += " ";
		this->name += n;
	}
}
;
Item* LoadItems(std::ifstream& readFromFile, int itemCount)
{
	std::string line{};
	std::string value{};
	Item* items = new Item[itemCount];
	for (int i = 0; i < itemCount; i++) {
		std::getline(readFromFile, line);
		if(line == "")
			std::getline(readFromFile, line);
		std::istringstream iss(line);
		while (iss.peek() != EOF) {
			iss >> value;
			if (isNumber(value) == false) {
				items[i].ConcName(value);
			}
			else if (items[i].price == -1)
				items[i].price = stoi(value);
			else
				items[i].weight = stoi(value);
		}
	}

	return items;
}

void KnapsackDynamic(Item* items, int itemCount, int knapsackSize)
{
	int** knapsackValues = CreateArray<int>(itemCount + 1, knapsackSize + 1);
	int** indexes = CreateArray<int>(itemCount + 1, knapsackSize + 1);

	SetDefaultValues(knapsackValues, 0, itemCount + 1, knapsackSize + 1);
	SetDefaultValues(indexes, 0, itemCount + 1, knapsackSize + 1);

	int newValue = 0;
	int oldValue = 0;

	for (int i = 1; i <= itemCount; i++) {
		for (int j = 1; j <= knapsackSize; j++) {
			newValue = 0;
			oldValue = 0;
			if (items[i - 1].weight <= j) {
				newValue = items[i - 1].price + knapsackValues[i][j - items[i - 1].weight];
			}

			if (i > 0) {
				oldValue = knapsackValues[i - 1][j];
			}
			if (newValue > oldValue) {
				knapsackValues[i][j] = newValue;
				indexes[i][j] = i;
			}
			else {
				knapsackValues[i][j] = oldValue;
				indexes[i][j] = indexes[i - 1][j];
			}
			//knapsackValues[i][j] = max(includeProfit, excludeProfit);
		}

	}
	std::cout << "Values: \n";
	ShowArray(knapsackValues, itemCount + 1, knapsackSize + 1, 3);

	std::cout << "Indexes: \n";
	ShowArray(indexes, itemCount + 1, knapsackSize + 1, 3);

	ShowPackedItems(items, indexes[itemCount], knapsackSize);

	std::cout << "\n";

	DeleteArray(knapsackValues);
	DeleteArray(indexes);

}

void ShowPackedItems(Item* items, int* indexes, int size)
{

	int index = indexes[size];
	std::cout << "Items: \n";
	while (size > 0 and indexes[size] != 0) {
		//std::cout<< index<<" "<< items[index-1].weight<<" "<< sizeLeft;
		index = indexes[size];
		std::cout << "\t- " << items[index - 1].name << "\n";
		size -= items[index - 1].weight;
	}
}


Item::~Item(){}

bool isNumber(std::string value)
{
	for (int i = 0; i < value.length(); i++) {
		if (isdigit(value[i]) == false)
			return false;
	}
	return true;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
