#include <iostream>


struct foo{
    int a;
    int b;
    int c;
};

int main(){
    foo f;
    f.a = 3;
    foo* p = &f;
    p->b = 4;
    std::cout << f.b;
    return 0;
}
