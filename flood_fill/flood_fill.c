#include "t_point.h"

void fill_recursion(char **tab, t_point size, t_point b, char fill)
{
	t_point point[4];
	point[0].x = b.x + 1;
	point[0].y = b.y;
	point[1].x = b.x - 1;
	point[1].y = b.y;
	point[2].x = b.x;
	point[2].y = b.y + 1;
	point[3].x = b.x;
	point[3].y = b.y - 1;

	if (b.x >= 0 && b.y >= 0 && b.x < size.x &&  b.y < size.y)
	{
		if (tab[b.y][b.x] != fill)
			return ;
		else
		{
			tab[b.y][b.x] = 'F';
			fill_recursion(tab, size, point[0], fill);
			fill_recursion(tab, size, point[1], fill);
			fill_recursion(tab, size, point[2], fill);
			fill_recursion(tab, size, point[3], fill);
		}
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char fill = tab[begin.y][begin.x];

	fill_recursion(tab, size, begin, fill);
}
