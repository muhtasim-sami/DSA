/*
 * Pseudo code :
 *
 * function knapsack(W, wt[], val[], n):
    // W: maximum capacity of the knapsack
    // wt[]: array of weights
    // val[]: array of values
    // n: number of items

    // Create a 2D array to store the maximum value at each n and W
    let dp[n + 1][W + 1]

    // Build the dp array in a bottom-up manner
    for i from 0 to n:
        for w from 0 to W:
            if i == 0 or w == 0:
                dp[i][w] = 0  // Base case: no items or weight
            else if wt[i - 1] <= w:
                // Include the item and check value
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])
            else:
                // Exclude the item
                dp[i][w] = dp[i - 1][w]

    return dp[n][W]  // Maximum value that can be obtained
 *
 * */

// Function to solve 0/1 Knapsack using Bottom-Up DP
int knapsackBottomUp(int weight[], int value[], int N, int W)
{
    // DP table
    int dp[N + 1][W + 1];

    // Initialize first row and column with 0
    for (int i = 0; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    dp[i - 1][w - weight[i - 1]] + value[i - 1]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

