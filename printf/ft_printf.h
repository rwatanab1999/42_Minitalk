/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:45:57 by rwatanab          #+#    #+#             */
/*   Updated: 2023/02/05 10:14:00 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <inttypes.h>
# define DECIMAL "0123456789"
# define HEXADECIMAL_HIGH "0123456789ABCDEF"
# define HEXADECIMAL_LOW "0123456789abcdef"

size_t	pf_strlen(const char *s);
ssize_t	pf_putchar(char c);
ssize_t	pf_putstr(char *s);
ssize_t	pf_putnbr(ssize_t nbr, char *format);
ssize_t	pf_convptr(uintptr_t num);
ssize_t	pf_putptr(uintptr_t num);
int		ft_printf(const char *format, ...);

#endif