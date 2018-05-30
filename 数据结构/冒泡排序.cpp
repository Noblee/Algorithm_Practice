#include <iostream>
#include <algorithm>

using namespace std;

void bubble(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main() {
    int a[] = {5, 6, 2123, 23, 3434, 2312, 123, 1233};
    bubble(a, 8);
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
    }
}