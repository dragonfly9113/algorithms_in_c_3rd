/* Program 1.3 Weighted version of quick union
    This program is a modification to the quick-union
    algorithm that keeps an additional array sz for 
    the purpose of maintaining, for each object with
    id[i] = i, the number of nodes in the associated
    tree, so that the union operation can link the
    smaller of the two specified trees to the larger,
    thus preventing the growth of long paths in the tree.

Pseudo code:
1. for i = 0 to id.length-1
2.     id[i] = i
3.     sz[i] = 1    // at begining, all nodes are root nodes with size 1.
4. while there is valid pair: p q
5.     from i = p, iterate through i = id[i] until i == id[i] // find the root from p
6.     from j = q, iterate through j = id[j] until j == id[j] // find the root from q
7.     if i == j        // p and q have the the same root: they are already connected
8.         continue
9.     if sz[i] < sz[j]
10.        id[i] = j    // merge the smaller tree to largner one
11.        update sz[j] with new size   // no need to update sz[i] since i is no longer root node
12.    else
13.        id[j] = i    // merge the smaller tree to larger one
14.        update sz[i] with new size
15.    print p and q    // print out pair representing objects that are not yet connected

Note:
    * An additional array sz[N] is added to track the size of trees of each root node.
    * Find operation is the same.
    * Union operation is a little more complex: try to merge the smaller tree to larger instead of arbitrary merging.
    * Array sz needs to be updated after each merge to keep size info accurate.
*/

#include <stdio.h>
#define N 10

int main()
{
    int i, j, p, q, t, id[N], sz[N];

    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (scanf("%d %d", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;

        if (i == j) continue;   // find is a little slower.

        if (sz[i] < sz[j]) {    // Merge smaller tree to larger tree and update sz array.
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }

        printf(" %d %d\t", p, q);
        // Print out the current values of id[]:
        for (i = 0; i < N; i++)
            printf(" %d", id[i]);
        printf("\n");
    }

    return 0;
}
