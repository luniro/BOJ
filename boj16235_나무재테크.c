#include <stdio.h>

int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int land[12][12], s2d2[12][12];
int tree[12][12][150];

int N, M, K;

void input(void)
{
	int i, j;
	int x, y, z;

	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			scanf("%d", &s2d2[i][j]);
			land[i][j] = 5;
		}
	}
	while (M--)
	{
		scanf("%d %d %d", &y, &x, &z);
		tree[y][x][z]++;
		if (tree[y][x][0] < z) tree[y][x][0] = z;
	}
}

void operation(void)
{
	int i, j;
	int tmp, k;
	int tmp_k;

	while (K--)
	{
		for (i = 1; i <= N; ++i)
		{
			for (j = 1; j <= N; ++j)
			{
				tmp_k = 0;
				for (k = 1; k <= tree[i][j][0]; ++k)
				{
					if (tree[i][j][k] == 0) continue;
					tmp = k * tree[i][j][k];
					if (land[i][j] < tmp)
					{
						tmp = land[i][j] / k;
						land[i][j] -= tmp * k;

						land[i][j] += (tree[i][j][k] - tmp) * (k >> 1);
						tree[i][j][k] = tmp;

						if (tmp > 0) tmp_k = k;
						while (++k <= tree[i][j][0])
						{
							land[i][j] += tree[i][j][k] * (k >> 1);
							tree[i][j][k] = 0;
						}

						break;
					}
					else
					{
						land[i][j] -= tmp;
						tmp_k = k;
					}
				}
				tree[i][j][0] = tmp_k + 1;
				k = tree[i][j][0];
				while (--k)
				{
					tree[i][j][k+1] = tree[i][j][k];
				}
				tree[i][j][1] = 0;
			}
		}

		for (i = 1; i <= N; ++i)
		{
			for (j = 1; j <= N; ++j)
			{
				land[i][j] += s2d2[i][j];

				tmp = 0;
				for (k = 5; k <= tree[i][j][0]; k += 5)
				{
					tmp += tree[i][j][k];
				}
				if (tmp == 0) continue;
				for (k = 0; k < 8; ++k)
				{
					tree[i+dy[k]][j+dx[k]][1] += tmp;
				}
			}
		}
	}
}

int cal(void)
{
	int i, j, k;
	int ret = 0;

	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			for (k = 1; k <= tree[i][j][0]; ++k)
			{
				ret += tree[i][j][k];
			}
		}
	}

	return ret;
}

int main(void)
{
	input();
	operation();
	printf("%d\n", cal());

	return 0;
}
