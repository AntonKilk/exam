// #include "test_functions.h"
#include "t_point.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function 'colors' an entire zone
by replacing characters inside by the character 'F'. A zone is an ensemble of
the same character delimitated horizontally and vertically by other characters.

The flood_fill function won't 'color' in diagonal.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is available inside the "t_point.h" file attached to this
assignment. We will use our "t_point.h" for graduation.
 */

void  flood_fill(char **tab, t_point size, t_point begin);

char	**make_area(char **zone)
{
	char **area;
	area = (char **)malloc(sizeof (char *) * 7);
	int i = 0;
	while (i < 7)
	{
		area[i] = strdup(zone[i]);
		i++;
	}
	return (area);
}

void	print_tab(char **area)
{
	int i = 0;
	while (i < 7)
	{
		printf("%s\n", area[i]);
		i++;
	}
}

int main(void)
{
	char **area;
	t_point size = { 7, 7 };
	t_point begin = { 0, 0 };
	char *zone[] = {
		"aaaaaaa",
		"aabbbaa",
		"abaaaba",
		"abaaaba",
		"abaaaba",
		"aabbbaa",
		"aaaaaaa"
	};

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area);
	return (0);
}
