
#include "Message.h"


std::map<PieceT, FunT*> CommandMap
{
	std::make_pair(PieceT("add"), new add),
	std::make_pair(PieceT("jia"), new add)
};

std::vector<PieceT> SentenceT::separate_(std::string str)
{
	std::vector<PieceT> t{};
	size_t index = 0;
	while (index < str.length())
	{
		int pos = str.find(' ', index);
		if (pos == std::string::npos) break;
		if (pos - index > 0)
			t.push_back(std::string (str, index, pos - index));
		index = pos + 1;
	}
	if (index >= str.length()) return t;
	t.push_back(std::string (str, index, str.length() - index + 1));
	return t;
}

void SentenceT::show() const
{
	for (std::vector<PieceT>::const_iterator i = s_.begin(); i != s_.end(); i++)
	{
		static size_t p = 0;
		p++;
		std::cout << p << ' ';
		i->show();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

void SentenceT::show(int index) const
{
	std::cout << s_[index].get() << std::endl;
}

bool SentenceT::carryOut()
{
	//std::cout << '!';
	std::map <PieceT, FunT*>::iterator it = CommandMap.find((this->getPiece(0)));
	if (it == CommandMap.end())
	{
		std::cout << "Command not found" << std::endl;
		return false;
	}
	FunT* ptr = it->second;
	return ptr->fun(s_);
	//std::cout << "?" << std::endl;
}

bool add::pieceNumCheck(const SentenceT &s)
{
	size_t n = s.getPieceNum();
	//std::cout << s.getPieceNum();
	if (n == 3) return true; //the number of parameters + 1(because of the command name is getPiece(0)
	return false;
}

bool add::fun(const SentenceT &s)
{
	if (this->pieceNumCheck(s) == false)
		return false;
	std::string s1 = s.getPiece(1).get();
	std::string s2 = s.getPiece(2).get();
	std::cout << s1 << '+' << s2 << '=' << atoi(s1.c_str()) + atoi(s2.c_str()) << std::endl;
	return true;
}

bool carryOutCommand(std::string command)
{
	return SentenceT(command).carryOut();
}
