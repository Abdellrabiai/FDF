/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:16:28 by arabiai           #+#    #+#             */
/*   Updated: 2023/02/14 16:16:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

int	ft_iswspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long double	res;

	sign = 1;
	res = 0;
	while (*str && ft_iswspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		if (sign > 0 && res >= 9223372036854775807UL)
			return (-1);
		if (sign < 0 && res >= 9223372036854775808UL)
			return (0);
		str++;
	}
	return (res * sign);
}

int	get_index_base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atohex(const char *str)
{
	int			sign;
	long double	res;

	sign = 1;
	res = 0;
	while (*str && ft_iswspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		res *= 16;
		res += get_index_base(*str, 16);
		str++;
	}
	return (res * sign);
}
