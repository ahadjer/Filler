



void check_score (map, x, y)
{

    if (map[x][y] == char_enemy)
    {
        if (y - 1 < 0)//up
        {
            map[x][y-1].sign = 1;
        }
        if (y + 1 < map_size_y)//bottom
        {
            map[x][y+1].sign = 1;
        }
        



    }

}


void calculate_score()
{
    while y

        while x

            check_score(map, x, y);

            //if (x > 0 && y > 0 && )


}
