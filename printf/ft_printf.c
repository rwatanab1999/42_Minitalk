/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:42:27 by rwatanab          #+#    #+#             */
/*   Updated: 2023/02/05 10:15:59 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fmt_specifier_func(const char **format, ssize_t *co, va_list *ap)
{
	(*format)++;
	if (**format == 'c')
		*co = *co + pf_putchar((char)va_arg(*ap, int));
	else if (**format == 's')
		*co = *co + pf_putstr(va_arg(*ap, char *));
	else if (**format == 'p')
		*co = *co + pf_putptr(va_arg(*ap, uintptr_t));
	else if (**format == 'd' || **format == 'i')
		*co = *co + pf_putnbr((ssize_t)va_arg(*ap, int), DECIMAL);
	else if (**format == 'u')
		*co = *co + pf_putnbr((ssize_t)va_arg(*ap, unsigned int), DECIMAL);
	else if (**format == 'x')
		*co = *co + pf_putnbr((ssize_t)va_arg(*ap, unsigned int), \
		HEXADECIMAL_LOW);
	else if (**format == 'X')
		*co = *co + pf_putnbr((ssize_t)va_arg(*ap, unsigned int), \
		HEXADECIMAL_HIGH);
	else if (**format == '%')
		*co = *co + write(1, "%", 1);
	(*format)++;
}

static void	str_output_func(const char **format, ssize_t *count)
{
	const char	*start;

	start = *format;
	while (**format != '%' && **format)
		(*format)++;
	*count = *count + write(1, start, *format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	count;

	va_start(ap, format);
	count = 0;
	while (*format && count < INT_MAX)
	{
		if (*format == '%')
			fmt_specifier_func(&format, &count, &ap);
		else
			str_output_func(&format, &count);
	}
	va_end(ap);
	if (count >= INT_MAX)
		return (-1);
	return (count);
}
