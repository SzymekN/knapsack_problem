#include <iostream>
#include "libs/libKnapsack.h"

int main()
{
    Item* items;
    int itemCount{};
    int knapsackSize{};
    std::ifstream readFromFile;
    OpenFile(readFromFile, "in.txt");
    //-1 because first line contains knapsack size
    itemCount = CountLines(readFromFile) - 1;
    readFromFile >> knapsackSize;
    items = LoadItems(readFromFile, itemCount);

    KnapsackDynamic(items, itemCount, knapsackSize);

    for (int i = 0; i < itemCount; i++) {
        std::cout << items[i].GetName() << " " << items[i].GetPrice()
            << " " << items[i].GetWeight() << "\n";
    }

}
