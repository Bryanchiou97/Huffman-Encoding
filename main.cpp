#include "Decompressor.h"

using namespace std;

const static string USAGE = "Usage: ./Decompressor inputFilePath";

int main(int argc, char* argv[]){
    
    if (argc < 2){
        cout << USAGE;
        exit(1);
    }
    
    string filePath = argv[1];

    // Extract the name of the file
    string fileName = "";
    int index;
    for (int i = 0; i < filePath.length(); i++){
        if(filePath[i] == '/'){
            index = i;
        }
    }

    index++;
    for (int i = index; i < filePath.length()-10; i++){
        fileName += filePath[i];
    }
    // Set the input and output file name
    string d_inputFile = filePath;
    string d_outputFile = "decompressed_files/" + fileName + "decompressed";
    
    cout << "InputFile: " << d_inputFile << endl;
    cout << "OutputFile: " << d_outputFile << endl;

    // Here you take the the compressed file, and write 
    // your output (the decompressed file) into the decompressed_files/ directory
    // Please use the output file name as defined above (d_outputFile)
	    
    // Start writing your code here...

    Decompressor cs(d_inputFile, d_outputFile);
    cs.doWork();









    return 0;
}
