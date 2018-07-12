/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadjer <ahadjer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:27:04 by ahadjer           #+#    #+#             */
/*   Updated: 2018/07/12 23:06:03 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	init_env(t_env *env)
{
	env->player = 0;
	env->map = NULL;
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
	get_player(&env, &line);
	get_map_size(&env, &line);
	init_map(&env);


	while (get_next_line(0 ,&line))
	{
		// if ()
		debug_show_map(&env);
		debug_show_score(&env);
		env.high_score = -1;
		env.pos_x = 0;
		env.pos_y = 0;
		dprintf(2, "here : %s\n", line);
		dprintf(2, "here BLABLABLABLA : %s\n", line);
		get_map(&env, &line);
		dprintf(2, "here 6 : %s\n", line);
		get_piece_size(&env, &line);
		init_piece(&env);
		get_piece(&env, &line);
		dprintf(2, "here 10 : %s\n", line);
		// calculate_score(&env);
		put_piece(&env);
		// ft_putstr("0 0\n");
		dprintf(2, "score => %d\n", env.high_score);
		dprintf(2, "POS PUT x:%d  y:%d\n", env.pos_x, env.pos_y);
		ft_putstr(ft_itoa(env.pos_y));
		ft_putstr(" ");
		ft_putstr(ft_itoa(env.pos_x));
		ft_putstr("\n");

		// exit(0);

	}


	// while (get_next_line(0 ,&line) && i < 100)
	// {
	// 	dprintf(2, "here : %s\n", line);
    //
	// 	if (i == 5)
	// 		ft_putstr("0 0\n");
	// 	i++;
	// }







	// get_next_line(0, &line);

	// dprintf(2, "player = %c\n", env.player);
	// dprintf(2, "enemi = %c\n", env.enemi);


	// while (get_next_line(0 ,&line))
	// {
	// 	env.high_score = -1;
	// 	line = get_map(&env, line);
	// 	line = get_piece_size(&env, line);
	// 	init_piece(&env);
	// 	get_piece(&env, line);
	// 	calculate_score(&env);
		// put_piece(&env);
    //
	// 	break;

		// dprintf(2, "HELLO########1\n");
		// dprintf(2, "move x: %d  y: %d\n", env.pos_x, env.pos_y);

		// dprintf(2, "putain %d\n", env.pos_y);
		// char *x = ft_itoa(env.pos_y);
		// dprintf(2, "putain 2 %s\n", x);
		// ft_putstr(" ");
		// ft_putstr(ft_itoa(env.pos_x));
	 	// ft_putstr("\n");
		// dprintf(2, "HELLO########4\n");
	// }

	// dprintf(2, "END########\n");
	return (0);
}
