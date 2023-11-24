#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    int block_nums = n / blocksize;
    // iterate from block to block
    for (int i = 0; i < block_nums + 1; ++i) {
        for (int j = 0; j < block_nums + 1; ++j) {
            // transpose all data in the block[i][j] 
            for (int k = 0; (k < blocksize) && (i * blocksize + k < n); ++k) {
                for (int z = 0; (z < blocksize) && (j * blocksize + z < n); ++z) {
                    // calculation formula
                    // transpose: src[] -> blocks[i][j][k][z] -> blocks[j][i][z][k] -> dst[] 
                    dst[j * n * blocksize + z * n + i * blocksize + k] = src[i * n * blocksize + k * n + j * blocksize + z];
                }
            }
        }
    }
}
