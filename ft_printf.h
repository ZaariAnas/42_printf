/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:08:34 by azari             #+#    #+#             */
/*   Updated: 2022/10/31 21:04:43 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define B10 "0123456789"
# define B16x "0123456789abcdef"
# define B16X "0123456789ABCDEF"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


void	ft_putchar(int c);
int	ft_strlen(char *s);

#endif