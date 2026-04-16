#pragma once

#include <ge211.hxx>

struct cell{
    int number = 0;
    bool available_numbers[9] = {true, true,true,true,true,true,true,true,true};
};

class Model
{
public:
    cell** initial;

    cell** player;

    cell** initial_board(void);

    cell** player_board(void);

    bool is_game_over(void) const{return false;}

    void play_move(int num, ge211::Posn<int>);

    explicit Model(int size = 9);
private:

    cell** create_board(void);

    void remove_available(cell**, int, int);

    void generate_board(cell**);

    cell** create_player_board(cell**);

    ge211::Posn<int> find_lowest(cell**);

    bool board_is_full(cell**);

};
