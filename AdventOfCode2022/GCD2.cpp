#include "AoCHeader.h"

int GCDcpp1(int a, int b) {

	int higher;
	int lower;
	int remainder;

	if (b > a) { 
		higher = b;
		lower = a;
	} else {
		higher = a;
		lower = b;
	}

	while (lower > 0) {

		remainder = higher % lower;
		higher = lower;
		lower = remainder;

	}

	return higher;
}