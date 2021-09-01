#include <iostream>
#include <cmath>
using namespace std;
int num = 0, flag = 1;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(1.0 * n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int start, end;
	if (scanf("%d%d", &start, &end)) {};
	for (int i = 2; num < end; i++) {
		if (isPrime(i)) {
			num++;
			if (num >= start && flag % 10 == 1) {
				if (flag == 1)
					flag++;
				else {
					printf("%d\n", i);
					flag++;
					continue;
				}
			}
			if (num >= start && flag % 10 != 1) {
				if (num == end )
					printf("%d", i);
				else {
					printf("%d ", i);
					flag++;
				}
			}
		}
	}
	return 0;
}