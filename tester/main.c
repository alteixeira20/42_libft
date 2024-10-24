#include <stdio.h>
#include "tester.h"

int main(void) {
    FILE *results = fopen("results.txt", "w");
    if (!results) {
        printf("Error: could not open results file.\n");
        return 1;
    }

    // Running all tests
    test_strlen(results);
    test_isalpha(results);
    test_isdigit(results);

    // Close the results file
    fclose(results);

    return 0;
}
