#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

int N;
int P[11];
int C[11];
int E[11][10];
int V;
int min = 1000;

void input(void)
{
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &P[i]);
	}
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &C[i]);
		for (j = 0; j < C[i]; ++j)
		{
			scanf("%d", &E[i][j]);
		}
	}
}

void dfs(int now, int G, int status)
{
	int i;

	V |= 1 << now;
	for (i = 0; i < C[now]; ++i)
	{
		if ((1 & (G >> E[now][i])) == status) continue;
		if ((V & (1 << E[now][i]))) continue;
		dfs(E[now][i], G, status);
	}
}

int sub(int G, int status)
{
	int i;

	for (i = 1; i <= N; ++i)
	{
		if ((1 & (G >> i)) == status) continue;
		dfs(i, G, status);
		return 0;
	}

	return 1;
}

int chk(int G)
{
	V = 0;
	if (sub(G, 0) || sub(G, 1)) return 0;
	return (V == (1 << (N + 1)) - 2);
}

void func(int L, int G, int a, int b)
{
	if (L > N)
	{
		if (min > abs(b - a) && chk(G)) min = abs(b - a);
		return;
	}

	func(L + 1, G, a + P[L], b);
	func(L + 1, G | (1 << L), a, b + P[L]);
}

int main(void)
{
	input();
	func(1, 0, 0, 0);
	printf("%d\n", min == 1000 ? -1 : min);

	return 0;
}
