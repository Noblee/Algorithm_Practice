#include <iostream>
#include <map>
#include <string>

using namespace std;
struct node {
    int f, r;
};

int main() {
    int a[10000] = {0};
    while (1) {
        int f, r, v;
        cin >> f >> r >> v;
        if (f == 0)
            break;
        for (int i = f; i <= r; i++)
            a[i] = v;
    }
    int f;
    f = 1;
    for (int r = 2; r < 10000; r++) {
        if (a[r] == a[f])
            continue;
        else {
            static int az = 0;
            if (az == 0) {
                printf("[%d, %d, %d]", f, r - 1, a[f]);
                az = 1;
            } else {

                printf(", [%d, %d, %d]", f, r - 1, a[f]);
            }
            f = r;
        }
    }
    return 0;
}
