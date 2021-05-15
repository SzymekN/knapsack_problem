#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <string>
#include <sstream>
#include "libFiles.h"
#include "libArrays.h"

class Item;
Item* LoadItems(std::ifstream& readFromFile, int itemCount);
void KnapsackDynamic(Item* items, int itemCount, int knapsackSize);
void ShowPackedItems(Item* items, int* indexes, int size);

class Item
{
private:
	int price{};
	int weight{};
	std::string name{};

public:
	Item();
	Item(int, int, std::string);

	void ConcName(std::string n);
	void SetPrice(int p) { price = p;};
	void SetWeight(int w) { weight = w; };
	std::string GetName() { return name; };
	int GetPrice() { return price; };
	int GetWeight() { return weight; };
	
	friend Item* LoadItems(std::ifstream& readFromFile, int itemCount);
	friend void KnapsackDynamic(Item* items, int itemCount, int knapsackSize);
	friend void ShowPackedItems(Item* items, int* indexes, int size);

	~Item();
};

bool isNumber(std::string value);

int max(int a, int b);

#endif // !KNAPSACK_H
