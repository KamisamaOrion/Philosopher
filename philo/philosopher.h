/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:45:21 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/19 23:46:04 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

typedef struct s_info
{
	int	nb_philo;
	int	t_te;
	int	t_ts;
	int	t_td;
	int	max;
}	t_info;

typedef struct s_philo
{
	t_info philo;
	pthread_mutex_t *print;
	int	i;
}	t_philo;

#endif
