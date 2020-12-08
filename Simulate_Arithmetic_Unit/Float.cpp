/**
* Float类的实现
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/10/2
*/

#pragma once
#include "Num.h"
#include <string>

const unsigned long long FLOAT_ONES = 0XFFFFFFFFFFFFFFFF;
const unsigned int E_BASE = 1023;

Float::Float()
{
	// 浮点数
	this->num_type = NumType::float_;
	// 补码
	this->code_type = CodeType::true_;
	this->num.num = (double)0;
}

Float::Float(double num)
{
	// 浮点数
	this->num_type = NumType::float_;
	// 编码类型
	this->code_type = CodeType::true_;
	this->num.num = num;
}

Float::Float(double num, CodeType type)
{
	// 浮点数
	this->num_type = NumType::float_;
	// 编码类型
	this->code_type = type;
	this->num.num = num;
}

Float::~Float()
{
}

/**
* 浮点数原码乘法
* :param a: Float原数据
* :param b: Float原数据
*/
Float Float::multiply_true_code(Float a, Float b)
{
	
	unsigned int e = a.get_e_true() + b.get_e_true();
	unsigned long long A = a.get_num();
	unsigned long long B = b.get_num();

}

/**
* 补码乘法
* :param a: Float原数据
* :param b: Float原数据
*/
Float Float::multiply_complement_code(Float a, Float b)
{
	return a;
}

/**
* 浮点数: 转原码
*/
void Float::convert_to_true_code()
{
	//正数
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::true_;
		return;
	}
	// 反码 -> 原码
	else if (this->code_type == CodeType::inverse_)
	{
		this->num.s.num ^= FLOAT_ONES;
	}
	// 补码 -> 原码
	else if (this->code_type == CodeType::complement_)
	{
		this->convert_to_inverse_code();
		this->convert_to_true_code();
	}
	this->code_type = CodeType::true_;
	return;
}

/**
* 浮点数: 转反码
*/
void Float::convert_to_inverse_code()
{
	// 正数
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::inverse_;
		return;
	}
	// 原码 -> 反码
	else if (this->code_type == CodeType::true_)
	{
		this->num.s.num ^= FLOAT_ONES;
	}
	// 补码 -> 反码
	else
	{
		this->num.s.num -= 1;
	}
	this->code_type = CodeType::inverse_;
	return;
}

/**
* 浮点数: 转补码
*/
void Float::convert_to_complement_code()
{
	if (this->num.s.f == 0)
	{
		this->code_type = CodeType::complement_;
		return;
	}
	// 原码  -> 补码
	else if (this->code_type == CodeType::true_)
	{
		this->convert_to_inverse_code();
		this->convert_to_complement_code();
	}
	// 反码 -> 补码
	else if (this->code_type == CodeType::inverse_)
	{
		this->num.s.num += 1;
	}
	this->code_type = CodeType::complement_;
	return;
}

/**
* 打印
*/
void Float::print_code_binary()
{
	// 打印符号位
	this->num_to_binary(&this->num, 64, 63);
	printf(" ");
	// 打印阶码
	this->num_to_binary(&this->num, 63, 52);
	printf(" ");
	// 打印小数
	this->num_to_binary(&this->num, 52, 0);
	printf("\n");
}

/**
* 十进制打印数字
*/
void Float::print_num()
{
	// 转补码
	this->convert_to_true_code();
	printf("十进制为:%lf\n", this->num.num);
}
// 转浮点数
Float* Float::convert_to_float()
{
	return this;
}

// 转整数
Int* Float::convert_to_int()
{
	u_int num;
	num.num = 0;
	this->convert_to_true_code();
	// e: 保存阶码
	unsigned int e = this->num.s.e;
	// x第一位置1
	num.s.x |= 0X40000000;
	// x其余位取小数前30位
	num.s.x |= (this->num.s.num >> 22);
	// 向左移
	if (e >= E_BASE)
	{
		e = e - E_BASE;
		// 如果左移不足30
		if (e < 30)
		{
			num.num >>= (30 - e);
		}
		// 否则
		else
		{
			e -= 30;
			num.num <<= e;
		}

	}
	// 向右移（为0）
	else
	{
		num.s.x = 0;
	}
	// 符号位
	if (this->num.s.f == 0)
		num.s.f = 0;
	else
		num.s.f = 1;
	Int* ans = new Int(num.num, CodeType::true_);
	return ans;
}

/**
* 获取十进制数字的字符串
*/
string Float::get_string()
{
	string ans = "";
	ans += std::to_string(this->num.num);
	return ans;
}


/**
* << 重载
*/
ostream& operator<<(ostream& os, Float num)
{
	os << num.get_string();
	return os;
}

/**
* 获取num(将double变成long long)
*/
long long Float::get_num()
{
	long long ans = 0;
	ans |= (this->num.s.f << 63);
	ans |= (this->num.s.e << 51);
	ans |= this->num.s.num;
	return ans;
}

/**
* 获取符号位
*/
unsigned long long Float::get_sign()
{
	return this->num.s.f;
}

/**
* 获取数字位
*/
unsigned long long Float::get_x()
{
	return this->num.s.num;
}

/**
* 获取小数部分(原码形式)
*/
unsigned long long Float::get_x_true()
{
	return 0;
}


/**
* 获取小数部分(补码形式)
*/
unsigned long long Float::get_x_complement()
{
	return 0;
}

/**
* 获取阶码(移码)
*/
unsigned long long Float::get_e()
{
	return this->num.s.f;
}


/**
* 获取阶码(原码)
*/
unsigned long long Float::get_e_true()
{
	return this->num.s.f - E_BASE;
}
