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
// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
//#include<bits/stdc++.h>
#include"libs/libArrays.h"
using namespace std;

/*
// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n,
    int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[16];
    memset(dp, 0, sizeof dp);

    // Fill dp[] using above recursive formula
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
        ShowArray(dp, 16, 4);
    }

    return dp[15];
}

// Driver program
int main()
{
    int W = 15;
    int val[] = { 400,410,50,30,70,2000,150};
    int wt[] = { 5,6,1,8,1,10,2 };
    int n = sizeof(val) / sizeof(val[0]);

    cout << unboundedKnapsack(W, n, val, wt);

    return 0;
}
*/