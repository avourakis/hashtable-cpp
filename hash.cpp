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

