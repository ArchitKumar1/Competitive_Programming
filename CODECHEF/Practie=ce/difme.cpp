
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;

int N, M;
bool flip;
int res[MAXN][MAXN];

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d%d", &N, &M);

        if (N > M) {
            swap(N, M);
            flip = true;
        } else {
            flip = false;
        }

        if (N == 1) {
            printf("%d\n", (M <= 2) ? 1 : 2);
            for (int j = 0; j < M; ++j)
                res[0][j] = 1 + (j/2) % 2;
        } else if (N == 2) {
            printf("%d\n", (M == 2) ? 2 : 3);
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j)
                    res[i][j] = 1 + j % 3;
        } else {
            printf("4\n");
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j) {
                    if (j%2 == 0)
                        res[i][j] = 1 + (i/2 + j/2) % 2;
                    else
                        res[i][j] = 3 + ((i+1)/2 + j/2) % 2;
                }
        }

        if (flip) swap(N, M);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j)
                printf("%d ", flip ? res[j][i] : res[i][j]);
            printf("\n");
        }
    }

    return 0;
}
