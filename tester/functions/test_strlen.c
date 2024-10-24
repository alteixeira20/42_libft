#include "../tester.h"
#include "../../libft.h"

void test_strlen(FILE *results) {
    const char *str = "Hello, 42!";
    int len = ft_strlen(str);
    if (len == 10) {
        fprintf(results, "ft_strlen: SUCCESS\n");
    } else {
        fprintf(results, "ft_strlen: KO\n");
    }
}
