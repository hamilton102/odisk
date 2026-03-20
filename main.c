#include <stdio.h>
#include "config.h"
#include "parse.h"

int main(void) {
        char* input_config = "test.ini";
        struct ini* ini = parse_config(input_config);

        printf("Header: %s\n", ini->header);
        printf("Key: %s\n", ini->key);
        printf("value: %s\n", ini->value);
        return 0;
}
