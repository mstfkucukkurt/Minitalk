/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkucukku <mkucukku@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:21:31 by mkucukku          #+#    #+#             */
/*   Updated: 2022/04/12 16:21:57 by mkucukku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_byte(int *byte, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (byte[i] == 1)
			kill(pid, SIGUSR2);
		else if (byte[i] == 0)
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	sig_fback(int signum, siginfo_t *siginfo, void *unused)
{
	char	*mess;

	(void)unused;
	(void)siginfo;
	mess = "Signal Delivered\n";
	if (signum == SIGUSR2)
		write(1, mess, ft_strlen(mess));
	else
		free(mess);
}

int	main(int argc, char **argv)
{
	int					i;
	int					spid;
	t_client			client;
	struct sigaction	act;

	if (argc != 3)
		return (0);
	spid = ft_atoi(argv[1]);
	client.p_id = spid;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_fback;
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr_fd("Sending to : ", 1);
	ft_putnbr_fd(spid, 1);
	ft_putchar_fd('\n', 1);
	i = 0;
	while (argv[2][i])
	{
		client.numbers = ascii_byte((unsigned char)argv[2][i]);
		send_byte(client.numbers, spid);
		free(client.numbers);
		i++;
	}
	return (0);
}
