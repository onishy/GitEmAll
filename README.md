# Go Git 'Em All!!!!!!
GitEmAll is a visualizer of any forking-and-merging-branch stuffs.
But sorry, visualizing isn't my business.

# What you need
- you need to install `git` and visualizer of git trees (`gitk`, `gitx`, and SourceTree may be popular).

# How to use
You can do the following actions to the branch.

- `update`: commit the message to the branch.
- `fork`: fork the new branch from another.
- `merge`: merge 2 branches.
- `rename`: rename the branch (fork is recommended)

See `sample/sample.cpp` or `japanese_political_parties.cpp` for how to call functions.

Once written the main.cpp, compile and run as follows.

1. `g++ main.cpp -std=c++1y`
1. `mkdir graph; cd graph`
1. `../a.out | sh`
1. `gitk`, `git log --graph` or launch gitx or SourceTree to see the graph.