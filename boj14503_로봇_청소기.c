#include <stdio.h>

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M, r, c, d;
char a[50][50];
int cnt = 1;

void input(void)
{
	int i, j;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < M; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

void oper(void)
{
	int i, nr, nc;

	while (1)
	{
		a[r][c] = -1;

		for (i = 0; i < 4; ++i)
		{
			d = (d + 3) % 4;
			nr = r + dr[d];
			nc = c + dc[d];

			if (!a[nr][nc])
			{
				r = nr;
				c = nc;
				cnt++;
				break;
			}
			else
			{
				continue;
			}
		}

		if (i == 4)
		{
			r -= dr[d];
			c -= dc[d];

			if (a[r][c] == -1) continue;
			else break;
		}
	}
}

int main(void)
{
	input();
	oper();
	printf("%d\n", cnt);

	return 0;
}
