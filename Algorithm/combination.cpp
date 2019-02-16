scanf("%d %d", &N, &M);

for (int m = 0; m < M; m++) dp[0][m] = m + 1;

for (int n = 1; n < N; n++) for (int m = 1; m < M; m++)
  dp[n][m] = dp[n][m - 1] + dp[n - 1][m - 1];

printf("%d\n", dp[N - 1][M - 1]);
