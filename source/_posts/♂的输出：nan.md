---
title: ♂的输出：nan
author: liu_zhou
tags: C++语法
categories: 杂项
abbrlink: 4c1b9ef7
date: 2020-03-20 08:17:01
---
## ~~声明：本文不♂~~  
最早见到NaN的时候我以为c++储存错了,
### 分明是一个浮点型，为何会输出字符啊
后来才知道才知道
### NaN（Not a Number，非数）是计算机科学中数值数据类型的一类值，表示未定义或不可表示的值。

**简单说就是出现了0/0这种操作**  
以下代码会输出nan：
```cpp
#include<cstdio>

int main() {
	double a = 0, b = 0, c;
	c = a / b;
	printf("%lf", c);
	return 0;
}
```
## inf
除nan以外，还有一种特殊输出输出，**inf**，其含义为**无穷大的数**，即n/0这类操作，如果是负数除以0，则会得到-inf  
输出inf的代码:
```cpp
#include<cstdio>

int main() {
	double a = 1, b = 0, c;
	c = a / b;
	printf("%lf", c);
	return 0;
}
```
输出-inf的代码:
```cpp
#include<cstdio>

int main() {
	double a = -1, b = 0, c;
	c = a / b;
	printf("%lf", c);
	return 0;
}
```