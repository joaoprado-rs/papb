#include <iostream>
using namespace std;
const int MAXN = 1000;
const int MAXP = 100;
const int MAXW = 30;

int P[MAXN];
int W[MAXN];
int MW[MAXP];

int dp[2][MAXW + 1];

int main() {
    int T, N, G;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> P[j] >> W[j];
        }
        cin >> G;
        for (int k = 0; k < G; k++) {
            cin >> MW[k];
        }

     int count = 0;

        for (int k = 0; k < G; k++) {
            int prev = 0, act = 1;
            for (int c = 0; c <= MW[k]; c++) {
                dp[prev][c] = 0;
            }

            for (int n = N - 1; n >= 0; n--) {
                for (int c = 0; c <= MW[k]; c++) {
                    dp[act][c] = dp[prev][c];
                    if (W[n] <= c) {
                        dp[act][c] = max(dp[act][c], dp[prev][c - W[n]] + P[n]);
                    }
                }
                swap(act, prev);
            }
            count += dp[prev][MW[k]];
        }

        cout << count << endl;
    }
    return 0;
}