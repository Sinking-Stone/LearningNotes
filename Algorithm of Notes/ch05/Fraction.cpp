#include <stdio.h>
#include <math.h>

struct Fraction {
	int up, down;
};

// 最小公因数
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// 分数的化简
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.down = -result.down;
		result.up = -result.up;
	}
	if (result.up == 0)
		result.down = 1;
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}

// 分数之间的加法
Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

// 分数之间的减法
Fraction minu(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

// 分数之间的乘法
Fraction multi(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

// 分数之间的除法
Fraction divide(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

// 分数之间的输出
void showResult(Fraction r) {
	r = reduction(r);
	if (r.down == 1)
		printf("%lld", r.up);
	else if (abs(r.up) > r.down)
		printf("%d %d/%d", r.up / r.down, abs(r.up) % r.down, r.down);
	else
		printf("%d/%d", r.up, r.down);
}

int main() {
	Fraction ans;
	ans.up = 32;
	ans.down = 34;
	showResult(ans);
}