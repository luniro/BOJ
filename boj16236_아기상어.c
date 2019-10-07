#include <stdio.h>

typedef struct _point
{
	int y, x;
} P;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int N, a[22][22], v[22][22];
P Q[402];
int head, tail;
int now = 1 << 22;
int time;

P shark;

void input(void)
{
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		for (j = 1; j <= N; ++j)
		{
			scanf("%d", &a[i][j]);
			v[i][j] = now;
			if (a[i][j] == 9)
			{
				a[i][j] = 0;
				shark.y = i;
				shark.x = j;
			}
		}
	}
}

void operation(void)
{
	P c, n;
	int i, tmp;
	int size, cnt;
	int d;

	size = cnt = 2;

	while(1)
	{
		P target = {21, 21};
		d = 1<<10;

		now -= 1<<10;
		head = tail = 0;
		v[shark.y][shark.x] = now;
		Q[tail++] = shark;

		while (head != tail)
		{
			c = Q[head++];
			if ((v[c.y][c.x] & 0x1ff) >= d) break;

			tmp = v[c.y][c.x] + 1;
			for (i = 0; i < 4; ++i)
			{
				n.y = c.y + dy[i];
				n.x = c.x + dx[i];

				if (v[n.y][n.x] <= tmp) continue;
				if (a[n.y][n.x] > size) continue;
				if (a[n.y][n.x] && a[n.y][n.x] < size)
				{
					if (target.y > n.y || (target.y == n.y && target.x > n.x))
					{
						target.y = n.y;
						target.x = n.x;
						d = tmp & 0x1ff;
						v[n.y][n.x] = tmp;
					}
					continue;
				}
				if (target.y != 21) continue;
				v[n.y][n.x] = tmp;
				Q[tail++] = n;
			}
		}

		if (target.y == 21) return;
		shark = target;
		a[shark.y][shark.x] = 0;
		time += d;
		if (--cnt == 0)
		{
			size++;
			cnt = size;
		}
	}
}

int main(void)
{
	input();
	operation();
	printf("%d\n", time);

	return 0;
}
