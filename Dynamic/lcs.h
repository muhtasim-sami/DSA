
/*
 *
 * Pseudo Code :
 * =============
 *
 * Function LCS(X, Y)
    m <- length of X
    n <- length of Y
    Create a 2D array c[0..m, 0..n]

    // Initialize the first row and column
    for i from 0 to m
        c[i, 0] <- 0
    for j from 0 to n
        c[0, j] <- 0

    // Fill the array
    for i from 1 to m
        for j from 1 to n
            if X[i-1] == Y[j-1] then
                c[i, j] <- c[i-1, j-1] + 1
            else
                c[i, j] <- max(c[i-1, j], c[i, j-1])

    return c[m, n] // Length of the longest common subsequence
 * */


char* lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];


   for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  
  return lcsAlgo

  //cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}


