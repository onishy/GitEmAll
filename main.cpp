#include <iostream>
#include "tree.hpp"

int main() {
    GitEmAll::Branch br1;

    br1.update(1, "hemi");
    auto br2 = br1.fork(2, "unchi");
    br2.update(3, "oppai");
    br2.rename(4, "newname");
    br2.update(5, "hemi");
    br1.merge(6, br2, "ma-jisita");

    return 0;
}