#include<stdio.h>
extern int count;					//extern修饰全局变量 该变量在其他文件中定义 但在本文件中使用
									//static修饰全局变量 该变量只能在本文件中访问 其他文件无法访问
									//static修饰函数 该函数只能在本文件中访问 其他文件无法访问
#define MAX 100						//宏定义标识符常量 在预处理阶段进行替换 不占用内存空间
#define SQUARE(x) ((x)*(x))			//宏定义函数式常量 在预处理阶段进行替换 不占用内存空间 但可能存在副作用
void test()
{
	static int count = 0;			//使用static修饰局部变量 本质上换了一种存储方式 使得该变量在程序运行期间一直存在 但只能在函数内部访问
	count++;
	printf("修饰count = %d\n", count);
}

void test_1()
{
	 int count_1 = 0;				//不用static修饰局部变量
	count_1++;
	printf("不修饰count_1 = %d\n", count_1);
}

int main()
{
	int i = 0;
	while (i < 10)
	{
		test();
		i++;
	}
	i = 0;
	while (i < 10)
	{
		test_1();
		i++;
	}
}
									//register修饰局部变量 建议该变量存储在寄存器中 访问速度快 但数量有限 不适合大数组等数据结构