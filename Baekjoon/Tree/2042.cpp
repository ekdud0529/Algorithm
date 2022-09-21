#include <iostream>
using namespace std;

int n, m, k;
long long tree[1024 * 1024 * 2];
int tmpN = 0;

// 1. tree의 배열 크기 tmpN 구하기
// 1-1 tmpN = leaf 노드의 개수
// 1-2 tmpN * 2 == 실제 배열의 크기
// 2. tree 값 초기화
// 2-1. inpur leafnode
// 2-2 Internal node 계산
// 3. update
// 4. 구간 합 구하기

void Update(int a, long long b)
{
	// a 번째 값 -> tmpN
	a = a + tmpN - 1;
	tree[a] = b;
	while (a > 1)
	{
		a = a >> 1;
		tree[a] = tree[a * 2] + tree[a * 2 + 1];
	}
}

long long getSum(int a, int b)
{
	a = a + tmpN - 1;
	b = b + tmpN - 1;
	long long sum = 0;

	while (a <= b)
	{
		// a -> right child? ->라면 오른쪽 부모로 올라감
		if ((a & 1) == 1) sum += tree[a];
		// b -> left child? -> 라면 왼쪽 부모로 올라감
		if ((b & 1) == 0) sum += tree[b];
		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}
	return (sum);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (tmpN = 1; tmpN < n; tmpN *= 2);
	for (int i = 0; i < n; i++)
	{
		cin >> tree[tmpN + i];
	}
	for (int i = tmpN + n; i < tmpN * 2; i++)
		tree[i] = 0;
	for (int i = tmpN - 1; i >= 1; i--)
	{
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	long long a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update(b, c);
		}
		else
		{
			cout << getSum(b, c) << "\n";
		}
	}
	return (0);
}
