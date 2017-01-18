#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef int (*COMPARE_FUNC)(int, int);

int compare(COMPARE_FUNC, int a, int b);
int compare1(int a, int b);
int compare2(int aa, int bb);

/**
 * C 函数指针 (函数回调)
 */
int main(void) {
    int ZhangSan = 30;
    int LiSi = 59;

    int diff1 = compare(compare1, ZhangSan, LiSi);
    printf("diff1:%d\n", diff1);

    int diff2 = compare(compare2, ZhangSan, LiSi);
    printf("diff2:%d\n", diff2);

    return EXIT_SUCCESS;
}

/**
 * 计算分差
 * @param compare_func
 * @param a
 * @param b
 * @return
 */
int compare(COMPARE_FUNC compare_func, int a, int b) {
    return (int) compare_func(a, b);
}

/**
 * 正常分差
 * @param a
 * @param b
 * @return
 */
int compare1(int a, int b) {
    if (a > b) {
        return a - b;
    } else if (a < b) {
        return b - a;
    }
    return 0;
}

/**
 * 全班挂科分差
 * @param aa
 * @param bb
 * @return
 */
int compare2(int aa, int bb) {
    int a = (int) (sqrt(aa) * 10);
    int b = (int) (sqrt(bb) * 10);

    return compare1(a, b);
}