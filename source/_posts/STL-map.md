title: STL-map
author: liu_zhou
abbrlink: bbf9d7b7
tags:
  - map
categories:
  - 数据结构
date: 2020-06-20 14:34:00
---
# 概念
`Map`是`STL`的一个关联容器，它提供一对一（其中第一个可以称为关键字，每个关键字只能在`map`中出现一次，第二个可能称为该关键字的值）的数据处理能力，由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。

## 个人理解

`map`可以看做一个特殊的数组，其下标可以为任意类型，即`key`

# 基本操作
## 定义
```cpp
map<Type, Type> dictionary
```
## 常用成员函数
### erase
删除指定`map`中指定的元素

```cpp
dictionary.erase("an") //删除键为“an”的元素
dictionary.erase(map_it) //删除迭代器指向的的元素
```
### insert
在`map`中添加元素

```cpp
maplive.insert(pair<int,string>(321,"hai"));//插入一个元素，key为321，value为hai
maplive.insert(map<int,string>::value_type(321,"hai"));//同上
//另:
maplive[112]="April";//map中最简单最常用的插入添加
```
### find
在`map`中查找关键`key`，当所查找的关键`key`出现时，它返回数据所在对象的位置，如果沒有，返回值与`end`函数的值相同
```cpp
//在map中寻找key为"123"的元素，并返回其value
map<string, int>::iterator iter = dictionary.find("123");
 
if(iter != dictionary.end()) {
	printf("Find, the value is %d\n", iter->second);
}
else {
	printf("Do not Find\n");
}
```