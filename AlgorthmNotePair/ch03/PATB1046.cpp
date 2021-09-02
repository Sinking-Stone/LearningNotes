#include <iostream>
using namespace std;

int main() {
	int num, n1 = 0, n2 = 0;
	if (scanf("%d", &num)) {};
	int ans[num][5];
	for (int i = 0; i < num; i++) {
		if (scanf("%d %d %d %d", &ans[i][0], &ans[i][1], &ans[i][2], &ans[i][3])) {};
		ans[i][4] = ans[i][0] + ans[i][2];
		if (ans[i][4] == ans[i][1] && ans[i][4] != ans[i][3])
			n2++;
		if (ans[i][4] == ans[i][3] && ans[i][4] != ans[i][1])
			n1++;
	}
	printf("%d %d", n1, n2);
	return 0;
}