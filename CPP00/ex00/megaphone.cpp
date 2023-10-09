#include <iostream>

int main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while (av[i][j])
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
			if (!av[i][j] && av[i])
			{
				j = 0;
				i++;
			}
		}
	}
}
