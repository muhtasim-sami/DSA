
/*
 * Pseudo Code :
 * =============
 *
 * function MatrixChainOrder(p):
    n = length(p) - 1
    let m be a 2D array of size n x n
    for i from 1 to n do
        m[i][i] = 0  // cost is zero when multiplying one matrix

    for L from 2 to n do  // L is the chain length
        for i from 1 to n - L + 1 do
            j = i + L - 1
            m[i][j] = ∞  // set to a large value
            for k from i to j - 1 do
                // Cost of multiplying matrices from i to j
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
                if q < m[i][j] then
                    m[i][j] = q  // update minimum cost

    return m[1][n]  // Minimum cost to multiply matrices from 1 to n
 *
 * */


#define INF = 1000000000;

int matrixChainMultiplication()
{
    // Matrix dimensions:
    // A1 = 10x30, A2 = 30x5, A3 = 5x60
    int p[] = {10, 30, 5, 60};
    int n = 4;  // number of dimensions

    int m[10][10];
    //int INF = 1000000000;

    // Cost is zero for single matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Chain length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i <= n - L; i++)
        {
            int j = i + L - 1;
            m[i][j] = INF;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];
}



