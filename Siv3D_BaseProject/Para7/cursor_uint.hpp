

//���j���[��ʂł̃J�[�\���ʒu��⏕������
//�P���ɃC���N�������g����Ɣ͈͊O�܂ł����Ă��܂��̂ŁA
//�ő�l�ݒ肵�Ď����Ń��[�v���Ă��΃��j���[��ʂ̏������y�ɂȂ��˂Ƃ�������
class Cursor_uint
{
public:
	Cursor_uint();
	Cursor_uint(int  max);
	int value() const;
	int max() const;

public://���Z�q

	bool        operator== (const int &x) const;
	inline bool operator!= (const int &x) const
	{
		return !(*this == x);
	}
	bool        operator=  (const int &subst);  //max�ȏ�̐��l�͑�����Ȃ��̂ŁA���̐����ۂ�Ԃ�



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

	int _value;//�}�C�i�X�ɍs���\��������̂Ō��m���邽�߂�����unsigned�ɂ��ĂȂ�
	int _max;
};
