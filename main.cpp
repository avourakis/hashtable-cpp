#include <iostream>
#include <string>
#include "hash.h"


int main()
{
    std::string first_name = "Andres";
    std::string last_name = "Vourakis";
    hash_table test;

    test.add_item(first_name, last_name);
    
    return 0;

}
