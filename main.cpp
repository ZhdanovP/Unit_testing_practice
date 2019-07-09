#include <iostream>

#define TEST_C(name) void _##name()

#define RUN_TEST_C(name) _##name()

#define EXPECT_TRUE(x) \
	if(x) { \
		std::cout << __func__ << " PASSED.\n"; \
	} else { \
		std::cout << __func__ << " FAILED.\n"; \
	}

#define EXPECT_FALSE(x) \
	if(x) { \
		std::cout << __func__ << " FAILED.\n"; \
	} else { \
		std::cout << __func__ << " PASSED.\n"; \
	} 


template<typename T>
T sum(const T& x, const T& y) {
	return x + y;
}

auto lambda_sum = [](const unsigned int x, const unsigned int y) -> decltype(x + y) {
	if(x < y) {
		return 0;
	}
	return x - y;
};

TEST_C(Test1_example) {
	const int expected = 7;
	const int value = sum(2, 5);
	EXPECT_TRUE(expected == value);
}

TEST_C(Test1_lambda_example) {
	const int expected = 3;
	const int value = lambda_sum(5, 2);
	EXPECT_TRUE(expected == value);
}

int main() {
	RUN_TEST_C(Test1_example);
	RUN_TEST_C(Test1_lambda_example);
}

