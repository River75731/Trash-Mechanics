#pragma once
#include <iostream>

#include <cmath>
#include <cstdlib>
#include <ctime>

#include <string>
#include <vector>
#include <map>

/*demo
carryOutCommand("add 1 3");
*/

class PieceT
{
private:
	std::string str_;
public:
	PieceT() : str_() {};
	PieceT(const std::string &str) :str_(str) {};
	std::string get() const { return str_; }
	void set(const std::string &str) { str_ = str; }
	bool operator < (const PieceT &p) const { return str_ < p.get(); }
	bool operator <= (const PieceT &p) const { return str_ <= p.get(); }
	bool operator > (const PieceT &p) const { return str_ > p.get(); }
	bool operator >= (const PieceT &p) const { return str_ >= p.get(); }
	bool operator == (const PieceT &p) const { return str_ == p.get(); }
	bool operator != (const PieceT &p) const { return str_ != p.get(); }
	virtual void show() const { std::cout << str_; }
	~PieceT() {}
};

class SentenceT
{
private:
	std::vector<PieceT> s_;
	std::vector<PieceT> separate_(std::string str);
public:
	SentenceT() :s_() {}
	SentenceT(const std::string &str):s_(separate_(str)){}
	SentenceT(const std::vector<PieceT> &s) : s_(s) {}
	std::vector<PieceT> get() const { return s_; }
	PieceT getPiece(size_t index) const { return s_[index]; }
	size_t getPieceNum() const { return s_.size(); }
	void set(const std::string &str) { s_ = separate_(str); }
	void set(const std::vector<PieceT> &s) { s_ = s; };
	virtual void show() const;
	virtual void show(int index) const;
	virtual bool carryOut();
	~SentenceT() {}
};

class FunT //You should inherit the function
{
protected:
	//PieceT name_;
	virtual bool pieceNumCheck(const SentenceT &s) = 0; // You should reload the pieceNumCheck(s) to define number of parameters
public:
	FunT() {}
	virtual bool fun(const SentenceT &s) = 0; // You should reload the fun(s) to define behavior
	virtual ~FunT() {}
};

class add: public FunT
{
private:
	virtual bool pieceNumCheck(const SentenceT &s);
public:
	//add() :FunT(PieceT("add")) {}
	add() :FunT() {}
	virtual bool fun(const SentenceT &s);
	virtual ~add(){}
};

const extern SentenceT Command;
extern std::map<PieceT, FunT*> CommandMap;

bool carryOutCommand(std::string command);