#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <string.h>

// Example function to use with ft_striteri
static void example_func(unsigned int i, char *c)
{
	*c = *c + i;  // Shift each character by its index
}

void	test_striteri(FILE *results)
{
	char	test_str[] = "abcdef";
	const char	*expected_result = "acegik";

	// Run ft_striteri with test string and example function
	ft_striteri(test_str, example_func);

	// Check if the modified string matches the expected output
	if (strcmp(test_str, expected_result) == 0)
	{
		fprintf(results, "ft_striteri: SUCCESS\n");
	}
	else
	{
		fprintf(results, "ft_striteri: KO | Expected: \"%s\", Got: \"%s\"\n",
				expected_result, test_str);
	}
}
