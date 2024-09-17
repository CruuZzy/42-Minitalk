/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 23:37:01 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/05/04 23:37:01 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	print_pid(void)
{
	pid_t	num_pid;

	num_pid = getpid();
	if (num_pid == 0)
		return ;
	ft_printf("\n┌-------------------┐\n");
	ft_printf("\n « PID [ ");
	ft_putnbr_fd(num_pid, 1);
	ft_printf(" ] »\n");
	ft_printf("\n└-------------------┘\n");
}

static void	handle_buffer(size_t *c, int *bit, char buff[BUFF_SIZE])
{
	if (*c >= 1024)
	{
		write(1, buff, *c);
		ft_memset(buff, 0, BUFF_SIZE);
		*c = 0;
		*bit = 7;
	}
}

static void	reception(int sig)
{
	static size_t	c = 0;
	static int		bit = 7;
	static char		buff[BUFF_SIZE] = {0};

	if (sig == SIGUSR1)
		buff[c] |= (1 << bit);
	else if (sig == SIGUSR2)
		buff[c] &= ~(1 << bit);
	if (bit == 0)
	{
		if (buff[c] == '\0')
		{
			write(1, buff, c);
			ft_memset(buff, 0, BUFF_SIZE);
			c = 0;
		}
		else
			c++;
		bit = 7;
	}
	else
	{
		bit--;
	}
	handle_buffer(&c, &bit, buff);
}

int	main(int argc, char **argv __attribute__((unused)))
{
	argv = NULL;
	if (argc != 1)
	{
		ft_printf("Ejecuta solo el ./Server sin mas parametros.\n");
		return (1);
	}
	else
	{
		print_pid();
		signal(SIGUSR1, reception);
		signal(SIGUSR2, reception);
		while (1)
		{
			pause();
		}
	}
	return (0);
}
