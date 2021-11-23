#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	// impossible to reach since we can't enter the train station
	if (a[0] == 0) {
		cout << "NO" << '\n';
		return 0;
	}
	if (a[s - 1] == 1) {
		// it is possible to reach using the first track
		cout << "YES" << '\n';
		return 0;
	} else if (b[s - 1] == 0) {
		// since the previous condition failed, we need to check
		// if it's possible in the second track
		cout << "NO" << '\n';
		return 0;
	}
	// start at station (s - 1) and check if it's possible to switch
	// tracks and then go backwards to the (s - 1)-th station
	// (the train station that should be switched must be greater than
	// or equal to (s - 1) since we are going backwards)
	int flag = 0;
	for (int i = s - 1; i < n; i++) {
		if (a[i] == 1 && b[i] == 1) {
			flag = 1;
		}
	}
	cout << (flag == 1 ? "YES" : "NO") << '\n';
	return 0;
}
