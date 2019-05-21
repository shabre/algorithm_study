#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v;
	v.resize(n + 1);

	for (int i = 0; i < n; i++) {	// ���� �ʱ�ȭ
		for (int j = 0; j < n; j++) {
			if (i == j) {
				v[i].push_back(0);
			}
			v[i].push_back(MAX);
		}
	}
	
	while (m--) { // �Է¹������ ���� �׷��� �׸���
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v[t1 - 1][t2 - 1] = 1;
		v[t2 - 1][t1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == MAX) printf("INF ", v[i][j]);
			else printf("%3d ", v[i][j]);
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) { // �÷��̵�-���� �˰��� ����. �ð����⵵�� O(n^3)�ε� n <= 100�� 2�� �ȿ� ����Ǹ� �Ǳ� ������ ok
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v[k][j] > v[k][i] + v[i][j]) {
					v[k][j] = v[k][i] + v[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == MAX) printf("INF ", v[i][j]);
			else printf("%3d ", v[i][j]);
		}
		cout << '\n';
	}

	int min = MAX, ans = 0;
	for (int i = n-1; i >= 0; i--) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			s += v[i][j];
		}
		if (min >= s) {
			min = s;
			ans = i;
		}
	}
	printf("%d", ans+1); // �ε����� �� �Ŷ� +1 ����� �ùٸ� ��ȣ ���

	cin >> n;
}