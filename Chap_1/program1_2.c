/* Program 1.2 Quick-union solution to connectivity problem
    The for loops and subsequent if statement in this code
    specify the necessary the sufficent conditions on the
    id array for p and q to be connected. The assignment
    statement id[i] = j implements the union operation.

Psudo code:
1. for i = 0 to id.length-1
2.     id[i] = i
3. while there is valid pair: p q
4.     from i = p, iterate through i = id[i] until i == id[i] // find the root from p
5.     from j = q, iterate through j = id[j] until j == id[j] // find the root from q
6.     if i == j        // p and q have the the same root: they are already connected
7.         continue
8.     id[i] = j        // union: set a new root (j) for i (i will no longer be root)
9.     print p and q    // print out pair representing objects that are not yet connected

Note: this solution can do union quickly: id[i] = j. But the find operation can take
some time because it needs to find the root of p and q.
*/

#include <stdio.h>
#define N 10

int main()
{
    int i, j, p, q, t, id[N];

    for (i = 0; i < N; i++)
        id[i] = i;

    while (scanf("%d %d", &p, &q) == 2)
    {
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;

        if (i == j) continue;   // find is a little slower.

        id[i] = j;      // union is fast!

        printf(" %d %d\t", p, q);
        // Print out the current values of id[]:
        for (i = 0; i < N; i++)
            printf(" %d", id[i]);
        printf("\n");
    }

    return 0;
}
