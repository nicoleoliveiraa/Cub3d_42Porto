/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:55:24 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/05 19:16:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_types(va_list arg, const char *type, int *c)
{
	if (*type == 'c')
		ft_printchar(va_arg(arg, int), c);
	if (*type == 's')
		ft_printstr(va_arg(arg, char *), c);
	if (*type == 'i' || *type == 'd')
		ft_printnum(va_arg(arg, int), c);
	if (*type == 'u')
		ft_printuns(va_arg(arg, unsigned int), c);
	if (*type == 'x' || *type == 'X')
		ft_printhexa(va_arg(arg, unsigned int), type, c);
	if (*type == 'p')
		ft_printpvoid(va_arg(arg, size_t), c);
	if (*type == '%')
		ft_printchar('%', c);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		c;

	c = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			c += 1;
			write(1, format, 1);
		}
		else
		{
			format++;
			ft_types(arg, format, &c);
		}
		format++;
	}
	va_end(arg);
	return (c);
}

/* int main(void)
{
	//char	*a = "ss";
	ft_printf("fd%fgf");
	printf("\n nic%Ole");
	printf("\n");
	return (0);
} */