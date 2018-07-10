#ifndef FILLLER_H
# define FILLLER_H

#include "../libft/includes/libft.h"
#include <stdio.h>

typedef	struct		s_flag
{
	char			sign;
	int				f;
}					t_flag;

typedef struct      s_env
{
    char            player;
    char            enemi;
    int             map_x;
    int             map_y;
    t_flag          **map;
    int             piece_x;
    int             piece_y;
    char            **piece;
    int             pos_x;
    int             pos_y;
		int							high_score;

}                   t_env;

char                *get_player(t_env *env, char *line);
char                *get_map_size(t_env *env, char *line);
char                *get_map(t_env *env, char *line);
char                *get_piece_size(t_env *env, char *line);
char                *get_piece(t_env *env, char *line);
void                solver(t_env *env);
void                check_score (t_env *env, int x, int y);
void                calculate_score(t_env *env);
void                put_piece(t_env *env);
void								init_piece(t_env *env);
void								init_map(t_env *env);

#endif

// map[strlen([piece_x])][strlen([piece_y])]
