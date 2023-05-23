#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

int get_bit(uint16_t x, size_t n) {
	return ((x >> n) & 1);
}

void set_bit(uint16_t *x, size_t n, int value) {
	*x &= ~(1 << n);
	*x |= (value << n);
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
	int bit_zero = get_bit(*reg, 0);
	int bit_two = get_bit(*reg, 2);
	int bit_three = get_bit(*reg, 3);
	int bit_five = get_bit(*reg, 5);
	*reg >>= 1;
	int msb = bit_zero ^ bit_two ^ bit_three ^ bit_five;
	set_bit(reg, 15, msb);
}

