// @Func: 判断字符串s是不是整数字符串

#include <iostream>

using namespace std;


// weight: 权重
bool IsIntStr(const char* s, int& n, int& weight) {
    bool ret = true;

    if( *s == 0 ) {
        n = 0;
        weight = 1;
    } else {

        ret = ('0' <= *s ) && (*s <= '9');
        ret = ret && IsIntStr(s+1, n, weight);

        if( ret ) {
            n = n + (*s - '0') * weight;
            weight *= 10;

        } else {
            ret = false;
        }
    }

    return ret;
}

// mainly: 符号位处理
bool IsIntStr(const char* s, int& n) {
    bool ret = false;

    if( s && *s ) {

        int sign = 0;

        if( ('0' <= *s ) && (*s <= '9')) {
            sign = 1;
        } else {
            switch ( *s ) {
                case '+':
                    sign = 1;
                    s++;
                    break;
                case '-':
                    sign = -1;
                    s++;
                    break;
            }
        }

        if( sign ) {
            int weight = 0;
            ret = IsIntStr(s, n, weight) && (n *= sign, true);
        }
    }

    return ret;
}

int main() {
    int n = 0;
    cout << IsIntStr("-123434634", n) << endl;
    cout << "n: " << n << endl;
}