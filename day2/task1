#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;
const int MN = 20;
int tb[MN][MN];

bool isPostionTrue(int x, int j) {
    return ((1 << j) & x) > 0;
}

int main() {
    int n;
    cin >> n;
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tb[i][j];
        }
    }
    int dp[(1 << n)][n];
    int parent[(1 << n)][n];
    int MaxMask = (1 << n);
    for (int i = 0; i < MaxMask; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
            parent[i][j] = -1;
        }
    }
    dp[(1 << start)][start] = 0;
    for (int mask = 0; mask < MaxMask; mask++) {
        for (int curVertex = 0; curVertex < n; curVertex++) {
            for (int nextVertex = 0; nextVertex < n; nextVertex++) {
                if (isPostionTrue(mask, nextVertex) || nextVertex == curVertex)
                    continue;
                int nextMask = (mask | (1 << nextVertex));
                if (dp[nextMask][nextVertex] > dp[mask][curVertex] + tb[curVertex][nextVertex]) {
                    parent[nextMask][nextVertex] = curVertex;
                    dp[nextMask][nextVertex] = dp[mask][curVertex] + tb[curVertex][nextVertex];
                }
            }
        }
    }
    int mi = dp[MaxMask - 1][0], lastVertex = 0;
    for (int i = 1; i < n; i++) {
        if (mi > dp[MaxMask - 1][i] + tb[i][start]) {
            mi = dp[MaxMask - 1][i] + tb[i][start];
            lastVertex = i;
        }
    }
    cout << "Minimal path - " << mi << '\n';
    cout << "Path: ";
    vector<int> path;
    int mask = MaxMask - 1;
    for (int i = 0; i < n; i++) {
        path.emplace_back(lastVertex);
        mask = (mask) ^ (1 << lastVertex);
        lastVertex = parent[mask | (1 << lastVertex)][lastVertex];
    }
    reverse(path.begin(), path.end());
    path.emplace_back(start);
    for (auto i : path) {
        cout << i << ' ';
    }
}
