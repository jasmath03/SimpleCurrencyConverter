#include <stdio.h>
#include <stdlib.h>

#include "console_ui.h"

int main(int argc, const char *argv[]) {
    struct Currency* c1 = make_currency();
    if (!c1) {
        fprintf(stderr, "Failed to create currency structure. Exiting.\n");
        return EXIT_FAILURE;
    }
    
    print_currency(c1);
    
    struct Currency* c2 = convert_currency(c1);
    if (!c2) {
        fprintf(stderr, "Currency conversion failed. Exiting.\n");
        free(c1);
        return EXIT_FAILURE;
    }
    
    print_currency(c2);
    
    free(c1); 
    free(c2);
    return EXIT_SUCCESS;
}

