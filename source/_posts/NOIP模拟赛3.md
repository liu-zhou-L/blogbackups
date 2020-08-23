title: NOIP模拟赛3
author: liu_zhou
abbrlink: ad1dd5a1
tags:
  - 模拟
categories: []
mathjax: true
date: 2020-07-28 17:40:00
---
# 挖矿 +

## 题目描述

*有N名矿工在挖矿。工厂预先给第i名矿工支付了Mi元工资，他每挖一吨矿需要消费Ki元头 余下的钱不足Ki元，他就停止挖矿。他每挖一吨矿，工厂会立即奖励他2元钱。奖励的钱于挖矿的消费。*

*给出矿工的信息，请你计算一下矿工们总共可以挖出多少吨矿，以及哪个矿工挖的矿最多。*

## 输入格式

*第1行：1个整数N，表示矿工的人数(1 ≤ N ≤ 70)*

*接下来2N行，每2行描述1名矿工。第1行是一字符串(长度不超过20个字符)，表示矿工的姓名，第2行 2个整数，分别表示Ki(12 ≤ Ki ≤ 400)和Mi(1 ≤ Mi ≤ 10000)*

## 输出格式

*第1行：1个整数，表示矿工们总共可以挖出多少吨矿*

*第2行：1个字符串，表示挖矿最多的矿工的姓名。如果多个矿工挖得一样多，输出最靠前的1个人。*

### 样例输入

```
4
Caterpie
12 33
Weedle
12 42
Pidgey
12 47
Rattata
25 71
```

### 样例输出

```
14
Weedle
```

## 数据范围与提示

*COCI16-17 2# Go*

## 分析

模拟求出每一个工人的最大挖矿数，累加并记录最大值即可

### AC代码

```cpp
#include <cstdio>

const int MAXN = 75;

struct node {
	char name[40];
	int k;
	int m;
	int s;
} workers[MAXN];

int n, sum = 0, maxn = 1;

int check(node worker) {//求最大挖矿数的函数
	while (worker.m >= worker.k) {
		worker.s++;
		worker.m -= worker.k;
		worker.m += 2; 
	}
	return worker.s;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d", workers[i].name, &workers[i].k, &workers[i].m);
		workers[i].s = check(workers[i]);
		sum += workers[i].s;
		if (workers[i].s > workers[maxn].s) {//记录最大值
			maxn = i;
		}
	}
	printf("%d\n%s", sum, workers[maxn].name);
	return 0;
}
```

# 最小乘积 ++

## 题目描述

*给出0~9这10个数字的个数，放在数组A中。A[0]表示数字0的个数，A[1]表示数字1的个数，...，A[9]表示数字9的个数。*

*你要用这些数字构造整数A和B，A恰好有W1位，B恰好有W2，允许A和B出现前导0。要求数字i在A和 B中出现的次数之和不超过A[i]。*

*数据保证数组A的元素之和至少为W1+W2*

*在所有的合法整数对A、B中，找出它们乘积最小的一对数。*

## 输入格式

*第1行：10个整数，表示数组A， 0 ≤ A[i] ≤ 20*

*第2行：1个整数，表示W1 1 ≤ W1 ≤ 9*

*第3行：1个整数，表示W2 1 ≤ W2 ≤ 9*

## 输出格式

*第1行：1个整数，表示A和B的最小乘积*

## 样例输入

```
0 1 1 2 1 1 0 0 0 0
2
3
```

## 样例输出

```
3042
```

## 分析

要让乘积尽量小，显然 $ a $ 和 $ b $ 都尽量小。利用贪心的思想，去构造数字 $ a $ 和 $ b $ 。
首先，题目设定允许有前导 $ 0 $ ，因此如果有数字 $ 0 $ ，**则尽量安排给位数小的数**(这一点在考试时没想到,丢了48分)，因为如果能够让 $ a $ 或者 $ b $ 成为 $ 0 $ ，则乘积可以达到理论上的最小值： $ 0 $ 
如果数字 $ 0 $ 的个数不能让 $ a $ 或者 $ b $ 变为0，把0全部安排给位数小的数，也比两边分配更优。可以把分配了
所有的 $ 0 $ 后剩余的位数当作需要构造的位数。
分配了数字 $ 0 $ ，再从小到大考虑其他分配其它的数字。显然，需要的数字的个数是 $ W1+W2 $ .我们先从 $ A $ 数组中从 $ 1 $ 到 $ 9 $ 的顺序把数字逐个存放在另一个数组 $ B $ 中，再轮流从 $ B $ 数组中取出数字填在 $ a $ 和 $ b $ 的各个数
位上。
当位数小的数填完之后，再把剩余的数字全部填在位数大的数中。


## AC代码

```cpp
#include <cstdio>

#define ll long long

int a[15], w[5];
ll num = 0, num_ = 0;

void Swap(int &one, int &two) {
	int temp = one;
	one = two;
	two = temp;
	return;
}

int main() {
	//freopen("minproduct.in", "r", stdin);
	//freopen("minproduct.out", "w", stdout);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d%d", &w[1], &w[2]);
	if (w[1] <= a[0] || w[2] <= a[0]) {//如果有一个元素可以为零,则直接输出零
		printf("0");
		return 0;
	}
	if (w[1] > w[2]) Swap(w[1], w[2]);//把长度小的放在第一个
	//printf("%d %d", w[1], w[2]);
	int index = 1;
	w[1] -= a[0]; //!!!--将0全部放入第一个元素中--!!!
	while (w[1] + w[2]) {//当两者没有都为零时
		while (w[1] + w[2]) {
			while (a[index] == 0) index++;//如果这一位数字用完了,就换下一个
			if (w[1] != 0) {//第一个元素还可以加时
				num = num * 10 + index;//在末尾增加index
				w[1]--;//剩余长度减一
				a[index]--;当前位置的数量减一
			}
			while (a[index] == 0) index++;
			if (w[2] != 0) {
				num_ = num_ * 10 + index;
				w[2]--;
				a[index]--;
			}
		}
	}
	//printf("%lld %lld\n", num, num_);
	printf("%lld", num * num_);
	return 0;
}
```

# 回文数组 **

## 题目描述

*给定有N个整数的数组A，下标从1到N。如果对每一个下标i均满足A[i] =A[N-i+1]，则称数组是回文的。*

*例如，数组A={1,2,3,2,1}就是回文数组。*

*如果数组A不是回文的，可以采用合并两个相邻元素的方法去得到回文数组。注意，每操作一次，数组的元素数量减少1。*

*例如，数组A={1,2,3}不是回文数组，但是通过合并A[1]和A[2]，得到{3,3}就是回文数组了。*

*显然，无论给出怎样的数组元素，最多经过N-1次操作，合并为一个数时，数组A一定是回文数组了。*

*因此，本题一定有解。*

*然而问题来了：对于给定的数组A，最少经过多少次操作，能让A变成回文数组？*

## 输入格式

*第1行：1个整数N，表示数组A的元素个数*

*第2行：N个空格分开的整数，表示数组A*

## 输出格式

*第1行：1个整数，表示最少的操作次数*

## 样例输入

```
4
1 4 3 2
```

## 样例输出

```
2
```

## 分析

~~左右横跳之术~~ 很明显,在这道题中因为是累加,较大数是无法变成较小数的,所以肯定是考虑将较小数累加为较大数,而边缘的数肯定不可能与中间的数对称,所以每次只考虑边缘的两个数,不同就累加较小数,直到左右数字相同或左右两个指针相遇

## AC代码

```cpp
#include <cstdio>

const int MAXN = 1e6 + 5;

int n, sum = 0;
long long a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int left = 1, right = n;//左右指针
	while (left < right) {//两侧指针没相遇时
		if (a[left] != a[right]) {//不同时需要改变某一侧的数
			if (a[left] < a[right]) {//累加较小数
				left++;
				a[left] += a[left - 1];
				sum++;
			} else if (a[left] > a[right]) {
				right--;
				a[right] += a[right + 1];
				sum++;
			}
		} else {//相同则左右指针同时向内收缩
			left++;
			right--;
		}
	}
	printf("%d", sum);
	/*puts("");
	for(int i = left; i <= right; i++) {
		printf("%lld ", a[i]);
	}*/
	return 0;
}
```

# 乌龟 ++++

## 题目描述

*一只乌龟由于智商低下，它只会向左或向右走，不过它会遵循主人小h的指令：F（向前走一步），T（掉头）。*

*现在小h给出一串指令，由于小h有高超的计算能力，他可以马上知道乌龟最后走到哪里。为了难倒小h，他的好朋友小c就说，现在让你修改其中n个指令，使得乌龟移动到离起点最远的地方。（修改是指“T”变成“F”，或“F”变成“T”,可以对同一个指令多次修改）。乌龟一开始在0点*

## 输入格式

*第1行:一个字符串S代表指令*

*接下来一行一个整数n，表示要修改的指令个数*

## 输出格式

*第1行：一个整数，表示乌龟所能移动到的最远距离。*

## 样例输入
```
FFFTFFF
2
```

## 样例输出
```
6
```

## 分析
这道题有两种解法,记忆化搜索和动态规划,这里讲解记忆化搜索

这道题用爆搜是很容易想到的,但超时就和想到一样容易(

记忆化是一个方法,这里用`f[i][j][k][l]`表示执行到第`i`条指令,已经修改了`j`条指令,距离原点为`k`(有正负两种情况),当前方向为`l`(0向左,1向右)的最远距离,函数参数同理

讨论一下决策方案,最基本的分为当前位置为`F`和为`T`两种情况,且分别有改和不改两种

设当前状态为`dfs(now,cnt,sum,fx)`
+ 当为`T`且要改时,则`now`加一,`cnt`加一,`sum`根据`fx`加一或减一,即`dfs(now + 1, cnt + 1, sum + ((fx == 0) ? 1 : -1), fx)`
+  当为`T`且不改时,则`now`加一,`cnt`和`sum`不变,`fx`变为相反值,即`dfs(now + 1, cnt, sum, (fx == 0) ? 1 : 0)`
+ 当为`F`且要改时,则`now`加一,`cnt`加一,`sum`不变,方向变为相反值,即`dfs(now + 1, cnt + 1, sum, (fx == 0) ? 1 : 0)`
+ 当为`F`且不改时,则`now`加一,`cnt`加一,`sum`根据`fx`加一或减一,即`dfs(now + 1, cnt, sum + ((fx == 0) ? 1 : -1), fx)`

除以上四种情况以外,也可选择将当前命令改变两次,则`cnt`加二其它不变,即`dfs(now, cnt + 2, sum, fx)`

如果`now`超过`s`的长加一或`cnt`超过`n`,都不符合,执行`return`

`f`数组为记忆化数组,如果当前情况计算过了,也`return`

如果`now`等于`s`的长加一,且`cnt`等于`n`,则此种情况计算完毕,将`sum`的绝对值与`ans`比较保存答案并`return`

## AC代码
```cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int MAXN = 105;

int n, len, ans = 0;
bool f[MAXN][55][MAXN << 1][2] = {};
char s[MAXN];

void dfs(int now, int cnt, int sum, int fx) {
	if (f[now][cnt][sum][fx]) return;
	f[now][cnt][sum][fx] = true;
	if (now > len + 1 || cnt > n) return;
	if (now == len + 1 && cnt == n) {
		ans = std::max(ans, abs(sum));
		return;
	}
	if(s[now] == 'T') {
		dfs(now + 1, cnt + 1, sum + ((fx == 0) ? 1 : -1), fx);
	}
	else {
		dfs(now + 1, cnt, sum + ((fx == 0) ? 1 : -1), fx);
	}
	if(s[now] == 'F') {
		dfs(now + 1, cnt + 1, sum, (fx == 0) ? 1 : 0);
	}
	else {
		dfs(now + 1, cnt, sum, (fx == 0) ? 1 : 0);
	}
	dfs(now, cnt + 2, sum, fx);
	return;
}

int main() {
	scanf("%s%d", s + 1, &n);
	len = strlen(s + 1);
	dfs(1, 0, 0, 0);//初始为执行到第1条指令,其它均为零
	printf("%d", ans);
	return 0;
} 
```