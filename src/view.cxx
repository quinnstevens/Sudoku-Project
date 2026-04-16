#include "view.hxx"

View::View(Model const& model)
        : model_(model),
        brick_sprite({60,60}, {100,100,100}),
        select_brick_sprite({60,60}, {155,155,155}),
        red_brick_sprite({60,60}, {155,80,80}),
        green_brick_sprite({60,60}, {80,155,80}),
        background_brick_sprite({550,550}, {255,255,255}),
        vert_brick_sprite({1,550}, {0,0,0}),
        horz_brick_sprite({550,1}, {0,0,0}),
        one_sprite("1", sans28_),
        two_sprite("2", sans28_),
        three_sprite("3", sans28_),
        four_sprite("4", sans28_),
        five_sprite("5", sans28_),
        six_sprite("6", sans28_),
        seven_sprite("7", sans28_),
        eight_sprite("8", sans28_),
        nine_sprite("9", sans28_)
{ }

void
View::draw(ge211::Sprite_set& set, ge211::Posn<int> mouse_posn, bool show)
{
    ge211::Text_sprite::Builder count_builder(sans28_);

    set.add_sprite(background_brick_sprite, {0,0}, -1);
    set.add_sprite(vert_brick_sprite, {61*3 - 1, 0}, 0);
    set.add_sprite(vert_brick_sprite, {61*6 - 1, 0}, 0);
    set.add_sprite(horz_brick_sprite, {0, 61*3 - 1}, 0);
    set.add_sprite(horz_brick_sprite, {0, 61*6 - 1}, 0);

    // display all of the numbers and their positions on screen
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ge211::Posn<int> text_pos = {22 + i * 61, 7 + j * 61};
            set.add_sprite(brick_sprite, {i*61,j*61},1);
            if (model_.player[i][j].number == 1) {
                set.add_sprite(one_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 2) {
                set.add_sprite(two_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 3) {
                set.add_sprite(three_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 4) {
                set.add_sprite(four_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 5) {
                set.add_sprite(five_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 6) {
                set.add_sprite(six_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 7) {
                set.add_sprite(seven_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 8) {
                set.add_sprite(eight_sprite, text_pos, 4);
            }
            if (model_.player[i][j].number == 9) {
                set.add_sprite(nine_sprite, text_pos, 4);
            }
        }

        // display the row and column of the cells in the selected box

        for(int i = 0; i<9; i++){
            set.add_sprite(select_brick_sprite, {i*61 - (i*61) %61, mouse_posn
            .y - mouse_posn.y % 61}, 2);
            set.add_sprite(select_brick_sprite, {mouse_posn.x - mouse_posn.x
            % 61,
                                                 i*61 - (i*61)%61},2);
        }
    }

    // if show is true then the enter key was pressed and this will display a
    // red box if the initial board and the player board don't match up, and
    // if the number != 0

    if(show == true){
        for(int i = 0; i < 9; i++){
            for(int j = 0;j<9;j++){
                if(model_.player[i][j].number != model_.initial[i][j].number
                && model_.player[i][j].number != 0){
                    set.add_sprite(red_brick_sprite, {i * 61 - (i*61) %61,
                                                      j*61 -
                                                              (j*61)%61}, 3);
                }
            }
        }
    }

    // the following code evaluates both board, and if they are equal to each
    // other. if they are, it will display a green box on every cell.

    int count = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0;j<9;j++){
            if(model_.player[i][j].number == model_.initial[i][j].number
               && model_.player[i][j].number != 0){
                count++;
            }
        }
    }
    if(count == 81){
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                set.add_sprite(green_brick_sprite, {i * 61, j * 61}, 3);
            }
        }
    }

}
