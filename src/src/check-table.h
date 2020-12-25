#ifndef CHECK_TABLE_H
#define CHECK_TABLE_H

const int case0[9] = {0,0,0, 0,0,0, 0,0,0};
const int case1[9] = {0,0,0, 1,0,0, 0,1,0};
const int case2[9] = {0,0,0, 0,0,1, 0,1,0};
const int case3[9] = {0,0,0, 1,1,1, 0,0,0};
const int case4[9] = {0,1,0, 0,0,1, 0,0,0};
const int case5[9] = {0,1,0, 1,0,1, 0,1,0};
const int case6[9] = {0,1,0, 0,1,0, 0,1,0};
const int case7[9] = {0,1,0, 1,0,0, 0,0,0};
const int case8[9] = {1,0,0, 1,0,0, 0,0,0};
const int case9[9] = {0,1,0, 0,1,0, 0,1,0};
const int case10[9] = {0,1,0, 1,0,1, 0,1,0};
const int case11[9] = {0,1,0, 0,0,1, 0,0,0};
const int case12[9] = {0,0,0, 1,1,1, 0,0,0};
const int case13[9] = {0,0,0, 0,0,1, 0,1,0};
const int case14[9] = {0,0,0, 1,0,0, 0,1,0};
const int case15[9] = {0,0,0, 0,0,0, 0,0,0};

const int* cases[16]={case0,case1,case2,case3,case4,case5,case6,case7,case8,case9,case10,case11,case12,case13,case14,case15};
#endif