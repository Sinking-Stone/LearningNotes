#include <iostream>
using namespace std;

int main() {
	int n1, n2, n3, n4, num1 = 0, num2 = 0;
	if (scanf("%d %d %d %d", &n1, &n2, &n3, &n4)) {};
	while (n1) {
		if (n1 % 10 == n2)
			num1 = num1 * 10 + n2;
		n1 /= 10;
	}
	while (n3) {
		if (n3 % 10 == n4)
			num2 = num2 * 10 + n4;
		n3 /= 10;
	}
	printf("%d", num1 + num2);
	return 0;
}