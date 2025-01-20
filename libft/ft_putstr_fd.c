/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:56:13 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 11:48:44 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
#include <fcntl.h>
int main(void)
{
    int fd = open("archivo", 1);
    char *string = "hola mundo";
    ft_putstr_fd(string, fd);
    close(fd);
    return (0);
}
*/