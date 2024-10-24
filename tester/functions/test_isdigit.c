#include "../tester.h"
#include "../../libft.h"

void test_isdigit(FILE *results) {
    if (ft_isdigit('0')) {
        fprintf(results, "ft_isdigit: SUCCESS\n");
    } else {
        fprintf(results, "ft_isdigit: KO\n");
    }
}
