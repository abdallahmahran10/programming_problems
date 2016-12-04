#include "common.h"
#define Request int
#define Item int

class Logger
{
public:
	Logger();
	virtual void log(string msg) = 0;
};

class FileLogger :public Logger
{
public:
	FileLogger()
	{}
	// override the log function
	void log(string msg);
};

class User
{
public:
	virtual double getDiscount(double TotalSales)
	{
		return TotalSales;
	}
};

class User 
{
public:
	virtual double getDiscount(double TotalSales)
	{
		return TotalSales;
	}
	
	User(Logger *_logger)
	{
		m_pLogger = _logger;
	}
	
	//
	bool login(string username, string password)
	{
		string msg ="";
		// some data validation code
		// ....
		// some EPIC code to connect to DB
		// ....
		m_pLogger->log(msg);
		// ....
		// display login attempt result
		// ....
		// return result
	}
	//
	bool execute(Request req)
	{
		// some data validation code
		// ....
		// another EPIC code to connect to DB
		// ....
		// log user request
		// ....
		// display execution result
		// ....
		// return result
	}
	private:
	Logger *m_pLogger;
	int m_userType;
	/* user data*/
	//
	bool addToFavorite(Item item);
	//
	bool removeFromFavorite(Item item);
	//
	bool trackItem(Item item);
	//
	bool returnItem(Item item);

};


class SilverUser : public User
{

public:
	double getDiscount(double TotalSales)
    {
		return User::getDiscount(TotalSales) - 50;	
    }
};