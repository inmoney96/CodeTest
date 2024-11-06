#include <iostream>
#include <stack>
using namespace std;


int main() {
	int n = 0;
	scanf("%d", &n);

	int tmp;
	stack<pair<int,int>> towers;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		if (!towers.empty() && towers.top().second > tmp)
		{
			printf("%d ", towers.top());
			towers.push({ i,tmp });
		}
		else
		{
			while (!towers.empty())
			{
				towers.pop();
				if (!towers.empty() && towers.top().second > tmp)
				{
					printf("%d ", towers.top());
					towers.push({ i,tmp });
					break;
				}
			}
			if (towers.empty())
			{
				printf("0 ");
				towers.push({ i,tmp });
			}
			
		}
	}


	return 0;
}