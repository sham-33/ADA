#include<stdio.h>
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
    if (n < min) 
        min = n;
    while (1) {
        count++;
        if (m % min == 0) {
            count++;
            if (n % min == 0)
                break;
            min -= 1;
        } else
            min -= 1;
    }

    return count;
}

float modified(int m,int n) { 
    int temp; 
    float count = 0; 
    while (n > 0) { 
        if (n > m) { 
            temp = m;
            m = n;
            n = temp; 
        } 
    m = m - n; 
    count += 1; 
    } 
 
    return count;  
} 

void analysis(int choice) {
    int m, n, i, j, k;
    float count, maxcount, mincount;
    FILE *fp1, *fp2;

    for (i = x; i < y; i += 10) {
        maxcount = 0;
        mincount = 10000;
        for (j = 2; j <= i; j++) {
            for (k = 2; k <= i; k++) {
                count = 0;
                m = j;
                n = k;
                switch (choice) {
                    case 1:
                        count = euclid(m, n);
                        break;
                    case 2:
                        count = consec(m, n);
                        break;
                    case 3:
                        count = modified(m, n);
                        break;
                }

                if (count > maxcount) 
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }
        switch (choice) {
            case 1:
                fp2 = fopen("e_b.txt", "a");
                fp1 = fopen("e_w.txt", "a");
                break;
            case 2:
                fp2 = fopen("c_b.txt", "a");
                fp1 = fopen("c_w.txt", "a");
                break;
            case 3:
                fp2 = fopen("m_b.txt", "a");
                fp1 = fopen("m_w.txt", "a");
                break;
        }
        fprintf(fp2, "%d %.2f\n",i ,mincount);
        fclose(fp2);
        fprintf(fp1, "%d %.2f\n",i, maxcount); 
        fclose(fp1); 
    }
}

int main() {
    int choice, m, n;
    printf("GCD\n");
    printf("1. Euclid's method.\n");
    printf("2. Consecutive subtraction method.\n");
    printf("3. Modified Euclid's method.\n");
    printf("0. Exit\n");
    do {
        printf("\nEnter your choice from the menu: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
                analysis(choice); 
            default:
                break;
        }
    } while (choice != 0);
}