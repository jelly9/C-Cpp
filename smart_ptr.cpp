#include <iostream>
using namespace std;

//#include "boost/shared_ptr.hpp"

#if 0
//1���ռ����Ȩ��ת�ư�AutoPtr//
template<typename T>
class AutoPtr
{
public:
	//���캯��
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}

		//��������
	~AutoPtr()
	{
		if(_ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}

	//�������캯��
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	//��ֵ���������
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if(this != &ap)
		{
			if(_ptr)
			{
				delete _ptr;
			}

			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	//���������������
	T& operator*()
	{
		return *_ptr;
	}
	//ȡַ���������
	T& operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

void F1()
{
	AutoPtr<int> ap(new int(1));
	AutoPtr<int> ap1(ap);
	AutoPtr<int> ap2;
	ap2 = ap1;

}
#endif



#if 0
//2������_owner�İ汾
template<typename T>
class AutoPtr
{
public:
	//���캯��
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
		,_owner(true)
	{
		if(!_ptr)
		{
			_owner = false;
		}
	}
	
	//��������
	~AutoPtr()
	{
		if(_owner)
		{
			delete _ptr;
			_ptr = NULL;
		}

	}

	//��������
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
		,_owner(true)
	{
		ap._owner = false;
	}

	//��ֵ���������
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if(this != &ap)
		{
			delete _ptr;
			_ptr = ap._ptr;
			_owner = true;
			ap._owner = false;
		}
		return *this;
	}

	//���������������
	T& operator*()
	{
		return *_ptr;
	}
	//ȡַ���������
	T& operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
	bool _owner;
};

AutoPtr<int> Funtest()
{
	AutoPtr<int> ap(new int(1));
	return ap;
}


void F2()
{
	AutoPtr<int> ap(new int(1));
	AutoPtr<int> ap1(ap);
	AutoPtr<int> ap2;
	ap2 = ap1;
	AutoPtr<int> ap3(Funtest());
	AutoPtr<int> ap4(AutoPtr<int> (new int(1)));

}

#endif

#if 0
//3����������UniquePtr
template<typename T>
class UniquePtr
{
public:

	UniquePtr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if(NULL != _ptr)
		{
			delete _ptr;
			_ptr = NULL;
		}
	}

	//���������������
	T& operator*()
	{
		return *_ptr;
	}

	//ȡַ���������
	T& operator->()
	{
		return _ptr;
	}
private:
	UniquePtr(const UniquePtr<T>& ap);
	UniquePtr& operator=(const UniquePtr<T>& ap);
private:
	T* _ptr;
};

void F3()
{
	UniquePtr<int> ap(new int (1));
	UniquePtr<int> ap1(ap);//�޷���ɿ���
	UniquePtr<int> ap2;
	ap2 = ap;//�޷���ɸ�ֵ
}

#endif


#if 0
template<typename T>
class UniqueArray
{
public:

	UniqueArray(T* array = NULL)
		:_array(array)
	{}
	~UniqueArray()
	{
		if(NULL != _array)
		{
			delete _array;
			_array = NULL;
		}
	}

	//���������������
	T& operator*()
	{
		return *_array;
	}

	//ȡַ���������
	T& operator->()
	{
		return _array;
	}
	//[]����
	T& operator[](size_t idx)
	{
		return _array[idx];
	}

private:
	UniqueArray(const UniqueArray<T>& array);
	UniqueArray& operator=(const UniqueArray<T>& array);
private:
	T* _array;
};

void F4()
{
	UniqueArray<int> arr1(new int(1));//ûʲô����
	//UniqueArray<int> arr2(new int[4](1));//�޷���������	
}


#endif

#if 1
//3��SharePtr

//�Զ���ɾ����
//�ͷ��ļ�ָ��
struct Fclose
{
	void operator()(FILE*& fp)
	{
		cout<<"Fclose()"<<endl;
		fclose(fp);
		fp = NULL;
	}
};

//malloc��ָ����ͷ�
template<typename T>
struct Free
{
	void operator()(T*& p)
	{
		free(p);
		p = NULL;
	}
};

//һ������µ��ͷ�
template<typename T>
class Delete
{
public:
	void operator()(T*& p)
	{
		delete p;
		p = NULL;
	}
};

template<typename T, typename Destroy = Delete<T>>
class SharePtr
{
public:
	//���캯��
	SharePtr(T* ptr = NULL)
		:_ptr(ptr)
		,_pCount(NULL)
	{
		if(ptr)
		{
			_pCount = new int(1);
		}
	}

	~SharePtr()
	{
		Release();
	}


	//��������
	SharePtr(const SharePtr<T>& ap)
		:_ptr(ap._ptr)
		,_pCount(ap._pCount)
	{
		if(_ptr)
		{
			++UseCount();
		}

	}

	SharePtr<T>& operator=(const SharePtr<int>& ap)
	{
		if(this != &ap)
		{
			if(_ptr)
			{
				Release();
			}
			_ptr = ap._ptr;
			_pCount = ap._pCount;
			++UseCount();
		}
		return *this;
	}

	//ȡַ���������
	T& operator->()
	{
		return _array;
	}
	//[]����
	T& operator[](size_t idx)
	{
		return _array[idx];
	}

	int& UseCount()
	{
		return *_pCount;
	}

	void Release()
	{
		
 		if(_ptr && 0 == --UseCount())
		{
			Destroy()(_ptr);
			delete _pCount;
			_pCount = NULL;
		}
	}

private:
	T* _ptr;
	int* _pCount;

};	

/*void F5()
{
	SharePtr<int> p(new int(666));
	SharePtr<int> p1(p);
	SharePtr<int> p2;
	//p2 = p;

	//SharePtr<int> p3 = (int*)malloc(10);
	//SharePtr<FILE> p4 = fopen("test.c", "r");
}*/


#endif

#if 1
//4��SharePtr�����ѭ����������
struct Node
{
	//Node(int value)
	//	:_value(value)
	//{
	//	cout<<"Node()"<<endl;
	//}

	//~Node()
	//{
	//	cout<<"~Node()"<<endl;
	//}

	SharePtr<Node> _prev;
	SharePtr<Node> _next;
	int _value;
};

void F6()
{
	SharePtr<Node> p1(new Node(1));
	SharePtr<Node> p2(new Node(2));
	cout<<p1.UseCount()<<endl;
	cout<<p2.UseCount()<<endl;
}


#endif
int main()
{
	//F1();
	//F2();
	//F3();
	//F4();
	//F5();
	F6();
	return 0;
}

