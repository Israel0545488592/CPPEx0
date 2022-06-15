#ifndef _MAT_HPP_
#define _MAT_HPP_

#include <string>
#include <vector>
#include <memory>

using namespace std;

typedef struct matrix {

    //size
    int row;
    int col;
    vector<char> start1{}; //the data structure
    
}matrix;

shared_ptr<matrix> createMat(int, int);

void carpet(shared_ptr<matrix>& mat, char, char); //to ad the info as required 

namespace ariel { string mat(int, int, char, char); } //output function

//the ASCII interval of ligall input
#define low 33
#define high 126

#endif
