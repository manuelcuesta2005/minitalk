/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:18:17 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/12/16 20:18:19 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	send_messages(int pid_server, char *message)
{
	int		i;
	int		bit;
	char	letter;

	i = 0;
	while (message[i])
	{
		letter = message[i];
		bit = 0;
		while (bit < 8)
		{
			if (letter >> (7 - bit) & 1)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			bit++;
			usleep(100);
		}
		i++;
	}
	bit = 0;
	while (bit < 8)
	{
		kill(pid_server, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		ft_printf("Uso del cliente: %s <PID> <mensaje para el servidor> \n",
			argv[0]);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
	{
		ft_printf("Error: PID del servidor invalido. \n");
		return (1);
	}
	send_messages(pid_server, argv[2]);
	ft_printf("Mensaje enviado con exito \n");
	return (0);
}
