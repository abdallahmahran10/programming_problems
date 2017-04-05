#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "Common.h"

class CSVHandler
{
private:
    string mDelimitersList;
    string toExpersion(const string &csvLine);

public:
    CSVHandler(string delimitersList);

    vector<string> read(const string &filePath);
};



#endif // CSVHANDLER_H
