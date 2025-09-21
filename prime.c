#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// 函数声明
bool isPrime(int n);

int main() {
    int n;
    
    printf("素数判断程序\n");
    printf("请输入一个正整数: ");
    
    // 获取用户输入
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("错误：请输入一个有效的正整数！\n");
        return 1;
    }
    
    // 判断是否为素数并输出结果
    if (isPrime(n)) {
        printf("%d 是素数。\n", n);
    } else {
        printf("%d 不是素数。\n", n);
    }
    
    return 0;
}

// 判断素数的函数
bool isPrime(int n) {
    // 小于2的数不是素数
    if (n < 2) {
        return false;
    }
    
    // 2是素数
    if (n == 2) {
        return true;
    }
    
    // 偶数（除了2）不是素数
    if (n % 2 == 0) {
        return false;
    }
    
    // 检查从3到sqrt(n)的奇数因子
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}