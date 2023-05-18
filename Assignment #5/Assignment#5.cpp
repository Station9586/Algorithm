#include <bits/stdc++.h>
#define pb push_back
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL
#define eprintf(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef map<int, int> mi;

double START, END;

ll p[20010];
ll cnt;
int n = 110;

vector<vi> dp(n, vi(n, 0));
vector<vi> path(n, vi(n, 0));

void mcm (int a, int b, ll &mn, string &ans) { // recursive
    if (a == b) {
        ans += "A" + to_string(a);
        // ans += 'A' + a - 1;
        return;
    }
    ll cost = INF;
    string s = "";
    for (int i = a; i < b; i ++) {
        ll now = 0;
        string l = "", r = "";
        mcm(a, i, now, l);
        mcm(i + 1, b, now, r);
        now += mn + p[a - 1] * p[i] * p[b];
        if (now < cost) {
            cost = now;
            s = "(" + l + r + ")";
        }
    }
    mn = cost;
    ans += s;
}

void DynamicProgramming () { // dp
    for (int i = 1; i < n; i ++) dp[i][i] = 0;
    for (int l = 2; l < n; l ++) {
        for (int i = 1; i < n - l + 1; i ++) {
            int j = i + l - 1;
            dp[i][j] = INF;
            ll cost;
            for (int k = i; k < j; k ++) {
                cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    path[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum matrix-chain manipulations by DP: " << dp[1][n - 1] << "\n";
}

void print(int a, int b) { // backtracking
    if (a == b) {
        cout << "A" << a;
        // cout << (char)('A' + a - 1);
        return;
    }
    cout << "(";
    print(a, path[a][b]);
    print(path[a][b] + 1, b);
    cout << ")";
}

void solve () {
    ll mn = 0;
    string ans = "";
    START = clock();
    mcm(1, n - 1, mn, ans);
    END = clock();
    cout << "Minimum matrix-chain manipulations by Recursive: " << mn <<    "\n";
    cout << "Record by Recursive: " << ans << "\n";
    cout << "Time by Recursive: " << (END - START) / CLOCKS_PER_SEC << " s\n";
    START = clock();
    DynamicProgramming();
    END = clock();
    cout << "Record by DP: ";
    print(1, n - 1);
    cout << "\n";
    cout << "Time by DP: " << (END - START) / CLOCKS_PER_SEC << " s\n";
}

int main (int argc, const char* argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n; // Enter Test Case
    for (int i = 0; i < n; i ++) cin >> p[i];
    cout << "n: " << n << "\nMatrix: ";
    for (int i = 0; i < n; i ++) cout << p[i] << " ";
    cout << "\n";
    solve();
    // n = 100; // Random Test Case
    // while (n --) {
    // 	if (n == 2) break;
    // 	int num;
    // 	for (int i = 0; i < n; i ++) {
    // 		num = rand() % 20 + 1;
    // 		p[i] = num;
    // 	}
    // 	cout << "n: " << n << "\n";
    // 	solve();
    // 	cout << "\n";
    // }
    return 0;
}

