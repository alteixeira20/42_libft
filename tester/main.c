#include "libft_tester.h"
#include "../libft.h"
#include <stdio.h>

// Example test for ft_strlen
void ft_strlen_test(FILE *results) {
    const char *str = "Hello, 42!";
    int len = ft_strlen(str);
    if (len == 10) {
        fprintf(results, "ft_strlen: SUCCESS\n");
    } else {
        fprintf(results, "ft_strlen: KO\n");
    }
}

void ft_isdigit_test(FILE *results) {
    if (ft_isdigit('0')) {
        fprintf(results, "ft_isdigit: SUCCESS\n");
    } else {
        fprintf(results, "ft_isdigit: KO\n");
    }
}

// Example test for ft_isalpha
void ft_isalpha_test(FILE *results) {
    if (ft_isalpha('A')) {
        fprintf(results, "ft_isalpha: SUCCESS\n");
    } else {
        fprintf(results, "ft_isalpha: KO\n");
    }
}

int main(void) {
    	FILE *results = fopen("tester/results.txt", "w");
    	if (!results) {
        	printf("Error: could not open results file.\n");
        	return 1;
    	}

	ft_strlen_test(results);
	ft_isalpha_test(results);
	ft_isdigit_test(results);
    	// Add more test functions here
	fclose(results);
    	return 0;
}
