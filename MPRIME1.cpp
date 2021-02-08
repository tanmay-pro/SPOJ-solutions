#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
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
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int MOD = 1e9 + 7;

void subsetSums(vl &arr, vl &sol, ll num)
{
    ll n = arr.size();
    long long total = 1 << n;
    for (long long i = 0; i < total; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
        }
        if (sum <= num)
        {
            sol.push_back(sum);
        }
    }
}

vl sieve(ll n)
{
    int is_composite[n + 5] = {0};
    is_composite[0] = is_composite[1] = 1;

    for (int i = 2; i * i <= n; i++)
        if (!is_composite[i])
            for (int j = i * i; j <= n; j += i)
                is_composite[j] = 1;

    vl primes;
    for (int i = 0; i <= n; i++)
        if (!is_composite[i])
            primes.push_back(i);
    return primes;
}

int main()
{
    amazing;
    ll t = 1;
    //cin >> t;
    while (true)
    {
        ll num;
        cin >> num;
        if (num == 0)
        {
            break;
        }
        else
        {
            vl primes;
            ll sum;
            primes = sieve(num);
            vl sol;
            ll cnt = 0;
            for (ll i = 0; primes[i] <= num; i++)
            {
                sum = primes[i];
                for (ll j = i + 1; sum < num; j++)
                    sum += primes[j];
                if (sum == num)
                    cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}