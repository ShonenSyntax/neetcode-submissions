#include <set>
using namespace std;

bool check_row(vector<vector<char>>& board){ 
    for(int i = 0; i < board.size(); i++){
        set<char> my_row;

        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == '.')
                continue;

            if(my_row.find(board[i][j]) != my_row.end())
                return false;

            my_row.insert(board[i][j]);
        }   
    }
    return true;
}

bool check_column(vector<vector<char>>& board){
    for(int j = 0; j < board[0].size(); j++){
        set<char> my_column;

        for(int i = 0; i < board.size(); i++){
            if(board[i][j] == '.')
                continue;

            if(my_column.find(board[i][j]) != my_column.end())
                return false;

            my_column.insert(board[i][j]);
        }   
    }
    return true;
}

bool check_box(vector<vector<char>>& board){
    for (int start_row = 0; start_row < 9; start_row += 3) {
        for (int start_col = 0; start_col < 9; start_col += 3) {

            set<char> my_box;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    char current = board[start_row + i][start_col + j];

                    if (current == '.')
                        continue;

                    if (my_box.find(current) != my_box.end())
                        return false;

                    my_box.insert(current);
                }
            }
        }
    }

    return true;
}


class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board){ //each cell is a char
            
            if( (check_row(board)) && (check_column(board)) && (check_box(board)) )
                return true;
            else
                return false; 
    }
};