#include "mat.hpp"
#include <stdexcept>

shared_ptr<matrix> createMat(int col, int row) {

    // invalid input
    if (row < 1 || col < 1) { throw std::invalid_argument("dont play with me this is invalid"); }
    if (row % 2 == 0 || col % 2 == 0) { throw std::invalid_argument("dont play with me this is invalid"); }

    if (row < 1 || col < 1) { return NULL; }

    //initiation
    shared_ptr<matrix> mat = std::make_shared<matrix>();

    mat -> col = col;
    mat -> row = row;

    mat -> start1.resize(col*row);

    return mat;
}


//troversing the matrix in spiral fassion and ading the data as should

void carpet(shared_ptr<matrix>& mat, char ch1, char ch2) {

    //setup
    int iter = 0;       //iterator
    int count = 0;      //counter
    int loop = 0;       //indication in to how 'deep' we are in the matrix
    int col = mat->col;
    int row = mat->row;
    char ch = ch1;      //wich charcter decorates current layer

    while (count < col * row) {

        for (int i = 0; (i < col - 2 * loop) && (count < col * row); i++) {        //right

            mat -> start1[iter] = ch;
            iter++;
            count++;
        }
        iter--;         //retret to the matrix'es bounds
        iter += col;    //get ready for next diraction

        for (int i = 0; i < (row - 1 - 2 * loop) && (count < col * row); i++) {    //down

            mat -> start1[iter] = ch;
            iter += col;
            count++;
        }
        iter -= col;
        iter--;

        for (int i = 0; i < (col - 1 - 2 * loop) && (count < col * row); i++) {   //left

            mat -> start1[iter] = ch;
            iter--;
            count++;
        }
        iter++;
        iter -= col;

        for (int i = 0; i < (row - 2 - 2 * loop) && (count < col * row); i++) {    //up

            mat->start1[iter] = ch;
            iter -= col;
            count++;
        }
        iter += col;
        iter++;

        ch == ch1 ? ch = ch2 : ch = ch1;  //fliping charcter for new layer     
        loop++;
    }
}

string ariel::mat(int col, int row, char ch1, char ch2) {

    //invalid input, see mat.hpp
    if ((ch1 < low || ch1 > high) || (ch2 < low || ch2 > high)) { throw std::invalid_argument("invalid charcter"); }

    string ans;  

    shared_ptr<matrix> mat = createMat(col, row);  //allocating memory, completely safe and efficent
                                                  //imbeded memory management 

    carpet(mat, ch1, ch2);             //ading the data as required

    for (int i = 0; i < row; i++) {    //constructing answere line ny line
        for (int j = 0; j < col; j++) {

            ans += mat -> start1[j + (i * col)];
        }
        ans += '\n';
    }

    return ans;
}