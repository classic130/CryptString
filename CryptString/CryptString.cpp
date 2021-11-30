#include <iostream>
#include "cryptstring.hpp"

int __cdecl main()
{
    std::cout << crypt_string("test!\n");

    getchar();
}