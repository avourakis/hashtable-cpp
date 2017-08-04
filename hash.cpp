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
        table[index]->first_name = first_name;
        table[index]->last_name = last_name;
        table[index]->next = NULL;
    } 
    else
    {
        item* ptr = table[index];
        item* new_item = new item;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        new_item->first_name = first_name;
        new_item->last_name = last_name;
        new_item->next = NULL;

        ptr->next = new_item;
    }
}

void hash_table::print_table()
{
    // Prints the data in the array along with number of items it contains.

    for(int i = 0; i < table_size; i++)
    {
        std::cout << "----------------------" << std::endl;
        std::cout << "First Name: " << table[i]->first_name << std::endl;
        std::cout << "Last Name: " << table[i]->last_name << std::endl;
        std::cout << "Items: " << count_items(i) << std::endl;
        std::cout << "----------------------" << std::endl;
    }
}

int hash_table::count_items(int index)
{
    // Returns the number of items found at an specific index in the array
    int count = 0;
    if(table[index]->first_name == "empty")
        return count;
    else
    {
        count++;
        item* ptr = table[index];
        while(ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}



