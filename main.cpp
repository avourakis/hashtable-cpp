#include <iostream>
#include <string>
#include <vector>
#include "hash.h"


int main()
{
    std::vector<std::string> first_names = {"Andres", "Elon", "Steve", "Jeff", "Siraj"};
    std::vector<std::string> last_names = {"Vourakis", "Musk", "Wozniak", "Moss", "Raval"};
    
    hash_table test;

    for(std::vector<std::string>::size_type i = 0; i != first_names.size(); i++)
    {
        test.add_item(first_names[i], last_names[i]);
    }

    test.print_table();
    
    int index = test.hash_function("Siraj");
    std::cout << "Before delete" << std::endl;
    test.print_items(index);
    test.delete_item("Siraj");
    std::cout << "After delete" << std::endl;
    test.print_table();
    test.print_items(index);

    return 0;
}
