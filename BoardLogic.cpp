/*
 * name: Jonathan Schwarz
 * ID: 203672910
 */

#include "BoardLogic.h"
#include "PlayerHuman.h"


BoardLogic::BoardLogic(Board *game_board,  PlayerType *player, PlayerType *opponent) :
        player_turn(player), board(game_board), player_opponent(opponent){
}

vector<coordinates> BoardLogic::valid_moves() {
    int j, k, direction = 0;
    vector<Disc> list = player_turn->get_disc_list();
    for (int i = 0; i < list.size(); ++i) { // runs on a player's disc list.
        for (direction = 0; direction < 8; ++direction) { // runs in each direction once.
            j = list[i].getloc_x();
            k = list[i].getloc_y();
            check_direction(direction ,j ,k );
        }

    }
    check_double();
    return valid_points;
}

void BoardLogic::add_to_board(int i, int j) {
    Disc d;
    d = Disc(player_turn->get_symbol(),i,j);
    board->add_to_board(d,i,j);
    player_opponent->remove_disc(d);
    player_turn->add_disc(d);
}

bool BoardLogic::is_board_end(int i, int j) {
    return (1 > i || i > board->get_size() - 1) || (1 > j || j > board->get_size() - 1);
}

bool BoardLogic::is_empty(int i, int j) {
    return board->get_board()[i][j].get_sym() == E;
}


bool BoardLogic::is_opponent(int i, int j) {
    return board->get_board()[i][j].get_sym() == player_opponent->get_symbol();
}

void BoardLogic::print_vec() {
    for (int i = 0; i < valid_points.size(); ++i) {
        cout <<'(' << valid_points[i].x << ',';
        cout << valid_points[i].y << ") ";
    }
    cout <<endl;
}

void BoardLogic::check_direction(const int &i, int &j, int &k) {
    int count = 0;
    int another_symbol_found = 0;
    coordinates coor;

    while (!is_board_end(j, k)) {
        if (is_empty(j, k) && count == 0) {
            break;
        }

        if (is_opponent(j, k)) {
            count++;
        }
        if(player_turn->get_symbol() == board->get_board()[j][k].get_sym()) {
            another_symbol_found++;
            if (another_symbol_found == 2) {
                break;
            }
        }

        if (is_empty(j, k) && count > 0) {
            coor.x = j;
            coor.y = k;
            valid_points.push_back(coor);
            break;
        }
        switch (i) { // checks the directions.
            case 0: j++;
                break;
            case 1: j++, k++;
                break;
            case 2: k++;
                break;
            case 3: j--, k++;
                break;
            case 4: j--;
                break;
            case 5: j--, k--;
                break;
            case 6: k--;
                break;
            case 7: j++, k--;
                break;
            default:break;
        }
    }
}

void BoardLogic::flipping(int j, int k) {
    int count = 0;
    int jsave = j;
    int ksave = k;
    for (int i = 0; i < 8; ++i) { // for each direction.
        count = 0;
        j = jsave;
        k = ksave;
        while (!is_board_end(j, k)) {

            if (is_empty(j, k) && count == 0) {
                break;
            }

            if (is_opponent(j, k)) {
                count++;
            }

            if (board->get_board()[j][k].get_sym() == player_turn->get_symbol() && count > 0) {
                for (int l = 0; l < count; ++l) { // runs back in each direction and changes the discs to the player's type discs.
                    switch (i) {
                        case 0:
                            j--;
                            add_to_board(j, k);
                            break;
                        case 1:
                            j--, k--;
                            add_to_board(j, k);
                            break;
                        case 2:
                            k--;
                            add_to_board(j, k);
                            break;
                        case 3:
                            j++, k--;
                            add_to_board(j, k);
                            break;
                        case 4:
                            j++;
                            add_to_board(j, k);
                            break;
                        case 5:
                            j++, k++;
                            add_to_board(j, k);
                            break;
                        case 6:
                            k++;
                            add_to_board(j, k);
                            break;
                        case 7:
                            j--, k++;
                            add_to_board(j, k);
                            break;
                        default:
                            break;
                    }

                }
                break;
            }

            switch (i) { // checks the directions.
                case 0:
                    j++;
                    break;
                case 1:
                    j++, k++;
                    break;
                case 2:
                    k++;
                    break;
                case 3:
                    j--, k++;
                    break;
                case 4:
                    j--;
                    break;
                case 5:
                    j--, k--;
                    break;
                case 6:
                    k--;
                    break;
                case 7:
                    j++, k--;
                    break;
                default:
                    break;
            }
        }

    }
}

void BoardLogic::check_double() {

    for (int j = 0; j < valid_points.size(); ++j) {

        for (int k = 0; k < valid_points.size(); ++k) {

            if ((valid_points[j].y == valid_points[k].y) &&
                (valid_points[j].x == valid_points[k].x) && (j != k)) {
                valid_points.erase(valid_points.begin() + k);
            }
        }
    }
}

vector<coordinates> BoardLogic::getValidMoves() {
    return valid_points;
}

PlayerType *BoardLogic::getPlayerTurn() {
    return player_turn;
}

PlayerType *BoardLogic::getPlayerOpponent() {
    return player_opponent;
}

Board *BoardLogic::getBoard() {
    return board;
}

void BoardLogic::swapPlayers() {
    PlayerType* temp = player_turn;
    player_turn = player_opponent;
    player_opponent = temp;
}

BoardLogic::~BoardLogic() {
    delete board;
    delete player_turn;
    delete player_opponent;
}

void BoardLogic::clearVec() {
valid_points.clear();
}

