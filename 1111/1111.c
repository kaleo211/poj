#include <stdio.h>

char map[20][21];
int visit[20][21];

int hight, wide;
int value;

void dfs(int i, int j) {
    int ii, jj;
    if (map[i][j]=='X' && visit[i][j]==0) {
        visit[i][j] = 1;

        for (ii=-1; ii<=1; ii++) {
            for (jj=-1; jj<=1; jj++) {
                if (!(ii==0&&jj==0)) {
                    if ( i+ii>=hight || i+ii<0 || j+jj>=wide || j+jj<0 || map[i+ii][j+jj]=='.') {
                        if ( i+ii>=hight && jj==0 )
                            value += 1;
                        if ( i+ii<0 && jj==0)
                            value += 1;
                        if ( j+jj>=wide && ii==0 )
                            value += 1;
                        if ( j+jj<0 && ii==0 )
                            value += 1;
                        if ((ii==0 || jj==0) && (i+ii<hight && i+ii>=0 && j+jj<wide && j+jj>=0) && map[i+ii][j+jj]=='.')
                            value += 1;

                    } else {
                        dfs(i+ii, j+jj);
                    }
                }
            }
        }
    }
}

int main() {
    int row, col, i, j;

    while (1) {

        scanf("%d %d %d %d", &hight, &wide, &row, &col);

        if (hight==0) break;

        for (i=0; i<hight; i++) {
            scanf("%s", map[i]);
        }

        for (i=0; i<hight; i++) {
            for (j=0; j<wide; j++)
                visit[i][j] = 0;
        }

        value = 0;
        dfs(row-1, col-1);
        printf("%d\n", value);

    }
}
