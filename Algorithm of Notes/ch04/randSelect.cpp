#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, A[100010];

int randPartition(int A[], int left, int right) {
	int p = ((1.0 * rand() / RAND_MAX * (right - left) + left));
	swap(A[p], A[left]);
	int temp = A[left];
	while (left < right) {
		while (left < right && A[right] > temp)
			right--;
		A[left] = A[right];
		while (left < right && A[left] < temp)
			left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

int randSelect(int A[], int left, int right, int K) {
	if (left == right)
		return A[left];
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if (K == M)
		return A[p];
	if (K < M)
		return randSelect(A, left, p - 1, K);
	else
		return randSelect(A, p + 1, right, K - M);
}

int main() {
	srand((unsigned)time(NULL));
	int n, sum = 0, sum1 = 0;
	if (scanf("%d", &n)) {};
	for (int i = 0; i < n; i++) {
		if (scanf("%d", & A[i])) {};
		sum += A[i];
	}
	randSelect(A, 0, n - 1, n / 2);
	for (int i = 0; i < n / 2; i++) {
		sum1 += A[i];
	}
	printf("%d\n", (sum - sum1) - sum1);
	return 0;
}