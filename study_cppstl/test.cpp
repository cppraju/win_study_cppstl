

template <typename T>
class myshPtr
{
	T *m_pObj;
	int  *m_prefCnt;
public:
	myshPtr();
	myshPtr(const myshPtr<T> &othr);
	myshPtr(myshPtr<T> &&othr);
	myshPtr<T> & operator =(const myshPtr<T> &othr);
	myshPtr<T> & operator =(myshPtr<T> &&othr);
	T * operator ->(void);
	~myshPtr();
};

template <typename T>
myshPtr<T>::myshPtr()
{
	m_pObj = new T;
	m_prefCnt = new int;
	*m_prefCnt = 1;
}
template <typename T>
myshPtr<T>::myshPtr(const myshPtr<T> &othr)
{
	m_pObj = othr.m_pObj;
	m_prefCnt = othr.m_prefCnt;
	*m_prefCnt =*m_prefCnt + 1;
}
template <typename T>
myshPtr<T>::myshPtr(myshPtr<T> &&othr)
{
	m_pObj = othr.m_pObj;
	m_prefCnt = othr.m_prefCnt;
	othr.m_pObj = nullptr;
	othr.m_prefCnt = nullptr;
}
template <typename T>
myshPtr<T> & myshPtr<T>::operator =(const myshPtr<T> &othr)
{
	if(this != &othr)
	{
		*m_prefCnt = *m_prefCnt - 1;
		m_pObj = nullptr;
		

		m_pObj = othr.m_pObj;
		m_prefCnt = othr.m_prefCnt;
		*m_prefCnt =*m_prefCnt + 1;
	}
	return(*this);
}
template <typename T>
myshPtr<T> & myshPtr<T>::operator =(myshPtr<T> &&othr)
{
	if (m_pObj != nullptr)
		delete m_pObj;
	m_pObj = othr.m_pObj;
	othr.m_pObj = nullptr;

	return(*this);
}
template <typename T>
T * myshPtr<T>::operator ->(void)
{
	return(m_pObj);
}
template <typename T>
myshPtr<T>::~myshPtr()
{
	if(*m_prefCnt == 0)
		delete m_pObj;
}
