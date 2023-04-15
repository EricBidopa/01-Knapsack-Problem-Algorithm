
#include <iostream>
#include <vector>
#include <algorithm>
using std::endl;
using std::vector;

int knapsack(int MaxWeight, const vector<int> &itemWeight, const vector<int> &itemVal) /*The code defines
a function knapsack that takes three parameters: the max capacity of the knapsack (W), a
of item weights (wt), and a vector of item values (val). */
                                                                                       // NB: Value in this context means how precious the item is.
{
    // 2D vector initialization
    const int n = itemWeight.size();
    vector<vector<int>> dp(n + 1, vector<int>(MaxWeight + 1, 0));

    // this loop is where all the magic happens. Greedy algorithm at work :)
    for (uint i = 1; i <= n; ++i)
    {
        for (uint w = 1; w <= MaxWeight; ++w)
        {
            if (itemWeight[i - 1] <= w)
            {
                dp[i][w] = std::max(itemVal[i - 1] + dp[i - 1][w - itemWeight[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][MaxWeight];
}

int main()
{
    const vector<int> itemWeights = {9, 7, 4, 2, 2};
    const vector<int> itemValues = {10, 2, 30, 10, 50};
    const int MaxKnapSackWeight = 10;

    const int max_val = knapsack(MaxKnapSackWeight, itemWeights, itemValues);
    std::cout << "Maximum Value of Items that the Knapsack can take is : " << max_val << " \n \t  With this information, you can now \n pair with the max weight of the knapsack, which will help you make \n the right choice for the items to take for the knapsack" << std::endl;

    return 0;
}
