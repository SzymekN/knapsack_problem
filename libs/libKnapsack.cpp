#include "libKnapsack.h"

Item::Item() : price{ -1 }, weight{ -1 }, name{ "" } {}

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
	//line read
	std::string line{};
	//one value from line
	std::string value{};
	//array of items
	Item* items = new Item[itemCount];

	for (int i = 0; i < itemCount; i++) {
		
		std::getline(readFromFile, line);
		//if empty line read - skip
		if (line == "")
			std::getline(readFromFile, line);
		
		std::istringstream iss(line);
	
		while (iss.peek() != EOF) {
			iss >> value;
			
			//check if read value is a number
			if (isNumber(value) == false) {
				items[i].ConcName(value);
			}
			else if (items[i].price == -1)
				items[i].price = stoi(value);
			else
				items[i].weight = stoi(value);
		}

		if (items[i].name == "" or items[i].price < 0 or items[i].weight < 1)
			throw EXCEPTION_CODE::invalidData;

	}

	return items;
}

void KnapsackDynamic(Item* items, int itemCount, int knapsackSize)
{
	//array of best values at each iteration
	int** knapsackValues = CreateArray<int>(itemCount + 1, knapsackSize + 1);
	//array of indexes of best values at each iteration
	int** indexes = CreateArray<int>(itemCount + 1, knapsackSize + 1);

	SetDefaultValues(knapsackValues, itemCount + 1, knapsackSize + 1);
	SetDefaultValues(indexes, itemCount + 1, knapsackSize + 1);

	//value of current item + items from row above
	int newValue = 0;
	//value of cell in row above
	int oldValue = 0;

	for (int i = 1; i <= itemCount; i++) {
		for (int j = 1; j <= knapsackSize; j++) {
			newValue = 0;
			oldValue = 0;
			//if item fits in knapsack check it's value
			if (items[i - 1].weight <= j) {
				newValue = items[i - 1].price + knapsackValues[i][j - items[i - 1].weight];
			}

			if (i > 0) {
				oldValue = knapsackValues[i - 1][j];
			}
			//if new value is better write it, else copy from cell above
			if (newValue > oldValue) {
				knapsackValues[i][j] = newValue;
				indexes[i][j] = i;
			}
			else {
				knapsackValues[i][j] = oldValue;
				indexes[i][j] = indexes[i - 1][j];
			}
		}

	}
	std::cout << "Values: \n";
	ShowArray(knapsackValues, itemCount + 1, knapsackSize + 1, 4);

	std::cout << "Indexes: \n";
	ShowArray(indexes, itemCount + 1, knapsackSize + 1, 4);

	ShowPackedItems(items, indexes[itemCount], knapsackSize);

	DeleteArray(knapsackValues);
	DeleteArray(indexes);

}

void ShowPackedItems(Item* items, int* indexes, int size)
{
	//set variable to index last element in knapsack 
	int index = indexes[size];
	std::cout << "Items: \n";

	//read what values are in knapsack
	while (size > 0 and indexes[size] != 0) {
		index = indexes[size];
		std::cout << "\t- " << items[index - 1].name << "\n";
		size -= items[index - 1].weight;
	}
}


Item::~Item() {}

bool isNumber(std::string value)
{
	//check if all chars in srting are numbers
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

void ShowAllItems(Item* items, int itemCount)
{
	//Show all items available
	std::cout <<"\n"<< std::setw(20) << "Name" << std::setw(10) << "Price" << std::setw(10) << "Weight\n";
	for (int i = 0; i < itemCount; i++) {
		std::cout << std::setw(20) << items[i].GetName() << std::setw(10) << items[i].GetPrice()
			<< std::setw(10) << items[i].GetWeight() << "\n";
	}
}
