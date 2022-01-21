#include <bits/stdc++.h>

using namespace std;

int cnt;

void CombinationRepetitionUtil(int chosen[], int arr[], int index, int r, int start, int end) {
	if (index == r) {
		vector<int> vec;
		for (int i = 0; i < r; i++) {
			vec.push_back(arr[chosen[i]]);
		}
		// produce the permutation of the current sequence formed
		do {
			for (int i = 1; i < (int) vec.size() - 1; i++) {
				// count the no. of peaks in the current sequence whether:
				// (A[i] > A[i - 1] && A[i] > A[i + 1]) or (A[i] < A[i - 1] && A[i] < A[i + 1])
				if ((vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) || (vec[i] < vec[i - 1] && vec[i] < vec[i + 1])) {
					cnt++;
				}
			}
		} while (next_permutation(vec.begin(), vec.end()));
		return;
	}
	for (int i = start; i <= end; i++) {
		chosen[index] = i;
		CombinationRepetitionUtil(chosen, arr, index + 1, r, i, end);
	}
	return;
}

void CombinationRepetition(int arr[], int n, int r) {
	int chosen[r + 1];
	CombinationRepetitionUtil(chosen, arr, 0, r, 0, n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int arr[] = {0, 1, 2};
		cnt = 0;
		// generate all the possible combinations of {0, 1, 2} with repetition
		CombinationRepetition(arr, 3, n);
		cout << cnt << '\n';
	}
	return 0;
}
