#include "../tester.h"
#include "../../libft.h"

void test_isalpha(FILE *results) {
    if (ft_isalpha('A')) {
        fprintf(results, "ft_isalpha: SUCCESS\n");
    } else {
        fprintf(results, "ft_isalpha: KO\n");
    }
}
