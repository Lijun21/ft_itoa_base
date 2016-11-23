/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:36:42 by lwang             #+#    #+#             */
/*   Updated: 2016/11/22 17:41:01 by lwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	count(int tmp, int base)
{
	int i;

	i = 0;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	return (i);
}

char	*revNchar(int *idst, int n, int sign)
{
	char *dst;
	int i;
	int j;

	i = 0;
	j = 0;
	dst = (char*)malloc(sizeof(char) * (n + 1));
	while (idst[i] != -1)
		i++;
	i--;
	if (sign == -1)
	{
		dst[j] = '-';
		j++;
	}
	while (i >= 0)
	{
		if (idst[i] > 9)
			dst[j] = idst[i] - 10 + 'A';
		else
			dst[j] = idst[i] + '0';
		i--;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa_base(int value, int base)
{
	int i;
	int tmp;
	int *idst;
	int n;
	int sign;

	i = 0;
	if (base == 10 && value >= -2147483647 && value < 0)
	{
		sign = -1;
		value = value * (-1);
	}
	else if (base == 10 && value == -2147483648)
	{
		char *n;
		n = "-2147483648";
		return (n);
	}
	else
		sign = 1;
	tmp = value;
	n = count(tmp, base);
	idst = (int*)malloc(sizeof(int) * (n + 2));
	while (value >= base)
	{
		idst[i] = value % base;
		value = value / base;
		i++;
	}
	idst[i] = value;
	i++;
	idst[i] = -1;
	return (revNchar(idst, n, sign));
}
