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
#include <signal.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

volatile sig_atomic_t bit_count = 0;
volatile sig_atomic_t current_char = 0;

void	handler_signal(int signal)
{
	if (signal == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;

	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}

}

int main()
{
	ft_printf("Iniciando servidor... \n");
	ft_printf("PID: %d \n", getpid());

	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
		pause();
}
