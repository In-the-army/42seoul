/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remain2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyki <sanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:45:12 by sanghyki          #+#    #+#             */
/*   Updated: 2022/04/16 22:35:35 by sanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hay_len;
	size_t nee_len;
	size_t i;

	if (*needle == '\0')
		return ((char *)haystack);
	hay_len = ft_strlen(haystack);
	nee_len = ft_strlen(needle);
	if (hay_len < nee_len || len < nee_len)
		return (0);
	i = 0;
	while (i + nee_len < len)
	{
		if (ft_memcmp(haystack, needle, nee_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

int ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	return (0);
}

int ft_integer(char *str)
{
	int num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (!(ft_isspace(str[i]) || str[i] == '-' || str[i] == '+'))
			break;
		if (str[i++] == '-')
		{
			sign *= -1;
			break;
		}
		else if (str[i++] == '+')
			break;
	}
	num = ft_integer((char *)str + i);
	return (sign * num);
}
