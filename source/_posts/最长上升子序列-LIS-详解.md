title: 最长上升子序列(LIS)详解
author: liu_zhou
abbrlink: '6e153245'
date: 2020-05-17 09:20:55
tags:
---

# 定义

>最长上升子序列（Longest Increasing Subsequence，LIS），在计算机科学上是指一个序列中最长的单调递增的子序列。
<p align="right">引自百度百科</p>

# 状态与状态转移方程

最长上升子序列是序列，其状态是一维的，所以我们可以定义状态 f(i),表示以a[i]结尾的最长上升子序列

如果每一个元素都只考虑它本身，则以a[i]结尾的最长上升子序列长度为一，即它本身，则初始化
```
f[i] = 1
```

如果a[i]比a[j]大（i>j），则a[i]可以添加到以a[j]结尾的最长上升子序列的末尾，即
```
f[i] = max(f[i], f[j] + 1)
```
# 完整代码
```cpp
#include <cstdio>

const int MAXN = 100005;

int a[MAXN], f[MAXN], n, ans = -1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		f[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(a[i] > a[j] && f[j] + 1 > f[i]) {
				f[i] = f[j] + 1;
			}
		}
		if(ans < f[i]) {
			ans = f[i];
		}
	}
	printf("%d", ans);
	return 0;
}
```