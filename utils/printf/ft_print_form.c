/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:28:00 by moouali           #+#    #+#             */
/*   Updated: 2024/01/15 17:11:35 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_put_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = ft_putstr("-2147483648");
	else if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
		count += ft_put_nbr(n);
	}
	else if (n > 9)
	{
		count += ft_put_nbr(n / 10);
		count += ft_put_nbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_put_unbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_put_unbr(n / 10);
		count += ft_put_unbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}

int	ft_putx_lo_up(unsigned int n, char c)
{
	int		count;
	char	*hex;

	count = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putx_lo_up(n / 16, c);
		count += ft_putx_lo_up(n % 16, c);
	}
	else
		count += ft_putchar(*(hex + n));
	return (count);
}

int	ft_putp(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_putp(n / 16);
		count += ft_putp(n % 16);
	}
	else
		count += ft_putchar(*(hex + n));
	return (count);
}
