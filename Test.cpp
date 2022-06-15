#include "doctest.h"
#include "mat.hpp"

using namespace std;

string no_spaces(string input) {
    erase(input, ' ');
    erase(input, '\t');
    erase(input, '\n');
    erase(input, '\r');
    return input;
}

TEST_CASE("carpets"){

    SUBCASE("matrix"){

        shared_ptr<matrix> m1, m2, m3, m4;

        SUBCASE("good input"){

            CHECK_NOTHROW( m1 = createMat(9, 9));
            CHECK_NOTHROW( m2 = createMat(99, 9));
            CHECK_NOTHROW( m3 = createMat(3, 7));
            CHECK_NOTHROW( m4 = createMat(7, 3));

            CHECK_NOTHROW( carpet(m1, '@', '#'));
            CHECK_NOTHROW( carpet(m1, '$', 'D'));
            CHECK_NOTHROW( carpet(m1, '0', '1'));
            CHECK_NOTHROW( carpet(m1, '>', '>'));
        }
        SUBCASE("bad input"){

            CHECK_THROWS( m1 = createMat(8, 8));
            CHECK_THROWS( m1 = createMat(12, 5));
            CHECK_THROWS( m1 = createMat(3, 10));
            CHECK_THROWS( m1 = createMat(-1, 3));
            CHECK_THROWS( m1 = createMat(-1, 3));
            CHECK_THROWS( m1 = createMat(-1, 3));
            CHECK_THROWS( m1 = createMat(2, -2));
            CHECK_THROWS( m1 = createMat(2, 0));
            CHECK_THROWS( m1 = createMat(0, 3));
        }
    }
    SUBCASE("carpet"){

        CHECK(no_spaces(ariel::mat(7,7, '!', '$')) == no_spaces("!!!!!!!\n!$$$$$!\n!$!!!$!\n!$!$!$!\n!$!!!$!\n!$$$$$!\n!!!!!!!"));
        CHECK(no_spaces(ariel::mat(3, 5, '!', '!')) == no_spaces("!!!\n!!!\n!!!\n!!!\n!!!"));
        CHECK(no_spaces(ariel::mat(1, 1, '#', ')')) == no_spaces("#"));
        CHECK(no_spaces(ariel::mat(1, 1, '!', ')')) == no_spaces("!"));
        CHECK(no_spaces(ariel::mat(5,3, '!', '$')) != no_spaces("!!!!\n!$$$$!\n!$!!!$!\n!$!$!$!\n!$!!!$!\n!$$$$$!\n!!!!!"));
    }
}