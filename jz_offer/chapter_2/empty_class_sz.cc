#include <iostream>

using namespace std;

class EmptyC {
public:
    EmptyC() { cout << "EmptyClass construct" << endl; }
    ~EmptyC() { cout << "EmptyClass destruct" << endl; }
};

class EmptyVirtualC {
public:
    EmptyVirtualC() { cout << "EmptyVirtualClass construct" << endl; }
    ~EmptyVirtualC() { cout << "EmptyVirtualClass destruct" << endl; }
    virtual void f() { cout << "virtual f" << endl; }
};


int main() {
    EmptyC a; 
    //每个无成员类型的实例由编译器决定，占1字节，加入的函数与实例无关，所以还是为1byte
    EmptyVirtualC va; 
    //虚函数表=》编译器为每个实例中添加一个指向该虚函数表的指针  64位该指针为8byte
    cout << "EmptyC sz: "
         << sizeof(a) << endl;
    cout << "EmptyVirualC sz: " 
         << sizeof(va) << endl;
    return 0; 
}
