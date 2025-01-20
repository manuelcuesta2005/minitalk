/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:59:49 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/12/16 15:59:51 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Manejador de señal
void handle_signal(int signal) {
    printf("¡Recibí la señal %d!\n", signal);
}

int main() {
    // Registrar el manejador para SIGINT
    signal(SIGINT, handle_signal);

    printf("Presiona Ctrl + C para enviar SIGINT. Para salir, usa Ctrl + Z o cierra el programa.\n");
    while (1) {
        sleep(1); // Mantén el programa corriendo
    }

    return 0;
}
