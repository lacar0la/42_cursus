/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahernan <lahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:29:25 by lahernan          #+#    #+#             */
/*   Updated: 2023/05/24 18:29:27 by lahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_conversion(va_list ap, const char str, int count);
int		ft_printf(const char *str, ...);
int		ft_putchar(int a);
int		ft_putstr(char *str);
int		ft_putdec(unsigned long dec);
int		ft_putnbr(int nb);
int		ft_puthex(unsigned long long num, int capital);
int		ft_putnbr_unsigned(unsigned int n);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);

#endif
