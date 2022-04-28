#include "head.h"

DERIVED set(int i1, int i2) {
    DERIVED obj;
    obj.BASE1::i = i1;
    obj.BASE2::i = i2;
    return obj;
}

void get(DERIVED &obj) {
    std::cout << "BASE1 i: " << obj.BASE1::i << "\n" \
         << "BASE2 i: " << obj.BASE2::i << std::endl;
}
