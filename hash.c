#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//hash_function(key, size));

// int hash_function(char* key, int size)
// {
//     // initialize index to 0
//     int index = 0;

//     // sum ascii values
//     for (int i = 0; key[i] != '\0'; i++)
//     {
//         index += toupper(key[i]);
//     }

//     // mod by size to stay w/in bound of table
//     return index % size;
// }


unsigned int hash_function(const char *word, int size)
{
   int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;

        // comma case
        else
            n = 27;

        hash = ((hash << 3) + n) % size;
    }
    return hash;
}

int main(int argc, char* argv[])
{
    // get hash table size
    int size = 1000000;
    //get_int("Hash table size: ");

    // get key
    char *key = get_string("Key: ");

    // calculate and print index
    printf("The string '%s' is mapped to index %i\n", key,
    hash_function(key, size));

    return 0;
}



//https://github.com/davidventuri/harvard-cs50/blob/master/pset5/dictionary.c