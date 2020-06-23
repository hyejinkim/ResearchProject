#include "ray.h"
#include "barry.h"
#include "convert.h"
#include "steven.h"
#include "hyejin.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //RayFunc();
    //barrysProgram();
    //convert();
    //payload();
    //docFuntion();
    //pptxFunction();

    string choice;
    int num;
    do
    {

        string filename = "./Test.docx";
        string filename2 = "./test.pptx";

        cout << "Please enter number." << endl;
        cout << "1. Raymond" << endl;
        cout << "2. Barry" << endl;
        cout << "3. Crystal" << endl;
        cout << "4. Steven" << endl;
        cout << "5. HyeJin" << endl;
        cout << "6. quit" << endl;
        cin >> num;

        if (num == 1)
        {
            RayFunc();
        }
        else if (num == 2)
        {
            barrysProgram();
        }
        else if (num == 3) 
        {
            convert();
        }
        else if (num == 4)
        {
            payload();
        }
        else if (num == 5)
        {
            docFunction(filename);
            pptxFunction(filename2);
        }
    } while (num != 6);
    
    return 0;
}