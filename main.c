#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n, m, k, q, p;
    scanf("%d %d %d %d %d", &n, &m, &k, &q, &p);

    int i[m], j[m], c[m];
    int r[m][k];
    int v[q];
    int qt[q][k];

    for (int temp = 0; temp < m; temp++) {
        scanf("%d %d %d", &i[temp], &j[temp], &c[temp]);

        for (int t = 0; t < k; t++)
            scanf("%d", &r[temp][t]);
    }

    for (int temp = 0; temp < q; temp++) {
        scanf("%d", &v[temp]);

        for (int t = 0; t < k; t++)
            scanf("%d", &qt[temp][t]);
    }

    // Início do algoritmo
    printf("max : ");
    for (int temp = 0; temp < m; temp++)
        if (i[temp] == 1) {
            printf("%dcarga%d%d + ", p, i[temp], j[temp]);
        }
    printf("0 - ");
    for (int temp = 0; temp < q; temp++)
        printf("%dx%d - ", v[temp], temp + 1);
    printf("0;\n\n");

    for (int temp1 = 0; temp1 < m; temp1++) {
        printf("a%d%d - b%d%d = carga%d%d;\n", i[temp1], j[temp1], i[temp1], j[temp1], i[temp1], j[temp1]);
    }

    for (int temp = 0; temp < m; temp++) {
        printf("%d <= carga%d%d <= %d;\n", -c[temp], i[temp], j[temp], c[temp]);
    }

    for (int temp1 = 1; temp1 <= n; temp1++) {
        if (temp1 == n)
            break;

        int alvo = temp1;

        int segunda = 0;
        int primeira = 0;
        for (int temp2 = 0; temp2 < m; temp2++) {
            if (i[temp2] == alvo) {
                segunda = 1;
            }
            if (j[temp2] == alvo) {
                primeira = 1;
            }
        }

        if (segunda && primeira) {
            for (int temp2 = 0; temp2 < m; temp2++) {
                if (j[temp2] == alvo)
                    printf("carga%d%d + ", i[temp2], j[temp2]);
            }
            printf("0 = ");
            for (int temp2 = 0; temp2 < m; temp2++) {
                if (i[temp2] == alvo) {
                    printf("carga%d%d + ", i[temp2], j[temp2]);
                }
            }
            printf("0;\n");
        }

        if (segunda && !primeira && alvo != 1) {
            printf("0 = ");
            for (int temp2 = 0; temp2 < m; temp2++) {
                if (i[temp2] == alvo) {
                    printf("carga%d%d + ", i[temp2], j[temp2]);
                }
            }
            printf("0;\n");
        }

        if (!segunda && primeira) {
            for (int temp2 = 0; temp2 < m; temp2++) {
                if (j[temp2] == alvo)
                    printf("carga%d%d + ", i[temp2], j[temp2]);
            }
            printf("0 = 0;\n");
        }
    }

    for (int temp1 = 0; temp1 < k; temp1++) {
        for (int temp2 = 0; temp2 < q; temp2++) {
            printf("%dx%d + ", qt[temp2][temp1], temp2 + 1);
        }
        printf("0 >= ");

        int rk = 0;
        for (int temp2 = 0; temp2 < m; temp2++) {
            printf("%da%d%d + ", r[rk][temp1], i[temp2], j[temp2]);
            printf("%db%d%d + ", r[rk][temp1], i[temp2], j[temp2]);
            rk++;
        }

        printf("0;\n");
    }

    for (int temp1 = 0; temp1 < q; temp1++) {
        printf("x%d >= 0;\n", temp1 + 1);
    }

    for (int temp1 = 1; temp1 <= n; temp1++) {
        for (int temp2 = 0; temp2 < m; temp2++) {
            if (i[temp2] == temp1) {
                printf("a%d%d >= 0;\n", i[temp2], j[temp2]);
                printf("b%d%d >= 0;\n", i[temp2], j[temp2]);
            }
        }
    }

    return 0;
}