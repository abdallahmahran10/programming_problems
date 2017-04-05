
#include "csvEval.h"

#define RETURN system("pause"); return 0

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout<<"Please specify the input csv file and the output file";
        RETURN;
    }
    string csvFilePath(argv[1]), outputFilePath(argv[2]);
    if(!file_exists(csvFilePath))
    {
        cout<<"Invalid path"<<endl;
        RETURN;
    }
    // parse csv file and dump the evaluation results in outputFilePath
    CSVEval csvEval;
    csvEval.evalCSVFile(csvFilePath, outputFilePath);

    cout<<"Done!"<<endl;
    RETURN;
}
