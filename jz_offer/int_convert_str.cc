#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const char digits[] = "9876543210123456789";//important
//前面9个 是为了负数 : zero[-1] = 1;
const char *zero = digits + 9;

template <typename T>
size_t convert(char buf[], T value) {
    T i = value;
    char *p = buf;

    do {
        int lsd = static_cast<int>(i%10);
        i /= 10;
        *p++ = zero[lsd];
    }while (i != 0);
    
    if (value < 0)
        *p++ = '-';

    *p = '\0';
    std::reverse(buf, p);
    return p - buf;
}

size_t convert_double_bysnprintf(char buf[], double v){
    return snprintf(buf, 32, "%.12g", v);
}

int main() {
    int num;
    char buf[30];

    cout << "enter num: ";
    cin >> num;
    size_t len = convert(buf, num);
    printf("convert to str: %s\n", buf);

    char doubuf[33];
    double dounum;
    cout << endl << "enter double num: ";
    cin >> dounum;
    convert_double_bysnprintf(doubuf, dounum);
    printf("convert to str: %s\n", doubuf);
    return 0;
}
