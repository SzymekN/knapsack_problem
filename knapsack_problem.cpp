#include <iostream>
#include "libs/libKnapsack.h"

int main()
{
    //array of object containig info about items
    Item* items;
    //how many items in to check
    int itemCount{};
    //size of a knapsack
    int knapsackSize{};
 
    try {
        std::ifstream readFromFile;
        OpenFile(readFromFile, "in.txt");
        //count objects written each in another line, -1 because first line contains knapsack size
        itemCount = CountLines(readFromFile) - 1;
        readFromFile >> knapsackSize;

        if (itemCount < 1 or knapsackSize < 1)
            throw EXCEPTION_CODE::valueOutOfBoundaries;
        
        items = LoadItems(readFromFile, itemCount);

        KnapsackDynamic(items, itemCount, knapsackSize);
        ShowAllItems(items, itemCount);
    }
    catch (EXCEPTION_CODE err) {
        ShowException(err);
        exit(-1);
    }
}
