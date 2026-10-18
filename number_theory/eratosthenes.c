#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
 * 判断一个正整数是否为素数
 */
int is_prime(uint64_t n)
{
	double sq;
	uint64_t nq;
	
	sq = sqrt((double)n);
	nq = (uint64_t)sq;

	uint64_t i = 2;
	for (; i <= nq; i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

/*
 * 寻找小于等于正整数max的所有素数
 */
void eratosthenes(uint64_t max, uint64_t *res, int *count)
{
	double sq;
	uint64_t nq;
	int c = 0, _count = *count;

	sq = sqrt(max);
	nq = (uint64_t)sq;

	uint64_t i = 2;
	for (; i <= max; i++) {
		if (c >= _count)
			break;
		if (i <= nq && is_prime(i)) {
			res[c++] = i;
		} else {
			
		}
	}

	*count = c;
}

int main(int argc, char **argv)
{


	return 0;
}
