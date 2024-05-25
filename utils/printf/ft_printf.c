/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:51:05 by moouali           #+#    #+#             */
/*   Updated: 2024/01/15 17:18:43 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(char form, int *ret, va_list *args)
{
	if (form == '%')
		*ret += ft_putchar('%');
	else if (form == 'c')
		*ret += ft_putchar(va_arg(*args, int));
	else if (form == 's')
		*ret += ft_putstr(va_arg(*args, char *));
	else if (form == 'd' || form == 'i')
		*ret += ft_put_nbr(va_arg(*args, int));
	else if (form == 'u')
		*ret += ft_put_unbr(va_arg(*args, unsigned int));
	else if (form == 'x' || form == 'X')
		*ret += ft_putx_lo_up((va_arg(*args, int)), form);
	else if (form == 'p')
	{
		*ret += write(1, "0x", 2);
		*ret += ft_putp(va_arg(*args, unsigned long));
	}
	else
		*ret += ft_putchar(form);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, str);
	if (write(1, 0, 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i])
				check_format(str[i], &ret, &args);
			else
				i--;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
