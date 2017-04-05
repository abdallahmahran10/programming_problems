#include "csveval.h"

CSVEval::CSVEval(void)
{
}

void CSVEval::dumpValues(vector<double> &values, const string &outputFilePath)
{
    std::ofstream outfile (outputFilePath,std::ofstream::binary);
    for(int i=0; i<values.size(); i++)
        outfile<<values[i]<<std::endl;
}


void CSVEval::evalCSVFile(string csvFilePath, string outputFilePath)
{
    CSVHandler csvHandler(mDelimitersList);
    vector<string> expsList = csvHandler.read(csvFilePath);
    vector<double> values = mExpressionEvaluator.eval(expsList);
    dumpValues(values, outputFilePath);
}
