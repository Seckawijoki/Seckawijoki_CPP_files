#include <iostream>
using namespace std;

template <typename T> class Singleton
{
protected:

	static T* ms_Singleton;

public:
	Singleton( void )
	{
#if defined( _MSC_VER ) && _MSC_VER < 1200	 
		int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
		ms_Singleton = (T*)((int)this + offset);
#else
		ms_Singleton = static_cast< T* >( this );
#endif
	}
	~Singleton( void )
	{  ms_Singleton = 0;  }
	static T& getSingleton( void )
	{	return ( *ms_Singleton ); }
	static T* getSingletonPtr( void )
	{ return ms_Singleton; }
};

template <typename T> T *Singleton<T>::ms_Singleton = 0;
	
class AbsBodyAR : public Singleton<AbsBodyAR>{
	virtual void setSkeletonData() = 0;
};

class HWBodyAR : public AbsBodyAR {
	void setSkeletonData() override {};
};

class IOSBodyAR : public AbsBodyAR {
	void setSkeletonData() override {};
};

int main(){
	HWBodyAR* create1 = new HWBodyAR();
	IOSBodyAR* create2 = new IOSBodyAR();
	
	AbsBodyAR* hwBodyAR = dynamic_cast<HWBodyAR*>(AbsBodyAR::getSingletonPtr());
	AbsBodyAR* iosBodyAR = dynamic_cast<IOSBodyAR*>(AbsBodyAR::getSingletonPtr()); 
	cout<<hwBodyAR<<endl<<iosBodyAR<<endl;
	cout<<create1<<endl<<create2<<endl;
} 
