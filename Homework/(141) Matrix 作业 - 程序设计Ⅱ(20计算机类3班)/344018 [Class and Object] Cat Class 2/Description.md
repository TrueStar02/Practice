# [Class and Object] Cat Class 2

# Problem Description
Please design a class Cat, which contains the following public member variables and functions:
请设计类 Cat, 它包含下面的公有成员变量和函数:
char * name
Cat(const char * name)
Cat(const Cat & cat)
Cat & operator = (const Cat & cat)
const char * get_name() const
~Cat()
Requirement: member variable name stores a dynamically allocated array of characters.
要求: 成员变量 name 存储的是一个动态分配的字符数组.

## EXAMPLE INPUT

GHJOPIXM
ZLMCUOYRWJEHDQ

## EXAMPLE OUTPUT
1
1
This is my cat: GHJOPIXM
1
1
This is my cat: ZLMCUOYRWJEHDQ
