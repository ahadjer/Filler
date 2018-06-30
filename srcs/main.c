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

char	*get_player(t_env *env, char *line)
{
	get_next_line(0, &line);
	env->player = ft_strstr(line, "exec p1") ? 'O' : 'X';
	env->enemi = ft_strstr(line, "exec p1") ? 'X' : 'O'; 
	dprintf(2, "%s\n", line);
	dprintf(2, "player = %c\n", env->player);
	dprintf(2, "enemi = %c\n", env->enemi);
	return (line);
}

char	*get_map_size(t_env *env, char *line)
{
	int		i;
	char	**w;

	get_next_line(0, &line);
	if (!ft_strstr(line, "Plateau"))
		get_next_line(0, &line);
	dprintf(2, "%s\n", line);
	i = ft_strlen(line);
	line[i - 1] = '\0';
	w = ft_strsplit(line, ' ');
	env->map_x = ft_atoi(w[2]);
	env->map_y = ft_atoi(w[1]);
	dprintf(2, "mapx: %d\nmapY %d\n", env->map_x, env->map_y);
	return (line);
}

void	init_map(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->map = (t_flag **)ft_memalloc(sizeof(t_flag *) * env->map_x)))
		exit(0);
	while (i < env->map_x)
	{
		if (!(env->map[i] = (t_flag*)ft_memalloc(sizeof(t_flag) * env->map_y)))
		exit(0);
		i++;
	}
}

char	*get_map(t_env *env, char *line)
{
	int		x;
	int		y;

	get_next_line(0, &line);
	y = 0;
	while (!ft_strstr(line, "000 "))
		get_next_line(0, &line);
	while (y < env->map_y)
	{
		x = 0;
		line += 4;
		while (x < env->map_x)
		{
			env->map[x][y].sign = line[x];
			x++;
		}
		y++;
		get_next_line(0, &line);
	}
	return (line);
}

char	*get_piece_size(t_env *env, char *line)
{
	int		i;
	char	**p;

	
	line = 0;
	if (!ft_strstr(line, "Piece "))
	{
		dprintf(2, "fuck %s\n", line);
	
		get_next_line(0, &line);
	}
	dprintf(2, "hello\n");
	dprintf(2, "pouet %s\n", line);
		
	i = ft_strlen(line);
	line[i - 1] = '\0';
	p = ft_strsplit(line, ' ');
	env->piece_x = ft_atoi(p[2]);
	env->piece_y = ft_atoi(p[1]);
	dprintf(2, "p_x : %d\np_y : %d\n", env->piece_x, env->piece_y);
	return (line);
}

void	init_piece(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->piece = (char **)ft_memalloc(sizeof(char *) * env->piece_x)))
		exit(1);
	while (i < env->piece_x)
	{
		if (!(env->piece[i] = (char*)ft_memalloc(sizeof(char) * env->piece_y)))
			exit(1);
		i++;
	}
}

char	*get_piece(t_env *env, char *line)
{
	int		x;
	int		y;

	while (!ft_strstr(line, "Piece "))
		get_next_line(0, &line);

	y = 0;
	get_next_line(0, &line);	
	dprintf(2, "hello  %s\n", line);
	
	while (y < env->piece_y)
	{
		dprintf(2, "here %s\n", line);
		x = 0;
		while (x < env->piece_x)
		{
			dprintf(2, "x -> %d y -> %d\n", x, y);
			env->piece[x][y] = line[x];
			x++;
		}
		get_next_line(0, &line);
		y++;
	}
	return (line);
}

void play()
{
	//...
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


void	init_env(t_env *env)
{
	env->player = 0;
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
	get_next_line(0, &line);
	line = get_map(&env, line);	
	debug_show_map(&env);

	line = get_piece_size(&env, line);
	dprintf(2,"END \n");
	
	init_piece(&env);
	dprintf(2,"END \n");	
	
	get_piece(&env, line);
	//calculate_score(&env);
	//put_piece(&env);
	dprintf(2, "%d %d\n", env.pos_y, env.pos_x);	
	dprintf(2, "%s %s\n", ft_itoa(env.pos_y), ft_itoa(env.pos_x));
	return (0);
}
