/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:44:54 by scruz-ra          #+#    #+#             */
/*   Updated: 2024/05/06 20:44:54 by scruz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	send_b(pid_t pid, char c)
{
	int	b;

	b = 7;
	while (b >= 0)
	{
		if (c & (1 << b))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		b--;
	}
	return (0);
}

static int	send_str(pid_t pid_s, char *str)
{
	int	c;
	int	i;

	c = 0;
	while (str[c] != '\0')
	{
		if (send_b(pid_s, str[c]))
			return (1);
		++c;
	}
	i = 0;
	while (i < 8)
	{
		kill(pid_s, SIGUSR2);
		usleep(1000);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid_num;

	if (argc < 3 || argc > 3)
	{
		ft_printf("Solo 3 argumentos: ./a.out <PID> + Str. \n");
		return (1);
	}
	else if (argc == 3)
	{
		pid_num = ft_atoi(argv[1]);
		if (!pid_num)
		{
			ft_printf("El <PID> es Invalido.");
			return (1);
		}
		else if (pid_num)
			send_str(pid_num, argv[2]);
	}
	return (0);
}
