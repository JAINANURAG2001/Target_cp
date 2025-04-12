// find the subarray with maximum sum and all distinct elements

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int ans = INT_MIN;
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        mp[v[i]]++;
        sum += v[i];
    }

    if (mp.size() == k)
    {
        ans = max(ans, sum);
    }

    for (int i = k; i < n; i++)
    {

        mp[v[i]]++;
        sum += v[i];
        sum -= v[i - k];
        mp[v[i - k]]--;

        if (mp[v[i - k]] == 0)
            mp.erase(v[i - k]);

        if (mp.size() == k)
        {
            ans = max(ans, sum);
        }
    }

    if (ans == INT_MIN)
    {
        cout << "Not possibe" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}