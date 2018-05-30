#include<bits/stdc++.h>

using namespace std;
vector<int> data;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        int temp, a, b;
        cin >> temp >> a >> b;
        int sum = 0;
        int maxx = 0;
        switch (temp) {
            case 1:
                data[a - 1] = b;
                break;
            case 2:
                for (int i = a - 1; i < b; i++)
                    sum += data[i];
                cout << sum << endl;
                break;
            case 3:
                for (int i = a - 1; i < b; i++)
                    maxx = max(maxx, data[i]);
                cout << maxx << endl;
                break;
        }
    }
}