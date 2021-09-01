//
// Created by SinkingStone on 2021/8/31.
//
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp1(int a, int b) {
	return a > b;
}

bool cmp2(int a, int b) {
	return a < b;
}

int num1(int n) {
	int a[4];
	a[0] = n / 1000;
	a[1] = n / 100 % 10;
	a[2] = n / 10 % 10;
	a[3] = n % 10;
	sort(a, a + 4, cmp1);
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int num2(int n) {
	int a[4];
	a[0] = n / 1000;
	a[1] = n / 100 % 10;
	a[2] = n / 10 % 10;
	a[3] = n % 10;
	sort(a, a + 4, cmp2);
	return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int main() {
	int num;
	if (scanf("%d", &num)) {};
	int n1 = num1(num);
	int n2 = num2(num);
	int ans = 0;
	if (n1 == n2) {
		printf("%04d - %04d = 0000", n1, n2);
		return 0;
	}
	while (ans != 6174) {
		ans = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, ans);
		n1 = num1(ans);
		n2 = num2(ans);
	}
}
