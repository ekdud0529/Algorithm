#include <iostream>
using namespace std;

struct matrix {
	unsigned long long a, b, c, d;
};

matrix Cal(matrix cal, matrix answer)
{
	return {
		(cal.a * answer.a + cal.b * answer.c) % 1000000,
		(cal.a * answer.b + cal.b * answer.d) % 1000000,
		(cal.c * answer.a + cal.d * answer.c) % 1000000,
		(cal.c * answer.b + cal.d * answer.d) % 1000000
	};
}

int	main(void)
{
	unsigned long long n;
	matrix cal = { 1, 1, 1, 0 };
	matrix answer = { 1, 0, 1, 0 };

	cin >> n;
	if (n <= 2)
	{
		cout << 1;
		return 0;
	}
	n -= 2;
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			answer = Cal(cal, answer);
		}
		cal = Cal(cal, cal);
	}
	cout << answer.a % 1000000;
	return (0);
}
