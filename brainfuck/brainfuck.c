#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	brainfuck(char *code)
{
	int loop = 0;
	int tab[2048] = {0};
	int *ptr;
	ptr = tab;
	while (*code)
	{
		if (*code == '+')
			++(*ptr);
		else if (*code == '-')
			--(*ptr);
		else if (*code == '>')
			ptr++;
		else if (*code == '<')
			ptr--;
		else if (*code == '.')
			write(1, ptr, 1);
		else if (*code == '[' && *ptr == 0)
		{
			loop = 1;
			while (loop != 0)
			{
				code++;
				if (*code == '[')
					loop++;
				if (*code == ']')
					loop--;
			}
		}
		else if (*code == ']' && *ptr != 0)
		{
			loop = -1;
			while (loop != 0)
			{
				code--;
				if (*code == '[')
					loop++;
				if (*code == ']')
					loop--;
			}
		}
		code++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
	 	return (0);
	}
	brainfuck(argv[1]);
	write(1, "\n", 1);
	return (0);
}
