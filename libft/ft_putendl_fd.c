/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:23:28 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 11:44:10 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*
#include <fcntl.h>
int main(void)
{
    int fd = open("archivo", 1);
    char *string = "hola mundo";
    ft_putendl_fd(string, fd);
    close(fd);
    return (0);
}
*/
