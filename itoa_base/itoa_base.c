#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	int		len;
	int		nb;
	char	*base_string = "0123456789ABCDEF";

	len = 1;
	nb = value;
	while (nb/=base)
		len++;
	if (value < 0 && base == 10)
		len++;
	result = (char *)malloc(sizeof (char) * len + 1);
	if (!result)
		return(NULL);
	result[len] = '\0';
	len--;
	if (value < 0 && base == 10)
	{
		result[0] = '-';
		nb = -value;
	}
	else
		nb = value;
	while (nb > 0)
	{
		result[len] = base_string[nb % base];
		nb /= base;
		len--;
	}
	return(result);
}

int	main(void)
{
	printf("%s\n", ft_itoa_base(1281414, 16));
	return (0);
}
