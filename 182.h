#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  182.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:36
*/

/*  解决思路 & 复杂度
    sql题目，练习了group by语句和count，实现计数和分组.
    对groupby的限制要用having
*/

/*  Main函数入口
    select Email from Person group by Email having count(Email)>1
*/