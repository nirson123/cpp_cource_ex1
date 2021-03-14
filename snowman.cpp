//
// Created by nir son on 02/03/2021.
//

#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>
#include <cmath>


using namespace std;

namespace ariel {

    const int valid_code_length = 8;
    const int desimal_bace = 10;
    const int max_valid_digit_in_code = 4;
    const int min_valid_digit_in_code = 1;

    int extract_digit_at(int long_num , int i){
        return (long_num % int(pow(desimal_bace, valid_code_length - i ))) / int(pow(desimal_bace,valid_code_length - i - 1));
    }

    bool check_valid_snowman_code(int code) {
        if(to_string(code).length() != valid_code_length) {return false;}

        for(int i = 0 ; i < valid_code_length ; i++){
            int digit = extract_digit_at(code , i);
            if( digit > max_valid_digit_in_code || digit < min_valid_digit_in_code) {return false;}
        }
        return true;
    }

    string snowman(int code) {

        if (!check_valid_snowman_code(code)) {throw out_of_range("not a valid snowman code");} //check the code is valid

        //define the "library" of parts
        const array<string, 4> hats  = {" _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
        const array<string, 4> noses = {",",       ".",                "_",                 " "};
        const array<string, 4> eyes = {".",       "o",                "O",                 "-"};
        const array<string, 4> left_arms = {"<",       "\\",               "/",                 " "};
        const array<string, 4> right_arms = {">",       "/",                "\\",                " "};
        const array<string, 4> torsos = {"( : )",   "(] [)",            "(> <)",             "(   )"};
        const array<string, 4> bases = {" ( : ) ", " (\" \") ",          " (___) ",           " (   ) "};

        //define positions in the code
        const int hat = 0;
        const int nose = 1;
        const int left_eye = 2;
        const int right_eye = 3;
        const int left_arm = 4;
        const int right_arm = 5;
        const int torso = 6;
        const int base = 7;

        //string s_code = to_string(code);

        //hat
        string snowman = hats.at( extract_digit_at(code , hat)- 1) + "\n";

        //second level
        string mid_part = "(" + eyes.at( extract_digit_at(code , left_eye)- 1) +
                          noses.at(extract_digit_at(code , nose) - 1) +
                          eyes.at(extract_digit_at(code , right_eye) - 1) + ")";
        snowman += (extract_digit_at(code , left_arm) == 2 ? left_arms.at(extract_digit_at(code , left_arm) - 1) : " ");
        snowman += mid_part;
        snowman += (extract_digit_at(code , right_arm) == 2 ? right_arms.at(extract_digit_at(code , right_arm) - 1) : " ");
        snowman += "\n";

        //third level
        snowman += ((extract_digit_at(code , left_arm) == 2 ? " " : left_arms.at(extract_digit_at(code , left_arm) - 1)) +
                   torsos.at(extract_digit_at(code , torso) - 1) +
                   (extract_digit_at(code , right_arm) == 2 ? " " : right_arms.at(extract_digit_at(code , right_arm) - 1)) + "\n");

        //base
        snowman += bases.at(extract_digit_at(code , base) - 1);

        return snowman;
    }
}