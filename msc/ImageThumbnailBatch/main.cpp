#include "imagesresizer.h"

#define QUEUE_LIMIT 10
#define RETURN system("pause"); return 0

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout<<"Please specify the images input and the output folder"<<endl;
        RETURN;
    }
    vector<QString> inputs;
    int i;
    for(i=1; i<argc-1; i++)
    {
        if(file_exists(argv[i]))
            inputs.push_back(argv[i]);
        else
        {
            cout<<"Invalid path: "<<argv[i]<<endl;
            RETURN;
        }
    }

    QString outputFolder = argv[i];
    ImagesResizer imgsResizer(QUEUE_LIMIT, outputFolder);
    imgsResizer.resize(inputs);
    cout<<"Done!"<<endl;
    RETURN;

}
