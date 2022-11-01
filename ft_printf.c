/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:28:48 by azari             #+#    #+#             */
/*   Updated: 2022/11/01 18:12:46 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>

int ft_convert(va_list ptr, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbr_base_u((unsigned long long)va_arg(ptr, void *), B16x);
	}
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_base_s(va_arg(ptr, int), B10);
	else if (c == 'u')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B10);
	else if (c == 'x')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B16x);
	else if (c == 'X')
		i += ft_putnbr_base_u(va_arg(ptr, unsigned int), B16X);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}


int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		read;
	int		i;
	
	read = 0;
	i = -1;
	va_start(ptr, s);
	while (s[++i])
	{
		if (s[i] != '%')
			read += ft_putchar(s[i]);
		else if (s[i] == '%')
		{
			read +=	ft_convert(ptr, s[i + 1]);
			i++;
		}
	}
	va_end(ptr);
	return (read);
}

// int main()
// {
// 	int i;
// 	i = ft_printf("%p", -1);
// 	printf("%d", i);
// }