#include <stdio.h>
#include <math.h>

int prosteChyslo(int n) {
    int d;
    if (n < 2) {
        return 0;
    }
    for (d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            return 0;
        }
    }
    return 1;
}

void task18() {
    int i;
    printf("завдання 18\n");
    for (i = 2; i <= 20; i++) {
        printf("sin(%d) = %.4f\n", i, sin(i));
    }
}

void task34() {
    int n, i;
    double x, p, s;
    printf("завдання 34\n");
    printf("n = ");
    scanf("%d", &n);
    printf("x = ");
    scanf("%lf", &x);
    if (n <= 0) {
        printf("n має бути натуральним\n");
        return;
    }
    p = 1;
    s = 0;
    for (i = 1; i <= n; i++) {
        p = p * x;
        s = s + sin(p);
    }
    printf("відповідь: %.4f\n", s);
}

void task83() {
    double m, max;
    int i;
    printf("завдання 83\n");
    printf("маса 1: ");
    scanf("%lf", &max);
    for (i = 2; i <= 12; i++) {
        printf("маса %d: ", i);
        scanf("%lf", &m);
        if (m > max) {
            max = m;
        }
    }
    printf("найважчий предмет: %.4f\n", max);
}

void task90() {
    double a, s;
    int i;
    printf("завдання 90\n");
    s = 0;
    for (i = 1; i <= 10; i++) {
        printf("a%d = ", i);
        scanf("%lf", &a);
        s = s + a;
    }
    printf("середнє арифметичне: %.4f\n", s / 10);
}

void task109() {
    int x, v, vse = 1;
    printf("завдання 109\n");
    for (x = 0; x <= 15; x++) {
        v = x * x + x + 17;
        if (prosteChyslo(v) == 1) {
            printf("x=%d  %d - просте\n", x, v);
        } else {
            printf("x=%d  %d - не просте\n", x, v);
            vse = 0;
        }
    }
    if (vse == 1) {
        printf("твердження вірне: усі числа прості\n");
    } else {
        printf("твердження невірне\n");
    }
}

void task145() {
    int n, i, j, k, znaishli, vse = 1;
    printf("завдання 145\n");
    for (n = 6; n <= 100; n++) {
        znaishli = 0;
        for (i = 2; i <= n && znaishli == 0; i++) {
            for (j = i; j <= n && znaishli == 0; j++) {
                k = n - i - j;
                if (k >= j && prosteChyslo(i) && prosteChyslo(j) && prosteChyslo(k)) {
                    znaishli = 1;
                }
            }
        }
        if (znaishli == 0) {
            printf("число %d не розкладається на 3 простих\n", n);
            vse = 0;
        }
    }
    if (vse == 1) {
        printf("для всіх чисел від 6 до 100 твердження виконується\n");
    }
}

void task146() {
    int n, i, znaishli, vse = 1;
    printf("завдання 146\n");
    for (n = 52; n <= 200; n = n + 2) {
        znaishli = 0;
        for (i = 2; i <= n / 2 && znaishli == 0; i++) {
            if (prosteChyslo(i) && prosteChyslo(n - i)) {
                znaishli = 1;
            }
        }
        if (znaishli == 0) {
            printf("парне число %d не є сумою двох простих\n", n);
            vse = 0;
        }
    }
    if (vse == 1) {
        printf("для всіх парних чисел від 52 до 200 гіпотеза виконується\n");
    }
}

void task207() {
    double eps, a, s, t;
    int n, k;
    printf("завдання 207\n");
    printf("eps = ");
    scanf("%lf", &eps);
    if (eps <= 0) {
        printf("eps має бути більше 0\n");
        return;
    }
    s = 0;
    n = 1;
    while (1) {
        t = 1;
        for (k = 1; k <= n; k++) {
            t = t * k / n;
        }
        a = t / 3;
        if (fabs(a) < eps) {
            break;
        }
        s = s + a;
        n++;
    }
    printf("сума членів ряду: %.4f (взято членів: %d)\n", s, n - 1);
}

void task242() {
    double a, b, h, x, y;
    int n, i;
    printf("завдання 242\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("h = ");
    scanf("%lf", &h);
    if (h <= 0 || a > b) {
        printf("потрібно h > 0 і a <= b\n");
        return;
    }
    n = (int)((b - a) / h + 0.0000001);
    printf("   x      F(x)\n");
    for (i = 0; i <= n; i++) {
        x = a + i * h;
        y = x * x * sin(x) * sin(x) + 1;
        printf("%7.4f  %.4f\n", x, y);
    }
}

void task251() {
    double a = 0.2, b = 4, c = -3, x, y;
    int d;
    printf("завдання 251\n");
    x = 1;
    y = a * x * x + b * x + c;
    printf("x = %.0f  y = %.4f\n", x, y);
    for (d = 1; d <= 6; d++) {
        x = x + d;
        y = a * x * x + b * x + c;
        printf("x = %.0f  y = %.4f\n", x, y);
    }
}

int main() {
    task18();
    task34();
    task83();
    task90();
    task109();
    task145();
    task146();
    task207();
    task242();
    task251();
    return 0;
}
