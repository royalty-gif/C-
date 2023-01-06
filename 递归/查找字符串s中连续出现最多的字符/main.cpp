// @Func: 查找字符串s中连续出现最多的字符

#include <iostream>

using namespace std;

// parameter:
// s:  传入的字符串
// n:  遍历每个字符出现的次数，与max比较，将最大值记录到max
// o:  记录原始的字符串，用于计算位置
// mi: 记录连续字符的起始位置，通过这个起始位置就可以得知出现最多的字符
// max:记录递归过程的最大值

void MaxDupChar(const char* s, int& n, const char* o, int& mi, int& max) {
    if( *s == 0 ) {
        n = 0;
        mi = -1;
        max = 0;
    } else {
        MaxDupChar(s+1, n, o, mi, max);

        if( *s == *(s+1) ) {
            n++;
        } else {
            n = 1;
        }

        if(n > max) {
            mi = s - o;
            max = n;
        }
    }
}

char MaxDupChar(const char* s, int& n) {
    char ret = 0;

    if( s ) {
        int i = -1; // 连续出现字符的起始位置
        int c = 0;  // 每个字符连续出现的次数

        MaxDupChar(s, c, s, i, n);

        ret = s[i];
    }

    return ret;
}

int main() {
    int n = 0;
    cout << "char: " << MaxDupChar("aabbbbbc", n) << endl;
    cout << "n: " << n << endl;
}