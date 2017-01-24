#include"14.30.strblob.h"
class BlobPtrPtr{
public:
	ConstStrBlobPtr* operator->() 
	{
		return ptr;
	}	
private:
	ConstStrBlobPtr* ptr = nullptr; 
};

