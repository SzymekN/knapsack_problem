#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <string>
#include <sstream>
#include "libFiles.h"
#include "libArrays.h"

class Item;
Item* LoadItems(std::ifstream& readFromFile, int itemCount);

//Class representing one item in knapsack
class Item
{
private:
	int price;
	int weight;
	std::string name;

public:
	Item();
	Item(int, int, std::string);

	/*
	Set name or append to it
	@param n - name or part of a name of object
	*/
	void ConcName(std::string n);
	void SetPrice(int p) { price = p;};
	void SetWeight(int w) { weight = w; };
	std::string GetName() { return name; };
	int GetPrice() { return price; };
	int GetWeight() { return weight; };
	
	/*
	Load items from file to array
	@param readFromFile - read from this file
	@param itemCount - number of items to read
	@return array of Item objects
	*/
	friend Item* LoadItems(std::ifstream& readFromFile, int itemCount);

	/*
	Dynamic algorithm to solve unbounded knapsack problem
	@param items - array of Item class objects
	@param itemCount - number of items available
	@param knapsackSize - max knapsack size
	*/
	friend void KnapsackDynamic(Item* items, int itemCount, int knapsackSize);

	/*
	Show solution of unbounded knapsack problem
	@param items - array of Item class objects
	@param indexes - row of indexes containing solution
	@param size - size of indexes array
	*/
	friend void ShowPackedItems(Item* items, int* indexes, int size);

	~Item();
};

/*
Check if string is a number
@param value - check this string
@return true if number
*/
bool isNumber(std::string value);

/*
Return greater value
*/
int max(int a, int b);

/*
Show all items available
@param items - array with Item class objects
@param itemCount - number of items available
*/
void ShowAllItems(Item* items, int itemCount);

#endif // !KNAPSACK_H
