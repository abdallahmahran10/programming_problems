#include "csvhandler.h"
#include <algorithm>

CSVHandler::CSVHandler(string delimitersList):mDelimitersList(delimitersList)
{
}


string CSVHandler::toExpersion(const string &csvLine)
{
    string exp(csvLine);
    int i=0;
    while( i < exp.size())
    {

        std::size_t found = mDelimitersList.find(exp[i]);
         if (found!=std::string::npos)
            exp.erase(i, 1);
        else
            i++;
    }
    return exp;
}

vector<string> CSVHandler::read(const string &filePath)
{
    vector<string> ret;
    string line;
    std::ifstream infile(filePath);
    while (std::getline(infile, line))
        ret.push_back(toExpersion(line));
    return ret;
}
