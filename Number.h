#pragma once
typedef unsigned int uint;
#define MAXDIGITS 1000
#define TERMINATOR 256



class Number {
public:
	int* digit;
	uint size;
	uint notation; // система счисления
public:
	void Init() { digit = new int[MAXDIGITS]; size = notation = 0; }
	Number() { Init(); }
	Number(uint n, uint p) { 
		Init();
		SetNonation(p);
		Set(n);
	}
	Number(int *_d, uint _s,uint p) {
		Init();
		SetNonation(p);
		for (int i=0;i< (int)_s;i++)
			digit[i] = _d[i];
		digit[_s] = TERMINATOR;
		size = _s;		
	}

	~Number() { delete digit; }
	void ZeroMem(int *a,int _s) {
		for (int i = 0; i < _s; i++)
		{
			a[i] = 0;
		}
	}

	void V() {
		for (uint i = 0; i < (int)size; i++)
		{
			printf("%d ",digit[i]);			
		}
		printf("\n");
	}

	void SetNonation(uint p) {
		if (p < 2) throw 1;
		if (p > 255) throw 1;
		notation = p; 
	}

	void Set(uint n) {
		if (n == 0) { digit[0] = 0; digit[1] = TERMINATOR; size = 1; return; }
		uint len = (uint)floor(log(n)/log(notation)+1);		
		for (int i = (int)len - 1; i >= 0; i--)
		{
			digit[i] = n % notation;
			n = n / notation;
		}
		size = len;
		digit[len] = TERMINATOR;
	}

	int GetSize() {
		return size;
	}

	uint Get()const {}
//--------------
	int operator[](int i) {
		if ((i < 0) || (i >= (int)size))throw 3;
		return digit[i];
	}

	Number& operator =(Number &b) {
		if (this == &b)return (*this);
		if (size != 0)delete digit;
		size = b.GetSize();

		digit = new int[MAXDIGITS];
		for (int i = 0; i < (int)size; i++)
		{
			digit[i] = b[i];
		}
		digit[size] = TERMINATOR;
		return (*this);	
	}	

	bool operator ==(Number &b) {
		if (this->size != b.GetSize()) return false;
		for (int i = 0; i < (int)size;i++) {
			if (this->digit[i] != b[i]) return false;
		}
		return true;
	}

	bool operator <(Number& b) {
		if ((int)this->size < b.GetSize()) return true;
		if ((int)this->size > b.GetSize()) return false;

		for (int i = 0; i < (int)size; i++) {
			if (this->digit[i] < b[i]) return true;
		}
		return false;
	}

	bool operator !=(Number &b) {		
		return !((*this)==b);
	}

	Number& operator <<(int n) { //compact 0111 -> 111		

		if ((digit[0] == 0) && (size == 1)) return (*this);
		for (int i = 0; i < n; i++) {
			digit[size + i] = 0;
		}	
		size += n;
		digit[size] = TERMINATOR;
		return (*this);
	}

	Number& operator -() { //compact 0111 -> 111		
		while (digit[0] == 0) {
			if (size <= 1)return (*this);
			for (int i = 0; i < (int)size; i++) {
				digit[i] = digit[i + 1];
			}
			this->size--;			
		}
		return (*this);
	}

	Number& operator -(Number &b) { 		
		int* result = new int[MAXDIGITS];
		ZeroMem(result, MAXDIGITS);

		int _size = size; result[size] = TERMINATOR;
		int ai = size-1, bi = b.GetSize()-1;
		int tmp;

		for (int i = size-1; i >= 0; i--) {
			tmp = (bi < 0) ? 0 : b[bi];
			if (digit[ai] < tmp) { //занимаем уследующего разряда
				result[ai - 1]--;
				result[ai]+=notation; 
			}
			result[ai] += (digit[ai] - tmp);
			ai--; 
			bi--;
		}
		Number *a=new Number(result, size, notation);
		-(*a);
		return *a;
	}

};
