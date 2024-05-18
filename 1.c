#include<Stdio.h>
#include<stdlib.h>
#define x 10
#define y 100

int test = 0;

float euclid(int m, int n) {
    int r;
    float count = 0;
    while (n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    return count;
}

float consec(int m, int n) {
    int min;
    float count = 0;
    min = m;
}
int main() {
    return 0;
}