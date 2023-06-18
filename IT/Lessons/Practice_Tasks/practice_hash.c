#include <stdio.h>
#include <math.h>
/*
    Your task is to implement a hash function which does not result in any collisions.
    Read the main() method closely; it includes only the input which will be used to test your hash function.
    Do not modify the main method.

    This is a practice question. There is no need to submit your response to Google Classroom.
    Avoid the use of any inbuilt library code. Aim to write original code only.
*/

int hash(const char* input) {
    int i = 0;
    int sum = 0;
    while(input[i] != '\0'){
        sum += input[i] * pow(10, i);
        i++;
    }
    return sum;
}

int main() {
    printf("%d\n", hash("abc"));
    printf("%d\n", hash("acb"));
    printf("%d\n", hash("bac"));
    printf("%d\n", hash("bca"));
    printf("%d\n", hash("cba"));
    printf("%d\n", hash("cab"));

    printf("%d\n", hash("abcd"));
    printf("%d\n", hash("acbd"));
    printf("%d\n", hash("bacd"));
    printf("%d\n", hash("bcad"));
    printf("%d\n", hash("cbad"));
    printf("%d\n", hash("cabd"));

    printf("%d\n", hash("abd"));
    printf("%d\n", hash("aco"));
    printf("%d\n", hash("bapo"));
    printf("%d\n", hash("bcf"));
    printf("%d\n", hash("cb5"));
    printf("%d\n", hash("ca8"));

    printf("%d\n", hash("abc!"));
    printf("%d\n", hash("acb2"));
    printf("%d\n", hash("bac'"));
    printf("%d\n", hash("bca0"));
    printf("%d\n", hash("cbah"));
    printf("%d\n", hash("cabf9"));
    
    printf("%d\n", hash("ZE1Cdm"));
    printf("%d\n", hash("gu2WWA"));
    printf("%d\n", hash("Rvl6Jg"));
    printf("%d\n", hash("yO6xNv"));
    printf("%d\n", hash("J7kJNi"));
    printf("%d\n", hash("BfbN4w"));
    printf("%d\n", hash("wX0xNO"));
    printf("%d\n", hash("K68Yy1"));
    printf("%d\n", hash("Z6hdDk"));
    printf("%d\n", hash("QsK6vR"));
    printf("%d\n", hash("IV7Hn4"));
    printf("%d\n", hash("BRzz8N"));
    printf("%d\n", hash("Qyj8co"));
    printf("%d\n", hash("A9ya2I"));
    printf("%d\n", hash("a3BxI5"));
    printf("%d\n", hash("zRI818"));
    printf("%d\n", hash("oF5oRz"));
    printf("%d\n", hash("VK2vDI"));
    printf("%d\n", hash("Wg8bXS"));
    printf("%d\n", hash("CaYo4t"));
    printf("%d\n", hash("M01Yzv"));
    printf("%d\n", hash("H8Wyp7"));
    printf("%d\n", hash("VhH18b"));
    printf("%d\n", hash("hc70QH"));
    printf("%d\n", hash("Iw25zw"));
    printf("%d\n", hash("g3J2kq"));
    printf("%d\n", hash("R46Dp7"));
    printf("%d\n", hash("o2hCNy"));
    printf("%d\n", hash("plM1cP"));
    printf("%d\n", hash("YS9HiJ"));
    printf("%d\n", hash("E6vEVH"));
    printf("%d\n", hash("Ly2JkN"));
    printf("%d\n", hash("C2pj5E"));
    printf("%d\n", hash("aM5lpU"));
    printf("%d\n", hash("oB141b"));
    printf("%d\n", hash("zM8wQg"));
    printf("%d\n", hash("M83nq3"));
    printf("%d\n", hash("Cqr9wB"));
    printf("%d\n", hash("AJ0ft2"));
    printf("%d\n", hash("Hw26JM"));
    printf("%d\n", hash("HgU5Up"));
    printf("%d\n", hash("B0OzvF"));
    printf("%d\n", hash("R7l0OS"));
    printf("%d\n", hash("VlQz4s"));
    printf("%d\n", hash("X50Zn3"));
    printf("%d\n", hash("HCdm9W"));
    printf("%d\n", hash("tO3Fcb"));
    printf("%d\n", hash("c8gXae"));
    printf("%d\n", hash("bAu5Ka"));
    printf("%d\n", hash("k6ySGw"));

}