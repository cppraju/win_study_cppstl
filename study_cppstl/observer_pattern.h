#pragma once

typedef void (*FP)(void* pData);

struct _Data
{
};
class SubjectToObserv
{
public:
	void attach(FP fp)
	{
		m_fp = fp;
	};
	void detach(void)
	{
		m_fp = nullptr;
	};
	void notify(void)
	{
		//just call of the func pointer
		m_fp((void*)&m_data);
	};
private:
	FP m_fp = nullptr;
	_Data m_data;
};

class Obsrvr
{
public:
	Obsrvr(void)
	{
		std::cout << "Obsrvr constructor\n";
	}
	Obsrvr(const Obsrvr &othr)
	{
		std::cout << "Obsrvr Copy constructor\n";
	};
	Obsrvr(Obsrvr&& othr)
	{
		std::cout << "Obsrvr Move constructor\n";
	}
	static void obsrv_callback(void* pd);
	void callbyasync(void);
};

void callobserverpattern(void);
void someObrsvfunc(Obsrvr v);
void someObrsvfunc2(Obsrvr &&v);