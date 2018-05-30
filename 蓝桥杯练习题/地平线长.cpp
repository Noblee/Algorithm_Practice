#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
const int maxn = 1e3 + 10;
const double eps = 1e-7;
using namespace std;
/*
很容易想到离散化，将三角形三个点的横坐标以及没两条斜边所在的直线的交点记录下来，然后去重，求出所有x与所有
线段（不是直线）相交的最大值（纵坐标），然后求相邻两个点的距离之和即可，注意去除两个三角形相隔的部分还有不
满足条件的点*/
struct line {
    double a, b, c;
    double sx, ex;
    line() {}
    line(double a, double b, double c, double sx, double ex) :
            a(a), b(b), c(c), sx(sx), ex(ex) {}
} lne[maxn];
double x[maxn * 100], y[maxn * 100];
int numl, numx, numy;
int n, kase = 1;

double pointx(line A, line B) {
    double det1 = A.a * B.b - A.b * B.a;
    double det2 = A.c * B.b - A.b * B.c;
    return det2 / det1;
}

double pointy(double xx) {
    double sy = -1.0;
    for(int i = 0; i < numl; i++) {
        if(xx < lne[i].sx - eps) continue;
        if(xx > lne[i].ex + eps) continue;
        sy = max(sy, (lne[i].c - lne[i].a * xx) / lne[i].b);
    }
    return sy;
}

int main() {
    scanf("%d", &n);
    numl = numx = 0;
    double X, H, W;
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &X, &H, &W);
        double sx1 = X + W / 2, k;
        double sx2 = X - W / 2, b;
        x[numx++] = sx1; x[numx++] = sx2;
        k = H / (X - sx1); b = -k * sx1;
        lne[numl++] = line(k, -1, -b, X, sx1);
        k = H / (X - sx2); b = -k * sx2;
        lne[numl++] = line(k, -1, -b, sx2, X);
    }
    for(int i = 0; i < numl; i++) {
        for(int j = i + 1; j < numl; j++) {
            if(fabs(lne[i].a - lne[j].a) < eps && fabs(lne[i].b - lne[j].b) < eps) continue;
            x[numx++] = pointx(lne[i], lne[j]);
        }
    }
    sort(x, x + numx);
    int num = unique(x, x + numx) - x;
    for(int i = 0; i < num; i++) {
        y[i] = pointy(x[i]);
    }
    double ans = 0;
    for(int i = 0; i < num - 1; i++) {
        if(y[i] < -eps || y[i + 1] < -eps) continue;
        if(fabs(y[i]) < eps && fabs(y[i + 1] - y[i]) < eps) continue;
        double dx = (x[i + 1] - x[i]) * (x[i + 1] - x[i]);
        double dy = (y[i + 1] - y[i]) * (y[i + 1] - y[i]);
        ans += sqrt(dx + dy);
    }
    printf("%.0f",ans);
    return 0;
}