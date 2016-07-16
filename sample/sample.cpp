#include <iostream>
#include "git_tree.hpp"

/* Example for creating a tree of Japanese Political Parties */

int main() {
    GitEmAll::Branch master;

    GitEmAll::Branch a = master.fork(1, "BranchA", "BranchA parted from master");
    GitEmAll::Branch b = a.fork(2, "BranchB", "BranchB parted from BranchA");
    a.update(3, "Hey!! What's up BranchA!");
    b.update(3, "Yay!! This is the update on BranchB!");

    GitEmAll::Branch c = a.fork(3, "BranchC", "Howdy!!! I'm BranchC!!");

    c.merge(4, a, "BranchC merged BranchA!!!");
    b.merge(5, c, "BranchB merged BranchC!!!");

    master.merge(6, b, "master merged BranchB!");

    return 0;
}