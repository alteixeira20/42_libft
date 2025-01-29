#include "../tester.h"
#include "../tester.h"
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 4
#define LEN_TESTS 28
#define PRINT_LIMIT 8  // Limit the number of bytes to print

void	test_memmove(FILE *results)
{
	int	i;
	char	test1[NBR_TESTS][LEN_TESTS] = {"aqui a gato", "hello 42", "", "1234567"};	
	char	test2[NBR_TESTS][LEN_TESTS] = {"aqui a gato", "hello 42", "", "1234567"};
	size_t	size = 4;

	i = 0;
	while (i < NBR_TESTS)
	{
		// Special case for testing overlapping regions on the fourth test
		if (i == 3)
		{
			ft_memmove(test1[i] + 2, test1[i], size); // Overlapping move in ft_memmove
			memmove(test2[i] + 2, test2[i], size);    // Overlapping move in memmove
		}
		else
		{
			ft_memmove(test1[i], "123456", size);
			memmove(test2[i], "123456", size);
		}
		
		// Check if the contents match
		if (memcmp(test1[i], test2[i], LEN_TESTS) != 0)
		{
			// Print KO message with expected vs. actual in the same line
			fprintf(results, "ft_memmove: KO | Test %d failed | Expected: ", i + 1);
			
			// Print only the relevant bytes up to PRINT_LIMIT
			size_t j = 0;
			while (j < PRINT_LIMIT)
			{
				fprintf(results, "%02x ", (unsigned char)test2[i][j]);
				j++;
			}

			fprintf(results, " | Yours: ");

			// Print actual values up to PRINT_LIMIT
			j = 0;
			while (j < PRINT_LIMIT)
			{
				fprintf(results, "%02x ", (unsigned char)test1[i][j]);
				j++;
			}
			fprintf(results, "\n");
			return;
		}
		i++;
	}
	fprintf(results, "ft_memmove: SUCCESS\n");
}
