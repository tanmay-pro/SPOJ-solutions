#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define n 1000002
int MOD = 1e9 + 7;

ll phi[n + 2];

void ETF()
{
    for (int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= n; j += i)
            {
                phi[j] = (phi[j] * (i - 1)) / i;
            }
        }
    }
}

ll LcmSum(int m)
{
    ETF();
    ll ans[n+2];
    fo(i, n+2)
    {
        ans[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            ans[j] += (i * phi[i]);
        }
    }

    ll answer = ans[m];
    answer = (answer + 1) * m;
    answer = answer / 2;
    return answer;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        cout << LcmSum(a);
        br;
    }
    return 0;
}