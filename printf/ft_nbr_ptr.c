/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:43:24 by rwatanab          #+#    #+#             */
/*   Updated: 2023/02/05 10:13:51 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	pf_putnbr(ssize_t nbr, char *format)
{
	ssize_t	base_len;
	ssize_t	count;
	ssize_t	max_digit;
	ssize_t	index;

	base_len = pf_strlen(format);
	count = 0;
	if (nbr < 0)
	{
		count = count + write(1, "-", 1);
		nbr = nbr * -1;
	}
	max_digit = 1;
	while (nbr >= max_digit * base_len)
		max_digit = max_digit * base_len;
	while (max_digit != 0)
	{
		index = (nbr / max_digit) % base_len;
		nbr = nbr % max_digit;
		max_digit = max_digit / base_len;
		count = count + write(1, &format[index], 1);
	}
	return (count);
}

ssize_t	pf_convptr(uintptr_t num)
{
	ssize_t	count;

	count = 0;
	if (num >= 16)
	{
		count = count + pf_convptr(num / 16);
		count = count + pf_convptr(num % 16);
	}
	else
	{
		if (num <= 9)
			count = count + pf_putchar('0' + num);
		else
			count = count + pf_putchar('a' + num - 10);
	}
	return (count);
}

ssize_t	pf_putptr(uintptr_t num)
{
	ssize_t	count;

	count = write(1, "0x", 2);
	if (num == 0)
		count = count + write(1, "0", 1);
	else
		count = count + pf_convptr(num);
	return (count);
}
