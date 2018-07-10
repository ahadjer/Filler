/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:27:04 by ahadjer           #+#    #+#             */
/*   Updated: 2018/06/28 00:00:19 by ahadjer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	init_env(t_env *env)
{
	env->player = 0;
}

void	debug_show_map(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			dprintf(2, "%c", env->map[x][y].sign);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	debug_show_piece(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->piece_y)
	{
		x = 0;
		while (x < env->piece_x)
		{
			dprintf(2, "%c", env->piece[x][y]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

void	debug_show_score(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->map_y)
	{
		x = 0;
		while (x < env->map_x)
		{
			dprintf(2, "%d", env->map[x][y].f);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
}

int		main(void)
{
	char	*line;
	t_env	env;

	init_env(&env);
	line = NULL;
	get_player(&env, line);
	get_map_size(&env, line);
	init_map(&env);
	while (get_next_line(0 ,&line))
	{
		env.high_score = -1;
		line = get_map(&env, line);
		line = get_piece_size(&env, line);
		init_piece(&env);
		get_piece(&env, line);
		calculate_score(&env);
		put_piece(&env);
	 	ft_putstr(ft_itoa(env.pos_y));
	 	ft_putstr(" ");
		ft_putstr(ft_itoa(env.pos_x));
	 	ft_putstr("\n");
	}
	return (0);
}
