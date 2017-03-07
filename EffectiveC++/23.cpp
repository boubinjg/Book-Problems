//prefer non-member non-friend functions to friend functions

class WebBrowser {
public:
	void clearCache(){}
	void clearHistory(){}
	void removeCookies(){}
};

//should this be a friend? a member? a nonmember?
void clearBrowser(WebBrowser& wb) 
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();	
}

//If clearBrowser were a friend, WebBrowser would be less encapsulated.
//friend functions would have access to WebBrowser's private variables, which
//is not necessary. For this reason it should not be a friend, or even a member.
//if it doesn't require special privilege, it shouldnt receive it.

//it is worth noting that clearBrowser could be a member/friend of some class,
//but shouldnt be a member/friend of this class.

//it is also more general to include this function as a non-member. Say a user doesn't
//want to use this function or functions like it. If this function were a member or friend,
//they would automatically include it. If not, this function could be in a separate 
//file from the WebBrowser class definition. Users could choose to use or ignore it like elements of
//the standard library.

int main()
{
	return 0;
}
