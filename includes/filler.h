#ifndef FILLLER_H
# define FILLLER_H

#include "../libft/includes/libft.h"

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
	int				best_score;

}                   t_env;

void                get_player(t_env *env, char *line);
void                get_map_size(t_env *env, char *line);
void                get_map(t_env *env, char *line);
void                get_piece_size(t_env *env, char *line);
void                get_piece(t_env *env, char *line);
void                solver(t_env *env);

#endif
