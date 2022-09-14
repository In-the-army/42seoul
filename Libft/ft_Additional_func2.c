/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Additional_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyki <sanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:23:30 by sanghyki          #+#    #+#             */
/*   Updated: 2022/05/18 21:48:17 by sanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	size_t	len;
	int		sign;

	if (n > 0)
		sign = 1;
	else
		sign = -1;
	len = ft_len(n);
	num_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!num_str)
		return (NULL);
	num_str[len--] = '\0';
	n *= sign;
	while (n > 0)
	{
		num_str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		num_str[0] = '-';
	return (num_str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
