#include <stdio.h>  // 使用了 printf 函数
#include <stdlib.h>  // 使用了 malloc, free 函数
#include <string.h>  // 使用 strcpy 函数


char *longest(char *s1, char* s2) {
    char *ss1 = s1, *ss2 = s2;  // 使用两个指针来访问两个字符串, 为了不破坏原字符串; 指针的运行速度更快
    _Bool alpha[26] = {0};  // 用来判断26个字母中哪一个出现, 初始都是 0, 下面如果出现了, 就把它的值改成 1, alpha[0] 假设对应 'a', 以此类推...
    while(*ss1 != '\0')  // 遍历第一个字符串
    {
        if(!alpha[*ss1 - 'a'])  // *ss1 - 'a' 对应索引值: 比如 *ss1 如果是 'a', 'a' - 'a' 就是0, 所以就是 alpha 的第 0 个元素, 以此类推
            alpha[*ss1 - 'a'] = 1;  // 如果上边的判断为真, 也就是出现了该字母, 那么它在 alpha 对应的位置变成 1, 表示出现了
        ss1++;  // 移动到下一个位置
    }
    while(*ss2 != '\0')  // 和上边的那个while 循环一样, 只不过遍历的是第二个字符串
    {
        if(!alpha[*ss2 - 'a'])
            alpha[*ss2 - 'a'] = 1;
        ss2++;
    }
    char result[27], k = 0;  // result 用来存放最终我们要合成的字符串, 就是按字母表顺序来的那个字符串
    for(int i = 0; i < 26; i++)  // i 从 0 到 25, 对应 alpha 的索引值, 也就是下标, 
        if(alpha[i])  // 如果出现过该字母, 就拿 'a' 来举例, 如果 s1 中 或者 s2 中有 'a', 那么 alpha[0] 就会变成 1, 这个 if 就起作用
            result[k++] = 'a' + i;  // 假设 alpha[0] 是 1, 也就是出现过 'a', 那么 'a' + 0 就是 'a'本身, 所以 result 中储存了 'a' 这个字符
    result[k] = '\0';  // result 中加上一个 '\0' 来表示结束
    char *r = malloc(sizeof(char) * (k+1));  // 动态分配空间, 刚好是字符串 result 的空间, 至于为什么是 k+1, 可以手算一下, 因为要考虑 '\0'
    strcpy(r, result);  // 将字符串拷贝到 r 中, 至于为什么要用这种方法返回字符串, 是因为 C语言 本身不可以直接返回字符串, 网上有4中方法, 但是在这里适合用动态分配这种方式
    return r;  // 返回 r
}

int main()
{
    char *s = longest("xyaabbbccccdefww", "xxxxyyyyabklmopq");
    printf("%s\n", s);  // 可以这样打印
    //while(*s != '\0')  // 也可以这样打印, 但是会使 s 指向的位置发生改变
    //    putchar(*s++);
    //putchar('\n');
    free(s);  // 记住要 free 掉
    return 0;
}
