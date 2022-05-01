#include "t_point.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int i = begin.y - 1;
	int w = size.x;
	int h = size.y;

	while (i < h)
	{

		int j = begin.x - 1;
		while(j < w)
		{
			while (tab[i][j] == '0' && j < w)
			{
				tab[i][j] = 'F';
				j++;
			}
			break ;
			j++;
		}
		i++;
	}
}
