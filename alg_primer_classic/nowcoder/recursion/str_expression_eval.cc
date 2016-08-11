#include <iostream>
#include <string>
#include <sstream>

/*
 *
 * 给定一个字符串str，str表示一个表达式，其中只可能有整数、加减乘除符号和
 * 左右括号，返回公式的计算结果。 
 *
 * 【举例】
 * str="48*((70-65)-43)+8*1"，返回-1816。
 * str="3+1*4"，返回7。
 * str="3+(1*4)"，返回7。
 *
 * 【说明】
 * 1．可以认为给定的字符串一定是正确的表达式，即不需要对str做公式有效性检查。
 * 2．如果是负数，就需要用括号括起来，比如"4*(-3)"。但如果负数作为公式的开头
 * 或括号部分的开头，则可以没有括号，比如"-3*4"和"(-3*4)"都是合法的。
 * 3．不用考虑计算过程中会发生溢出的情况。
 **/

using namespace std;

int plusAndSubtraction(string &expression) {
    //这里只有+ - 没有*/()
    istringstream ostr(expression);    
    int num = 0;
    char c;

    while (ostr >> c) {
        if (c>= '0' && c <= '9') {
            num = 10*num + c-'0';
        }


    }
     
}

int main() {
    return 0;
}
