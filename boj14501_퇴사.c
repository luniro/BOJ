#include <stdio.h>

int N, T[15], P[15], s[15];
int max;

void input(void)
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
	for (i = N - 1; i >= 0; --i)
	{
		s[i] = s[i + 1] + P[i];
	}
}

void dfs(int d, int t)
{
	if (t + s[d] <= max) return;
	if (d >= N)
	{
		max = t;
		return;
	}

	if (d + T[d] <= N) dfs(d + T[d], t + P[d]);
	dfs(d + 1, t);
}

int main(void)
{
	input();
	dfs(0, 0);
	printf("%d\n", max);

	return 0;
}
