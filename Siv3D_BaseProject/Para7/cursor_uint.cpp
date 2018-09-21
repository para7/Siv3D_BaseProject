#pragma once

#include "cursor_uint.hpp"

Cursor_uint::Cursor_uint(int  max)
	: _max(max)
	, _value(0)
{}

Cursor_uint::Cursor_uint()
	: _max(0)
	, _value(0)
{}

bool Cursor_uint :: operator== (const int &x) const
{
	return x == _value;
}
Cursor_uint Cursor_uint::operator++(int)
{
	const auto ret = *this;
	++(*this);
	return ret;
}
Cursor_uint Cursor_uint::operator--(int)
{
	const auto ret = *this;
	--(*this);
	return ret;
}

//max�ȏ�̐��l�͑�����Ȃ��̂ŁA���̐����ۂ�Ԃ�
bool Cursor_uint::operator= (const int &subst)
{
	_value = subst < _max ? subst : _value;
	return subst < _max;
}

int Cursor_uint::value() const
{
	return _value;
}
int Cursor_uint::max() const
{
	return _max;
}
/*----Cursor_uint end----*/