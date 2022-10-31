/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:29 by azari             #+#    #+#             */
/*   Updated: 2022/10/31 21:06:10 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	v;
	
	v = write(1, s, ft_strlen(s));
	if (v < 0)
		return (-1);
	return (ft_strlen(s));
}

void	ft_putnbr_base(long long nbr, char *base)
{
	int		len;
	long	n;

	len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < len)
		ft_putchar(base[n]);
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
		ft_putnbr_base(n % len, base);
	}
}

int main()
{
	ft_putnbr_base(30, B16x);
}