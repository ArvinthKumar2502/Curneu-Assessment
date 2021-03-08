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

	string dir_command="cd ";
	dir_command.append(dest);

	ofstream MyFile("zip.ps1");
	MyFile << zip_command;
    MyFile.close();

	system("start powershell.exe Set-ExecutionPolicy RemoteSigned");
   	system("start powershell.exe .\\zip.ps1");

	cout<<"\nLocation of Zipped Folder : "<<dest;

}

int main()
{
	string source_filepath;
    string destination_path;
	int x;

	std::cout << "\t\t\t\t\tZip a Folder\n\n\n";

	std::cout << "Enter the file path of the Directory to be Zipped : \n";
    cin >> source_filepath;

    std::cout << "\n\nEnter the Destination path of the Directory to be Zipped : \n";
    cin >> destination_path;

	zipFolder(source_filepath,destination_path);

	//cin>>x;
	
	return 0;
}