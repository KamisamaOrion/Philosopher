/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:40:55 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/19 23:47:43 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>

void	*call_me(void *info)
{
	t_philo	data;

	data = *(t_philo *)info;
	while (1)
	{
		pthread_mutex_lock(data.print);
		printf("%s\n %d\n", "coucou je suis le threadi :", data.i);
		pthread_mutex_unlock(data.print);
		usleep(1000000);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int	len;
	
	(void)av;
	(void)ac;
	len = 4;
	pthread_t *threads;
	pthread_mutex_t print;
	t_info	info;
	t_philo	**philo;

	info = (t_info) {4, 400, 200, 200, 0};
	philo = malloc(4 * sizeof(t_philo *));
	threads = malloc(4 * sizeof(pthread_t));
	memset((void *) threads, 0, 4 * sizeof(pthread_t));
	memset((void *) &print, 0, sizeof(pthread_mutex_t));
	while (0 < len--)
	{
		philo[4 - len] = malloc(sizeof(t_philo));
		philo[4 -len]->philo = info;
		philo[4 - len]->i = 4 - len;
		philo[4 - len]->print = &print;
		pthread_create(&threads[4 - len], NULL, call_me, (void *)philo[4 - len]);
	}
	len = 4;
	while (0 < len--)
		pthread_join(threads[4 - len], NULL);
}
