#include "NameSpace.hpp"
void Handle()
{   mfc::inflag++;
    owl::inflag--;
    ::inflag%=100;

}