#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 比较函数用于qsort排序
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 获取有效的整数输入
int get_valid_int(const char *prompt, int min, int max) {
    int value;
    int result;
    
    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);
        
        // 清除输入缓冲区
        while (getchar() != '\n');
        
        if (result != 1) {
            printf("错误：请输入一个有效的整数。\n");
            continue;
        }
        
        if (value < min || value > max) {
            printf("错误：请输入一个%d到%d之间的整数。\n", min, max);
            continue;
        }
        
        return value;
    }
}

int main() {
    int n, x;
    
    // 获取n的值（1到999之间的整数）
    n = get_valid_int("请输入一个1到999之间的整数: ", 1, 999);
    
    // 获取x的值（小于n的正整数）
    x = get_valid_int("请输入一个小于上述整数的正整数: ", 1, n-1);
    
    // 初始化随机数生成器
    srand(time(NULL));
    
    // 创建并初始化数组
    int *numbers = (int*)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    
    // 生成1到n的数字
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }
    
    // Fisher-Yates洗牌算法，随机打乱数组
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    
    // 取前x个元素
    int *selected = (int*)malloc(x * sizeof(int));
    if (selected == NULL) {
        printf("内存分配失败！\n");
        free(numbers);
        return 1;
    }
    
    for (int i = 0; i < x; i++) {
        selected[i] = numbers[i];
    }
    
    // 对选中的数字进行排序
    qsort(selected, x, sizeof(int), compare);
    
    // 输出结果
    printf("\n随机选出的%d个数字并按升序排列: ", x);
    for (int i = 0; i < x; i++) {
        printf("%d", selected[i]);
        if (i < x - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    // 释放内存
    free(numbers);
    free(selected);
    
    return 0;
}