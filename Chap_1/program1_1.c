/* Program 1.1 Quick-find solution to connectivity problem
    This program reads a sequence of pairs of nonnegative
    integers less than N from standard input (interpreting
    the pair p q to mean "connect object p to object q")
    and prints out pairs representing objects that are 
    not yet connected. It maintains an array id that 
    has an entry for each object, with the property that
    id[p] and id[q] are equal if and only if p and q are
    connected.

Psudo code:
1. for i = 0 to id.length-1
2.     id[i] = i
3. while there is valid pair: p q
4.     if id[p] == id[q]    // if p and q are already connected - this is why this algorithm is called quick-find: very easy
5.         continue         // to check if two objects are already connected or not.
6.     for i to id.length-1
7.         if id[i] == id[p]
8.             id[i] = id[q]    // if any object is connected to p, connect it to q also
9.     print p and q    // print out pair representing objects that are not yet connected

*/

#include <stdio.h>
#define N 10

int main()
{
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++)
        id[i] = i;

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (id[p] == id[q])
            continue;
        
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t)
                id[i] = id[q];
        
        printf(" %d %d\t", p, q);
        // Print out the current values of id[]:
        for (i = 0; i < N; i++)
            printf(" %d", id[i]);
        printf("\n");
    }

    return 0;
}
