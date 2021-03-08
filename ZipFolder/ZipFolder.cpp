#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


void zipFolder(string src,string dest)
{
	string zip_command="Compress-Archive -LiteralPath '";
	zip_command.append(src);
    zip_command.append("' -DestinationPath '");
    zip_command.append(dest);
    zip_command.append("'");

	ofstream MyFile("zip.ps1");
	MyFile << zip_command;
    MyFile.close();

	system("start powershell.exe Set-ExecutionPolicy RemoteSigned");
   	system("start powershell.exe .\\zip.ps1");

}

int main()
{
	string source_filepath;
    string destination_path;


	std::cout << "Enter the file path of the Directory to be Zipped : \n";
    cin >> source_filepath;

    std::cout << "Enter the Destination path of the Directory to be Zipped : \n";
    cin >> destination_path;

	zipFolder(source_filepath,destination_path);
	
	return 0;
}