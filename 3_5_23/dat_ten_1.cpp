#include <bits/stdc++.h>
using namespace std;
int x[100], n, k;
vector<string> strName;
void solution()
{
    for (int i = 1; i < k + 1; i++)
    {
        cout << strName.at(x[i] - 1) << " ";
    }
    cout << endl;
}
void Try(int i)
{
    for (int v = x[i - 1] + 1; v <= n - k + i; v++)
    {
        x[i] = v;
        if (i == k)
            solution();
        else
        {
            Try(i + 1);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    string name[n];

    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    set<string> setName(name, name + sizeof(name) / sizeof(name[0]));

    for (string str : setName)
        strName.push_back(str);

    n = strName.size();
    x[0] = 0;
    Try(1);
}