#include <iostream>
using namespace std;

int main() {
	int num = 0;
	int a[5] = {0}, flag[5] = {0};
	if (scanf("%d", &num)) {};
	int ans[num];
	for (int i = 0; i < num; i++) {
		if (scanf("%d", &ans[i])) {};
		if (ans[i] % 10 == 0) {
			a[0] += ans[i];
			flag[0]++;
		}
		if (ans[i] % 5 == 1) {
			if (flag[1] % 2 == 0)
				a[1] += ans[i];
			else
				a[1] -= ans[i];
			flag[1]++;
		}
		if (ans[i] % 5 == 2) {
			a[2]++;
			flag[2]++;
		}
		if (ans[i] % 5 == 3) {
			a[3] += ans[i];
			flag[3]++;
		}
		if (ans[i] % 5 == 4 && ans[i] > a[4]) {
			a[4] = ans[i];
			flag[4]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (flag[i] == 0 && i != 4)
			printf("N ");
		else if (flag[i] == 0 && i == 4)
			printf("N");
		else if (i == 3)
			printf("%.1lf ", a[i] * 1.0 / flag[3] );
		else if (flag[i] != 0 && i != 4)
			printf("%d ", a[i]);
		else if (flag[i] != 0 && i == 4)
			printf("%d", a[i]);
	}

	return 0;
}