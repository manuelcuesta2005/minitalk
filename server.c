/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:08:29 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/12/16 20:11:00 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int	g_bit_count = 0;

static void	handler_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;

	(void)context;
	character <<= 1;
	if (signal == SIGUSR2)
		character |= 1;
	g_bit_count++;
	if (g_bit_count == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_printf("Error al enviar confirmación al cliente ❌\n");
		}
		else
			write(1, &character, 1);
		character = 0;
		g_bit_count = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf("Error al enviar ACK al cliente ❌\n");
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Iniciando servidor... \n");
	ft_printf("PID: %d \n", getpid());
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error al configurar los manejadores de señales ❌\n");
		exit(1);
	}
	while (1)
		pause();
}
