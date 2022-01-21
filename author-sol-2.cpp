#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		// a total of 10 tuples
		// for each tuple, we have (n - 2) options
		// for each tuple, we have 3 ^ (n - 3) ways to fill the remaining positions
		int ans = 10 * (n - 2) * pow(3, n - 3);
		cout << (n < 3 ? 0 : ans) << '\n';
	}
	return 0;
}
