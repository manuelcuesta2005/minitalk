/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:53:20 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/06 16:23:14 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
    const char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    void *resultado = ft_memchr(buffer, 0x05, sizeof(buffer));
    printf("%02x\n", *(unsigned char *)resultado);
}
*/