#include "my_huffman_tree.h"

/* Huffman encoding
 * https://brilliant.org/wiki/huffman-encoding/
 * variable-length
 * coding depende on frequency, shorter for more freuqent symbol
 * number of bits to encode given message will be shorter than fixed-length code
 * unambiguous, code for any particular symbol is never a prefix of the bit string representing any other symbol
 * build prefix tree from bottom up, 
    1) Take a list of symbols and their probabilities.
    2) Select two symbols with the lowest probabilities (if multiple symbols have the same probability, select two arbitrarily).

    3) Create a binary tree out of these two symbols, labeling one branch​ with a "1" and the other with a "0". It doesn't matter which side you label 1 or 0 as long as the labeling is consistent throughout the problem (e.g. the left side should always be 1 and the right side should always be 0, or the left side should always be 0 and the right side should always be 1).

    4) Add the probabilities of the two symbols to get the probability of the new subtree.

    5) Remove the symbols from the list and add the subtree to the list.

    6) Go back through the list and take the two symbols/subtrees with the smallest probabilities and combine those into a new subtree. Remove the original symbols/subtrees from the list, and add the new subtree to the list.

    7) Repeat until all of the elements are combined.		
*/




