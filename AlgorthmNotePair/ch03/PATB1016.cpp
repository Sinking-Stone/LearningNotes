#include <iostream>
using namespace std;

int main() {
	int n1, n2, hh, mm, ss, temp;
	if (scanf("%d %d", &n1, &n2)) {};
	temp = (int)((n2 - n1) / 100.0 + 0.5);
	hh = temp / 3600;
	mm = (temp - hh * 3600) / 60;
	ss = temp % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
	return 0;
}