#include "minirt.h"

void	error_exit(int n)
{
	if (n == -1)
		write(STDERR_FILENO, "Error: can't allocate memory for some reason\n", 46);
	exit(n);
}
