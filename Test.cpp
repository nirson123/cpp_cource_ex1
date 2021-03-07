/*
 * unit tests for 'snowman' function
 *
 * by nir son
 */

#include "snowman.hpp"
#include "doctest.h"
#include <string>
#include <iostream>

using namespace ariel;

TEST_CASE("valid codes"){

    //random codes
    CHECK(snowman(11114411) == std::string(" _===_ \n (.,.) \n ( : ) \n (   ) "));
    CHECK(snowman(23311242) == std::string("  ___  \n ..... \n<(0_.)/\n<(   )/\n (\" \") "));
    CHECK(snowman(33232124) == std::string("   _   \n  /_\\  \n\\(o_0) \n (] [)>\n (   ) "));

    //simple same-digits codes , to make sure we cover every option
    CHECK(snowman(11111111) == std::string(" _===_ \n<(.,.)>\n<( : )>\n (   ) "));
    CHECK(snowman(22222222) == std::string("  ___  \n ..... \n\\(o.o)/\n\\(] [)/\n (\" \") "));
    CHECK(snowman(33333333) == std::string("   _   \n  /_\\  \n/(0_0)\\\n/(> <)\\\n (___)  "));
    CHECK(snowman(44444444) == std::string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
}
TEST_CASE("wrong code length"){
    /*valid codes are 8 digits long*/

    //less digits then needed
    CHECK_THROWS(snowman(1234123)); // 7 digits
    CHECK_THROWS(snowman(123)); // 3 digits
    CHECK_THROWS(snowman(1)); // 1 digit

    //more digits then needed
    CHECK_THROWS(snowman(123412341)); // 9 digits
    CHECK_THROWS(snowman(12341234123412)); // 10 digits
    CHECK_THROWS(snowman(12334123412341234)); // 16 digits , bigger then long max value
}
TEST_CASE("code with wrong digits"){
    /* the code should only have the digits 1,2,3,4 */

    //check wrong digit in every position
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111511));
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(11151111));
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(51111111));

    CHECK_THROWS(snowman(22202222)); // 0 is not a valid digit
    CHECK_THROWS(snowman(00000000));

    CHECK_THROWS(snowman(6789)); // wrong digits and wrong length
}
TEST_CASE("negative numbers"){

    CHECK_THROWS(snowman(-12341234)); // valid digits, but negative

    CHECK_THROWS(snowman(-1234)); // wrong length , and negative

    CHECK_THROWS(snowman(-12341235)); // wrong digit , and negative

}
