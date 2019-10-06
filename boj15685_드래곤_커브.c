#include <stdio.h>

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int main(void)
{
	int N, Q[1024], a[101][101] = {0};
	int x, y, d, g, i, j = 0;

	while (j < 1023)
	{
		Q[j++] = 1;
		for (i = j - 2; i >= 0; --i)
		{
			Q[j++] = -Q[i];
		}
	}

	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);

		j = 1 << g;
		a[y][x] = 1;
		for (i = 0; i < j; ++i)
		{
			y += dy[d];
			x += dx[d];
			a[y][x] = 1;
			d = (d + 4 + Q[i]) & 3;
		}
	}

	N++;
	i = 100;
	while (i--)
	{
		j = 100;
		while (j--)
		{
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) N++;
		}
	}
	printf("%d\n", N);

	return 0;
}
