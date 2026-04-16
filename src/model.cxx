#include "model.hxx"
#include <iostream>

using namespace ge211;

Model::Model(int size)
{
    cell** board = initial_board();
    //sometimes the algorithm messes up generating the board and gets stuck
    // in a forever loop, so when it gets stuck it will return an incomplete
    // board, the while loop says to re-generate a board until it has a
    // complete board
    while(board_is_full(board) == false){
        board = create_board();
        generate_board(board);
    }
    initial = board;
    player = create_player_board(initial);
}

void Model::play_move(int num, ge211::Posn<int> pos){
    player[pos.x][pos.y].number = num;
}

cell** Model::player_board(void){
    return player;
}

cell** Model::create_player_board(cell** board){
    cell** ret = create_board();

    // I found the following random number function on stack overflow
    // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist9(1, 8);


    int count = 0;
    while(count < 50) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(dist9(rng) == 3){
                    ret[i][j].number = board[i][j].number;
                    count++;
                }
            }
        }
    }

    return ret;
}

cell** Model::create_board(void){
    cell** board = new cell*[9];

    for(int y = 0;y<9;y++){
        board[y] = new cell[9];
        for(int x = 0;x<9;x++){
            cell a;
            board[y][x] = a;
        }
    }
    return board;
}

cell** Model::initial_board(void){
    cell** board = create_board();

    generate_board(board);

    return board;
}

bool Model::board_is_full(cell** board){
    for(int x = 0; x < 9;x++){
        for(int y = 0;y <9;y++){
            if(board[x][y].number == 0){
                return false;
            }
        }
    }
    return true;
}

ge211::Posn<int> Model::find_lowest(cell** board){
    int max = 0;
    int a = 0;
    int b = 0;
    for(int x = 0;x<9;x++){
        for(int y = 0;y<9;y++){
            if(board[x][y].number == 0) {
                int count = 0;
                for (int z = 0; z < 9; z++) {
                    if (board[x][y].available_numbers[z] == false) {
                        count++;
                    }
                }
                if (count > max) {
                    max = count;
                    a = x;
                    b = y;
                } else if (count == max && rand() % 10 == 0) {
                    // randomly will sometimes say if count is equal to max
                    // then execute
                    max = count;
                    a = x;
                    b = y;
                }
            }
        }
    }
    return {a,b};
}

void Model::remove_available(cell** board, int x, int y){

    // find the index of the cells number
    int num = board[x][y].number - 1;
    if(board[x][y].number < 0){
        board[x][y].number = 0;
    }

    // remove the number from the rows and the columns of the board
    for(int i = 0; i<9; i++){
        board[i][y].available_numbers[num] = false;
        board[x][i].available_numbers[num] = false;
    }

    // right and down find which box the cell is in
    int right = x/3;
    int down = y/3;

    // remove the available numbers in the cells from the box
    for(int i = right * 3; i < right * 3 + 3;i++){
        for(int j = down * 3; j < down * 3 + 3;j++){
            board[i][j].available_numbers[num] = false;
        }
    }
}

void Model::generate_board(cell** board){

    // calculate a random number

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist9(1, 8);

    // assign x and y to 2 random numbers between 1 and 8

    int x = dist9(rng);
    int y = dist9(rng);

    // assign a random position on board to a random number

    board[x][y].number = dist9(rng);

    remove_available(board,x,y);

    // count is used to determine if we are in a forever loop

    int count = 0;

    while(board_is_full(board) == false){
        count++;

        // find lowest is used to find what cell has the least amount of
        // available moves. if there are multiple cells, it will return a
        // random one.

        ge211::Posn<int> pos = find_lowest(board);
        int a = 0;

        // to assign a to the first avaiable value in the cell

        for(int i = 0;i<9;i++){
            if(board[pos.x][pos.y].available_numbers[i] == true){
                a = i + 1;
            }
        }

        // assign the cells number to a

        board[pos.x][pos.y].number = a;

        // remove the available numbers from the rows, columns and the box of
        // pos.x and pos.y

        remove_available(board,pos.x,pos.y);

        // if the while loop gets stuck, (this is known using the count
        // variable) return.

        if(count > 80){
            return;
        }
    }
}