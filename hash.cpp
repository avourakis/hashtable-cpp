#include <iostream>
#include <string>

#include "hash.h"

hash_table::hash_table()
{
    for (int i = 0; i < table_size; i++)
    {
        table[i] = new item;
        table[i]->first_name = "empty";
        table[i]->last_name = "empty";
        table[i]->next = NULL;
    }
}

int hash_table::hash_function(std::string key)
{
    // Compute the key's hash code and then map it to an index in the array

    int hash_code = 0;
    int index;
    for(int i = 0; i < key.length(); i++)
    {
        hash_code += (int)key[i]; // ASCII of letter
    }
    
    index = hash_code % table_size;

    return index;
}

void hash_table::add_item(std::string first_name, std::string last_name)
{
    // Adds a new item to the array. Takes care of collisions

    int index = hash_function(first_name);
    
    if(table[index]->first_name == "empty")
    {
        // do something
    } 
    else
    {
        // do something
    }

}











