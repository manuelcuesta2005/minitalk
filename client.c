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
#include <stdlib.h>
#include <unistd.h>

static volatile int	g_signal_received = 0;

static void	handle_signal(int signal)
{
	g_signal_received = signal;
}

static void	send_char(int pid_server, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_signal_received = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid_server, SIGUSR2) == -1)
				return (ft_printf("Error al enviar SIGUSR2 ❌\n"), exit(1));
		}
		else
		{
			if (kill(pid_server, SIGUSR1) == -1)
				return (ft_printf("Error al enviar SIGUSR1 ❌\n"), exit(1));
		}
		bit--;
		while (g_signal_received != SIGUSR1)
			usleep(100);
	}
}

static void	send_message(int pid_server, char *message)
{
	while (*message)
	{
		send_char(pid_server, (unsigned char)*message);
		message++;
	}
	send_char(pid_server, '\0');
	ft_printf("✅ Confirmación recibida del servidor.\n");
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		ft_printf("Uso: %s <PID del servidor> <mensaje>\n", argv[0]);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
	{
		ft_printf("Error: PID del servidor inválido ❌\n");
		return (1);
	}
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	send_message(pid_server, argv[2]);
	return (0);
}
