#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define string_length 256
#define letter_count 26
#define BETWEEN(compare_val, min, max) (min <= compare_val && max >= compare_val)

char small_letter_dictionary[3][letter_count];
char big_letter_dictionary[3][letter_count];


// initializes character dictionary
void init_dictionary() {
    for (int i=0; i<letter_count; i++) {
        if (i+3 >= letter_count) {
            small_letter_dictionary[0][i] = 'a' + i + 3 - letter_count;
            big_letter_dictionary[0][i] = 'A' + + i + 3 - letter_count;            
        } else {
            small_letter_dictionary[0][i] = 'a' + i + 3;
            big_letter_dictionary[0][i] = 'A' + i + 3;            
        }
        if (i-3 < 0) {
            small_letter_dictionary[1][i] = 'a' + i - 3 + letter_count;
            big_letter_dictionary[1][i] = 'A' + i - 3 + letter_count;
        } else {
            small_letter_dictionary[1][i] = 'a' + i - 3;
            big_letter_dictionary[1][i] = 'A' + i - 3;
        }
    }
}

// encrypts using cypher
char * encrypt_string(char *str_input) {
    char *str_output = (char*) malloc(sizeof(char)*strlen(str_input));
    for (int i=0; i<strlen(str_input); i++) {
        if (BETWEEN(str_input[i], 'A', 'Z')) {
            str_output[i] = big_letter_dictionary[0][str_input[i]-'A'];
        } else if (BETWEEN(str_input[i], 'a', 'z')) {
            str_output[i] = small_letter_dictionary[0][str_input[i]-'a'];
        } else {
            str_output[i] = str_input[i];
        }
    }

    return str_output;
}

// decrypts using cypher
char * decrypt_string(char *str_input) {
    char *str_output = (char*) malloc(sizeof(char)*strlen(str_input));
    for (int i=0; i<strlen(str_input); i++) {
        if (BETWEEN(str_input[i], 'A', 'Z')) {
            str_output[i] = big_letter_dictionary[1][str_input[i]-'A'];
        } else if (BETWEEN(str_input[i], 'a', 'z')) {
            str_output[i] = small_letter_dictionary[1][str_input[i]-'a'];
        } else {
            str_output[i] = str_input[i];
        }
    }

    return str_output;
}

// clears a string
void clear_str(char *str) {
    for (int i=0; i<strlen(str); i++) {
        str[i] = 0;
    }
}

// Simple Caesar Cipher Implementation
int main() {
    
    
    init_dictionary();
    char str_input[string_length];
    char *str_output;

    // prompt encryption
    printf("Enter what text you want to encrypt using Caesar-cypher: ");
    fgets(str_input, string_length, stdin);
    str_output = encrypt_string(str_input);
    printf("The resulting cipher (encrypted) is: %s\n", str_output);

    // clear string
    clear_str(str_input);

    // prompt decryption
    printf("Enter what text you want to decrypt using Caesar-cypher: ");    
    fgets(str_input, string_length, stdin);
    str_output = decrypt_string(str_input);
    printf("The resulting cipher (decrypted) is: %s\n", str_output);
}