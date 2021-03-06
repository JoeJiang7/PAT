/**
 * 1079. 延迟的回文数 (20)
 * 
 * 给定一个 k+1 位的正整数 N，写成 ak...a1a0 的形式，其中对所有 i 有
 *  0 <= ai < 10 且 ak > 0。N 被称为一个回文数，当且仅当对所有 i 有 ai = ak-i。
 * 零也被定义为一个回文数。
 * 
 * 非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，
 * 如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非
 * 回文数可以变出回文数，就称这个数为延迟的回文数。
 * （定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number）
 * 
 * 给定任意一个正整数，本题要求你找到其变出的那个回文数。
 * 
 * 输入格式：
 * 
 * 输入在一行中给出一个不超过1000位的正整数。
 * 
 * 输出格式：
 * 
 * 对给定的整数，一行一行输出其变出回文数的过程。每行格式如下
 * 
 * A + B = C
 * 其中A是原始的数字，B是A的逆转数，C是它们的和。A从输入的整数开始。重复操作直到C
 * 在10步以内变成回文数，这时在一行中输出“C is a palindromic number.”；或者
 * 如果10步都没能得到回文数，最后就在一行中输出“Not found in 10 iterations.”。
 * 
 * 输入样例 1：
 * 97152
 * 
 * 输出样例 1：
 * 97152 + 25179 = 122331
 * 122331 + 133221 = 255552
 * 255552 is a palindromic number.
 * 
 * 输入样例 2：
 * 196
 * 
 * 输出样例 2：
 * 196 + 691 = 887
 * 887 + 788 = 1675
 * 1675 + 5761 = 7436
 * 7436 + 6347 = 13783
 * 13783 + 38731 = 52514
 * 52514 + 41525 = 94039
 * 94039 + 93049 = 187088
 * 187088 + 880781 = 1067869
 * 1067869 + 9687601 = 10755470
 * 10755470 + 07455701 = 18211171
 * Not found in 10 iterations.
 **/

#include <stdio.h>
#include <string.h>

int isPalindromicNumber(char n[])
{
    int len = strlen(n);
    for(int i = 0; i < len / 2; i++)
        if(n[i] != n[len - i - 1])
            return 0;
    return 1;
}

void addBtoA(char a[], char b[])
{
    /* Assume length of a and b are the same */
    int len = strlen(a), sum, carry = 0;
    for(int i = len - 1; i >= 0; i --)
    {
        sum = a[i] - '0' + b[i] - '0' + carry;
        a[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry) /* Length of a + b is larger than a or b */
    {
        memmove(a + 1, a, len + 1); /* Shift to right by 1 */
        a[0] = carry + '0';         /* Add the carry to beginning */
    }
}

void reverseAtoB(char a[], char b[])
{
    int len = strlen(a);
    for(int i = 0; i < len; i++)
        b[len - i - 1] = a[i];
}

int main()
{
    int i;
    char a[1011] = {0}, b[1011] = {0};
    
    scanf("%s", a);
    for (i = 0; i < 10 && !isPalindromicNumber(a); i++)
    {
        reverseAtoB(a, b);
        printf("%s + %s = ", a, b);
        addBtoA(a, b);
        printf("%s\n", a);
    }
    
    if(i == 10)
        printf("Not found in 10 iterations.");
    else
        printf("%s is a palindromic number.", a);
    
    return 0;
}
