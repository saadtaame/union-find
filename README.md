# union-find
A C/C++ implementation of union by rank and find with path compression. The operations are fast and the implementation uses one array only. Applications include connectivity tests and finding minimum spanning trees (to name a few).

# API
* `init(); // Initialize module`
* `int root(int x); // Returns the representative of the disjoint set containing x`
* `void join(int x, int y); // Unify the sets containing x and y`
