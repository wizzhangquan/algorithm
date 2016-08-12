#include <iostream>
#include <string>
#include <deque>
#include <sstream>

/*
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

class ExpressionEvaluation {
public:
    int getValue(string &expression) {
        istringstream istr(expression);
        return computerExpression(istr);
    }
    int computerExpression(istringstream &istr) { 
        cout << "----------------------" << endl;
        deque<string> basicExpressQue;
        int num = 0;
        char c;
        
        while (istr >> c && c != ')') {
            if (c >= '0' && c <= '9') {
                num = 10*num + c-'0';
            } else if (c == '(') {
                num = computerExpression(istr);
                //expressQueuePush(basicExpressQue, intToStr(num));
                //num = 0;
            }
            else {
                expressQueuePush(basicExpressQue, intToStr(num));
                expressQueuePush(basicExpressQue, charToStr(c)); 
                num = 0;
            }
        }
        expressQueuePush(basicExpressQue, intToStr(num));
        cout << "Now show u the que: ";
        showQue(basicExpressQue);
        cout << "Now shot u the result: ";
        cout << computeByDeque(basicExpressQue) << endl;
        cout << "-----------------------" << endl << endl;
        return computeByDeque(basicExpressQue);
    }

    void expressQueuePush(deque<string> &que, const string elem) {
        cout << __func__ << ":begin :" << elem << endl;
        if (que.empty() || elem == "*" || elem == "/"
            || elem == "+" || elem == "-") {
            que.push_back(elem);
            return ;
        }
        string oper = que.back();
        if (oper == "*" || oper == "/") {
            que.pop_back();
            int leftNum = strToInt(que.back());
            que.pop_back();
            int ret = oper == "*" ? leftNum*strToInt(elem)
                         : leftNum/strToInt(elem);
             
            que.push_back(intToStr(ret));

        } else
            que.push_back(elem);
    }

    int computeByDeque(const deque<string> &que) {
        int left = strToInt(que.front());
        int right;
        string oper;
        for (deque<string>::const_iterator item = que.begin() + 1; 
            item != que.end(); ) {
            oper = *item++;
            right = strToInt(*item++);
            left = oper == "+" ? left+right
                 : left-right;
        }
        return left;
    }

    void showQue(const deque<string> &que) {
        for (auto s : que)
            cout << s << " ";
        cout << endl;
    }

private:
    int strToInt(const string &str) {
        istringstream istr(str);
        int ret;
        istr >> ret;
        return ret;
    }
    string intToStr(const int num) {
        ostringstream ostr;
        ostr << num;
        return ostr.str();
    }
    string charToStr(const char oper) {
        ostringstream ostr;
        ostr << oper;
        return ostr.str();
    }
};
/*
void ftest(istringstream &icur) {
    char a;
    if (!(icur >> a))
        return ;
    cout << a << "->";
    ftest(icur);
}

void test_ftest() {
    string str("Hello,World.");
    istringstream istr(str);
    ftest(istr);
}
*/

void run() {
    cout << "Please enter expression:" << endl;
    string expression;
    cin >> expression;
    
    ExpressionEvaluation ee;
    cout << "getValue : ";
    cout << ee.getValue(expression) << endl;
}

int main() {
    run();
    return 0;
}
