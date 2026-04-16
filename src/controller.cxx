#include "controller.hxx"

Controller::Controller()
        : model_(9),
          view_(model_),
          mouse(0,0),
          show(false)
{ }

ge211::Dims<int> Controller::initial_window_dimensions() const{
    ge211::Dims<int> window_dims = {548, 548};
    return window_dims;
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set, mouse, show);
}

void Controller::on_mouse_move(ge211::Posn<int> position){
    mouse = position;
}

void Controller::on_key(ge211::Key key){
    show = false;
    if (key.code() == 'q') { quit(); }

    // if aany key (other than 0) is pressed, then set the corresponding
    // board position to that key.

    if(key.code() == '1'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
        .number
        = 1;
    }
    if(key.code() == '2'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 2;
    }
    if(key.code() == '3'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 3;
    }
    if(key.code() == '4'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 4;
    }
    if(key.code() == '5'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 5;
    }
    if(key.code() == '6'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 6;
    }
    if(key.code() == '7'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 7;
    }
    if(key.code() == '8'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 8;
    }
    if(key.code() == '9'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 9;
    }

    // if the player presses return, set the bool show to true, show is used
    // in the view file to know when to display the wrong cells

    if(key.code() == '\r'){
        show = true;
    }

    // if the delete key is pressed then set the corresponding board position
    // to 0

    if(key.code() == '\b'){
        model_.player[(mouse.x - mouse.x % 61)/61][(mouse.y - mouse.y % 61)/61]
                .number
                = 0;
    }

    // if the space key is pressed then automatically solve the puzzle for
    // the player

    if(key.code() == ' '){
        for(int i = 0; i <9; i++){
            for(int j = 0;j <9;j++){
                model_.player[i][j].number = model_.initial[i][j].number;
            }
        }
    }

}