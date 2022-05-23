/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:42:35 by cletinic          #+#    #+#             */
/*   Updated: 2018/07/25 09:20:55 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int index = 0;
	int s1len = 0;
	int s2len = 0;
	char *str;
	
	while (s1[s1len]) // get the length of s1
		s1len++;
	while (s2[s2len]) // get the length of s2
		s2len++;
	str = (char *)malloc((sizeof(char)) * (s1len + s2len) + 1); // enough space for both stings and +1 for '\0'
	while (s1[index]) // put the content of s1 into the string we allocated space for
	{
		str[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index]) // now put the content of s2 into the string we allocated space for
	{
		str[s1len + index] = s2[index]; // since we already have s1 content we want to offset str's index by s1's length
		index++;
	}
	str[s1len + index] = '\0'; // nul-terminate the string we were allocated.
	return (str); // return the srting
}

// ITOA uses a very similar logic as put_number, but instead of printing to an fd 
// we are storing it into a string.

	// in putnbr we break down the numbers into individual digits. that is what we
	// are going to do here. we are going to break each digit into its own string
	// then we are using string join to join the number back together
	// then we return it.
	// eg 123 -> will break into 12 and 3
	// 3 -> string contains '3' '\0'
	// mod and divide 12 -> 1 and 2
	// 2 -> string contains '2' '\0'
	// 1 -> string contains '1' '\0'
	// then joins '1' '\0' and '2' '\0'
	// then joins '12' '\0' and '3' '\0'

char	*ft_itoa(int n)
{
	char *s;
	char *int_min;

	s = (char *)malloc((sizeof(char)) + 2); // allocate 2 spaces. one for the digit and one for the nul-terminator
	if (n == -2147483648) // you have to check for the int min or else moulinette fails you
		return(int_min = "-2147483648"); // if you cannot remember this number. - in a new terminal just type python. and the use "-2**31" (whithout quote marks this means: -2^31)
	if (n < 0)
	{
		s[0] = '-'; // assign - to the front of the string
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n)); // this will now sit on the stack until the rest of the number is joined and will put a positive nbr back into itoa
	}
	else if (n >= 10) // if nbr is more than a single digit
		s = ft_strjoin((ft_itoa(n / 10)), (ft_itoa(n % 10)));  // recursively break down the number, the numbers will sit on the stack until, it joins the digit-strings together
	else
	{
		s[0] = (n + '0'); // change the digit to the ascii symbol for that digit
		s[1] = '\0';
	}
	return (s); //return 
}

/*
#include <stdio.h>
int main ()
{
	char s[] = "hello";
	char s2[] = "there";

	printf("strjoin : |%s|", ft_strjoin(s, s2));

	printf("\nitoa: |%s|", ft_itoa(-123));
}
*/
