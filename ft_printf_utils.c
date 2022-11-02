/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:29 by azari             #+#    #+#             */
/*   Updated: 2022/11/02 11:35:02 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int	ft_putnbr_base_s(long long nbr, char *base)
{
	unsigned long long	number;
	int					read;

	read = 0;
	number = nbr;
	if (nbr < 0)
	{
		read += ft_putchar('-');
		number = -nbr;
	}
	read += ft_putnbr_base_u(number, base);
	return (read);
}

int	ft_putnbr_base_u(unsigned long long nbr, char *base)
{
	unsigned long long	read;
	unsigned long long	len;

	len = ft_strlen(base);
	read = 0;
	if (nbr >= len)
		read += ft_putnbr_base_u(nbr / len, base);
	write(1, &base[nbr % len], 1);
	read++;
	return (read);
}
