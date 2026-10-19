#include <cinttypes>
#include <cstdio>
#include <cstdint>
#include <vector>

/*
 * 寻找严格小于正整数 max 的所有素数
 */
void eratosthenes(uint64_t max, std::vector<uint64_t>& res)
{
	res.clear();
	if (max <= 2)
		return;

	std::vector<bool> is_prime(max, true);
	is_prime[0] = false;
	is_prime[1] = false;

	// 等价于 p * p < max，但不会在条件表达式中发生乘法溢出。
	for (uint64_t p = 2; p <= (max - 1) / p; ++p) {
		if (!is_prime[p])
			continue;

		// 小于 p * p 的倍数已经被更小的素因子筛除。
		for (uint64_t multiple = p * p; multiple < max; ) {
			is_prime[multiple] = false;
			if (multiple > (max - 1) - p)
				break;
			multiple += p;
		}
	}

	for (uint64_t i = 2; i < max; ++i) {
		if (is_prime[i])
			res.push_back(i);
	}
}

int main()
{
	std::vector<uint64_t> res;
	eratosthenes(300, res);

	for (uint64_t n : res)
		std::printf("%" PRIu64 " ", n);
	std::printf("\n");

	return 0;
}
