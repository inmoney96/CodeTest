#include <stdio.h>

int ans = 0;
int room[51][51] = {};
int y = 0, x = 0, l = 0;
int n = 0, m = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool isIn(int ny, int nx) {
	if (ny >= 0 && nx >= 0 && ny < n && nx < m) return true;
	return false;
	
}

void cleanRoom() {

	while (1)
	{
		if (room[y][x] == 0)
		{
			room[y][x] = 2;
			ans++;
		}

		bool dirtyNear = false;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isIn(ny, nx) && room[ny][nx] == 0)
			{
				dirtyNear = true;
			}
		}

		if (dirtyNear) //있을경우
		{
			while (1)
			{
				l--;
				if (l == -1) l = 3;
				int ny = y, nx = x;

				switch (l)
				{
				case 0:
					ny--;
					break;
				case 1:
					nx++;
					break;
				case 2:
					ny++;
					break;
				case 3:
					nx--;
					break;
				default:
					break;
				}
				if (room[ny][nx] == 0)
				{
					y = ny, x = nx;
					break;
				}
			}
			
		}
		else //없을경우
		{
			int ny = y, nx = x;

			switch (l)
			{
			case 0:
				ny++;
				break;
			case 1:
				nx--;
				break;
			case 2:
				ny--;
				break;
			case 3:
				nx++;
				break;
			default:
				break;
			}
			if (room[ny][nx] == 1)
			{
				return;
			}
			else
			{
				y = ny, x = nx;
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &y, &x, &l);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}

	cleanRoom();
	printf("%d", ans);

	return 0;
}