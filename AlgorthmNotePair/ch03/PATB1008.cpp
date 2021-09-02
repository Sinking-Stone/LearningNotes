#include <iostream>
using namespace std;

int main() {
	int num, move;
	if (scanf("%d %d", &num, &move)) {};
	int ans[num];
	move = move % num;
	for (int i = 0; i < num; i++)
		if (scanf("%d", &ans[i])) {};
	for (int i = 0; i < num; i++) {
		if (i == num - 1)
			printf("%d", ans[(i + num - move) % num]);
		else
			printf("%d ", ans[(i + num - move) % num]);
	}
	return 0;
}