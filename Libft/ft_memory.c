/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyki <sanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:30:04 by sanghyki          #+#    #+#             */
/*   Updated: 2022/04/16 18:44:59 by sanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //이거 써도 됨?

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr_dest;
	const unsigned char *ptr_src;

	ptr_dest = dest;
	ptr_src = src;
	if (ptr_dest == NULL && ptr_src == NULL)
		return (dest);
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr_s;

	ptr_s = s;
	while (n--)
		*ptr_s++ = c;
	return (s);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptr_dst;
	const unsigned char *ptr_src;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr_dst = dst;
	ptr_src = src;
	if (dst <= src)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	else
	{
		if (len--)
			ptr_dst[len] = ptr_src[len];
	}
	return (dst);
}

void ft_bzero(void *s, size_t n)
{
	unsigned char *ptr_s;

	ptr_s = s;
	while (n--)
		*ptr_s++ = 0;
}
