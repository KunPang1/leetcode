#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;

const int MAXN = 505;

void main() {
	int height[MAXN];
	char sex[MAXN], music[MAXN][101], sport[MAXN][101];
	int T;	// the number of test cases
	scanf("%d", &T);


	while (T--) {
		int N;
		scanf("%d", &N);

		int AdjArr[MAXN][MAXN];		//��ʼ�����Ӿ���


		int male = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %c %s %s", &height[i], &sex[i], music[i], sport[i]);
			if (sex[i] == 'M')
				male++;
		}

		int s = 0;
		int t = 1;
		for (int i = 0; i < N; i++) {
			if (sex[i] == 'M') {
				AdjArr[0][i + 2] = 1;
				AdjArr[i + 2][0] = 1;
				for (int j = 0; j < N; j++) {
					if (sex[i] == 'F') {
						AdjArr[1][i + 2] = 1;
						AdjArr[i + 2][1] = 1;
						if (abs(height[i] - height[j]) <= 40
							&& (strcmp(music[i], music[j]) == 0)
							&& (strcmp(sport[i], sport[j]) != 0)) {
							AdjArr[i + 2][j + 2] = 1;
							AdjArr[j + 2][i + 2] = 1;
						}
					}
				}
			}
		}
		//cout << "Finish building AdjArr." << endl;
	}

}