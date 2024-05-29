#include <iostream>
#include <string>

bool findplendrom(std::string s)
{
	bool bRet = false;
	//check if the number of char is odd
	if ((s.length() % 2) != 0)
	{
		std::string sleft, sright;
		int imid = s.length() / 2 + 1;
		int i = 0;
		for (std::string::iterator it = s.begin(); i < imid; i++, it++)
			sleft = sleft + *it;
		i = 0;
		for (std::string::reverse_iterator irv = s.rbegin(); i < imid; i++, irv++)
			sright = sright + *irv;
		if (sleft == sright)
			bRet = true;
	}

	return(bRet);
}