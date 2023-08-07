/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:42:38 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/02 16:42:39 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_count(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		return (11);
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb > 9)
	{
		while (nb > 9)
		{
			len++;
			nb = nb / 10;
		}
	}
	if (nb <= 9)
	{
		len++;
	}
	return (len);
}

static char	*conditional(int i, int n, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n <= 9)
	{
		str[i] = n + '0';
		i--;
	}
	if (n > 9)
	{
		while (n > 9)
		{
			str[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
		str[i] = n + '0';
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_count(n);
	i = len - 1;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	str = conditional(i, n, str);
	str[len] = '\0';
	return (str);
}
