//
// Created by Noble on 23/01/2018.
//
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

template<typename T>
void merge(vector<T> &v, int lo, int mid, int hi) {
    /* A为待排序指针，B为新建栈是前半部分序列的buff,
     * C为后半部分的指针
     * 整体过程就是对B进行遍历，
     * B和C中的元素比较，
     * 谁小谁放到A中，并令指向他的指针后移
     * B先耗尽，就直接结束
     * C先耗尽，后把B全部都放到末尾*/
    T *A = &v[lo], *C = &v[mid];
    int C_num = hi - mid, B_num = mid - lo;
    vector<T> B;
    for (int i = lo; i < mid; i++)
        B.push_back(v[i]);
    for (int i = 0, j = 0, k = 0; i < B_num;) {
        if ((j < C_num) && (B[i] > C[j]))
            A[k++] = C[j++];
        if (j == C_num || B[i] <= C[j])//
            // 这里右边去等号是为了保证稳定排序
            A[k++] = B[i++];
    }
    return;
}

void MergeSort(vector<int> &v, int low, int high) {
    if (high - low < 2) return;
    int mid = (low + high) / 2;
    MergeSort(v, low, mid);
    MergeSort(v, mid, high);
    merge(v, low, mid, high);
}
int main() {
    srand(time(NULL));
    vector<int> v;
    for(int i=0;i<1000;i++)
        v.push_back(rand()%10000);
    MergeSort(v,0,v.size());
    for(int i=0;i<1000;i++)
        cout << v[i]<<endl;
    return 0;
}