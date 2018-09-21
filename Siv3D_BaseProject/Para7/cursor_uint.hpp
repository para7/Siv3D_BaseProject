

//メニュー画面でのカーソル位置を補助するやつ
//単純にインクリメントすると範囲外までいってしまうので、
//最大値設定して自動でループしてやればメニュー画面の処理が楽になるよねということ
class Cursor_uint
{
public:
	Cursor_uint();
	Cursor_uint(int  max);
	int value() const;
	int max() const;

public://演算子

	bool        operator== (const int &x) const;
	inline bool operator!= (const int &x) const
	{
		return !(*this == x);
	}
	bool        operator=  (const int &subst);  //max以上の数値は代入しないので、その成功可否を返す



	inline Cursor_uint& operator++()
	{
		_value = ((_value + 1) < _max) ? _value + 1 : 0;
		return *this;
	}
	Cursor_uint operator++(int);

	inline Cursor_uint& operator--()
	{
		_value = (0 <= (_value - 1)) ? _value - 1 : _max - 1;
		return *this;
	}
	Cursor_uint operator--(int);

	Cursor_uint& operator+=(const int rhs)
	{
		if (rhs >= 0)
		{
			_value = (_value + rhs) % _max;
		}
		else
		{
			*this -= (-rhs);
		}
		return *this;
	}
	Cursor_uint& operator-=(const int rhs)
	{
		if (rhs >= 0)
		{
			_value = (_value + _max - rhs%_max) % _max;
		}
		else
		{
			*this += (-rhs);
		}
		return *this;
	}

	inline void max_reset(unsigned int newmax)
	{
		_max = newmax;
	}
private:

	int _value;//マイナスに行く可能性があるので検知するためあえてunsignedにしてない
	int _max;
};
