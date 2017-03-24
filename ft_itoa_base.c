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
#include <stdio.h>

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;
	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}
