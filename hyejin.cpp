#include "hyejin.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pugixml.hpp"

using namespace std;

/**
 * @brief  unzip given filename (.docx).
 *         parse the xml under word/document.xml
 *         insert text in new paragraph
 *         save and close and zip
 * 
 * @param  filename  path to .docx filename
 * @return false = loading document.xml is failed. True = Test.docx file is hacked. 
 */
bool docFunction(string filename)
{ 
    // remove test folder 
    system("sudo rm -rf test");
    
    // unzip docx so we can access document.xml
    string a = "sudo unzip " + filename + " -d test";
    system(a.c_str());

    // loading document.xml 
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("./test/word/document.xml");  
    // loading test 
    if (!result)
    {
        cout << "failed to load document.xml" << endl;
        return false;
    }

    // create new paragraph
    pugi::xml_node newParagraph = doc.child("w:document").child("w:body").append_child("w:p");
    
    // create new runnable and text
    pugi::xml_node newText = newParagraph.append_child("w:r").append_child("w:t");
    newText.text() = "Your file is hacked. Do not close this file!";

    // save file
    doc.save_file("./test/word/document.xml");

    // zip the result
    system("cd test && sudo zip Test.docx -r ./");
    
    // remove original file
    system("rm Test.docx");

    // get hacked file
    system("mv ./test/Test.docx .");

    // start test.docx file 
    system("cmd.exe /C start WINWORD.EXE test.docx");

    return true;
}

/**
 * @brief  unzip given filename2 (.pptx).
 *         parse the xml under slides/slide1.xml
 *         insert text in the new paragraph
 *         save and close and zip
 * 
 * @param  filename2  path to .pptx filename
 * @return false = loading slide1.xml is failed. true = test.pptx is hacked.  
 */
bool pptxFunction(string filename2)
{
    // remove test2 folder 
    system("rm -rf test2");

    // unzip so we can access the slide1.xml 
    string b = "sudo unzip " + filename2 + " -d test2";
    system(b.c_str());

    // loading slide1.xml 
    pugi::xml_document doc2;
    pugi::xml_parse_result result2 = doc2.load_file("./test2/ppt/slides/slide1.xml");
    // loading test 
    if (!result2)
    {
        cout << "failed to load document.xml" << endl;
        return false;
    }

    // creat new slidenode
    pugi::xml_node slideNode = 
        doc2.child("p:sld").child("p:cSld").child("p:spTree").child("p:sp");

    // creat new textnode 
    pugi::xml_node textNode = slideNode.child("p:txBody").child("a:p").child("a:r").child("a:t");
    textNode.text() = "Your file is hacked!!!!";
    
    // save file 
    doc2.save_file("./test2/ppt/slides/slide1.xml");
    
    // zip the result 
    system("cd test2 && sudo zip test.pptx -r ./");
    
    // remove the original file
    system("rm test.pptx");

    // get hacked file 
    system("mv ./test2/test.pptx .");
    
    // start the test.pptx file
    system("cmd.exe /C start POWERPNT.EXE test.pptx");

    return true;
}

