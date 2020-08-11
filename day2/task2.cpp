#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int A;
    cin >> A;
    vector<int> dp(A + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < x; i++) {
        for (int j = A - 5; j >= 0; j--) {
            dp[j + 5] = min(dp[j + 5], dp[j] + 1);
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = A - 2; j >= 0; j--) {
            dp[j + 2] = min(dp[j + 2], dp[j] + 1);
        }
    }
    for (int i = 0; i < z; i++) {
        for (int j = A - 1; j >= 0; j--) {
            dp[j + 1] = min(dp[j + 1], dp[j] + 1);
        }
    }
    if (dp[A] == INF) {
        cout << "No";
    } else {
        cout << "Yes, with " << dp[A] << " coins";
    }
}
