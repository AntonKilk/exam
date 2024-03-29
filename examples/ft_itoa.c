#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    char	*str;
    long	tmp;
    int		length;
    
    tmp = nbr;
    length = (nbr <= 0 ? 2 : 1);
    while (nbr && ++length)
        nbr /= 10;
    if (!(str = (char *)malloc(sizeof(char) * length)))
        return (NULL);
    str[--length] = '\0';
    if (tmp <= 0)
        str[0] = (tmp < 0 ? '-' : '0');
    while (tmp)
    {
        str[--length] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
        tmp /= 10;
    }
    return (str);
}