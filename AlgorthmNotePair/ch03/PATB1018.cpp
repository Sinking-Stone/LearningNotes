#include <iostream>
using namespace std;

int main() {
	int num = 0;
	int A[3] = {0}, B[3] = {0};
//	0-”Æ£¨1-∆Ω£¨2- ‰
	int AU[3] = {0}, BU[3] = {0};
//	0-J”Æ£¨1-C”Æ£¨2-B”Æ
	if (scanf("%d", &num)) {};
	char ans[num][2];
	for (int i = 0; i < num; i++) {
		if (scanf("%c %c", &ans[i][0], &ans[i][1])) {};
		if (ans[i][0] == 'C' && ans[i][1] == 'J') {
			A[0]++;
			B[2]++;
			AU[1]++;
		}
		if (ans[i][0] == 'J' && ans[i][1] == 'B') {
			A[0]++;
			B[2]++;
			AU[0]++;
		}
		if (ans[i][0] == 'B' && ans[i][1] == 'C') {
			A[0]++;
			B[2]++;
			AU[2]++;
		}
		if (ans[i][1] == 'C' && ans[i][0] == 'J') {
			B[0]++;
			A[2]++;
			BU[1]++;
		}
		if (ans[i][1] == 'J' && ans[i][0] == 'B') {
			B[0]++;
			A[2]++;
			BU[0]++;
		}
		if (ans[i][1] == 'B' && ans[i][0] == 'C') {
			B[0]++;
			A[2]++;
			BU[2]++;
		}
		if (ans[i][1] == 'B' && ans[i][0] == 'B') {
			B[1]++;
			A[1]++;
		}
		if (ans[i][1] == 'C' && ans[i][0] == 'C') {
			B[1]++;
			A[1]++;
		}
		if (ans[i][1] == 'J' && ans[i][0] == 'J') {
			B[1]++;
			A[1]++;
		}
	}
	int Amax = -1, Bmax = -1, Ain = 0, Bin = 0;
	for (int i = 0; i < 3; i++) {
		if (AU[i] >= Amax)
			Amax = AU[i], Ain = i;
		if (BU[i] >= Bmax)
			Bmax = BU[i], Bin = i;
	}
	printf("%d %d %d\n", A[0], A[1], A[2]);
	printf("%d %d %d\n", B[0], B[1], B[2]);
	if (Ain == 0)
		printf("J ");
	else if (Ain == 1)
		printf("C ");
	else
		printf("B ");
	if (Bin == 0)
		printf("J");
	else if (Bin == 1)
		printf("C");
	else
		printf("B");
	return 0;
}