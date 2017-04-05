#ifndef CSVEVAL_H
#define CSVEVAL_H


#include "Common.h"
#include "CSVHandler.h"
#include "ExpressionEvaluator.h"

class CSVEval
{
private:
    const string mDelimitersList = ", ";
    ExpressionEvaluator mExpressionEvaluator;

    void dumpValues(vector<double> &values, const string &outputFilePath);

public:
    CSVEval(void);

    void evalCSVFile(string csvFilePath, string outputFilePath);
};


#endif // CSVEVAL_H
