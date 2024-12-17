/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijerruz- <ijerruz-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:33:33 by ijerruz-          #+#    #+#             */
/*   Updated: 2024/04/24 17:13:14 by ijerruz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	reverse(char *s)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < ft_strlen(s) / 2)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

static char	*stringify(int n, int i, int neg)
{
	char	*string;

	string = malloc((numlen(n) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 0)
	{
		string[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (neg)
	{
		string[i] = '-';
		i++;
	}
	string[i] = 0;
	return (string);
}

char	*ft_itoa(int n)
{
	char	*num;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = stringify(n, 0, 0);
	if (!num)
		return (0);
	reverse(num);
	return (num);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-123456));
	//printf("%d\n", numlen(-88652));
	//printf("%s\n", reverse("hola"));
	return (0);
} */
