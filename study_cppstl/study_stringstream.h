#pragma once

struct _personinfo
{
	std::string _sname;
	__int16  _age;
	//friend std::istringstream& operator >>(std::istringstream& s, _personinfo& obj);
	//friend std::ostringstream& operator<<(const _personinfo& obj,  std::ostringstream& s);
	friend std::istream& operator >>(std::istream& s, _personinfo& obj);
	friend std::ostream& operator<<(std::ostream& s, const _personinfo& obj);
};

//std::istringstream& operator >>(std::istringstream& s, _personinfo& obj);
//std::ostringstream& operator <<(const _personinfo& obj, std::ostringstream& s);


 std::istream& operator >>(std::istream& s, _personinfo& obj);
 std::ostream& operator<<(std::ostream& s, const _personinfo& obj);

void call_stringstream(void);

void call_fstream(void);
void call_stringstream_morefeatures(void);