//
// Created by SinkingStone on 2021/8/31.
// 会超时
//
#include <iostream>
#include <cstring>

using namespace std;
char str[100010];
int P[100010];
int A[100010];
int T[100010];

int main() {
    gets(str);
    int indexP = 0, indexA = 0, indexT = 0, num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'P') {
            P[indexP] = i;
            indexP++;
        }
        if (str[i] == 'A') {
            A[indexA] = i;
            indexA++;
        }
        if (str[i] == 'T') {
            T[indexT] = i;
            indexT++;
        }
    }
    for (int i = 0; i < indexP; i++) {
        for (int j = 0; j < indexA; j++) {
            for (int k = 0; k < indexT; k++) {
                if (P[i] < A[j] && A[j] < T[k]) num++;
            }
        }
    }
    printf("%d",num);
    return 0;
}
