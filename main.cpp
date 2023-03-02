#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;


////////  STL: VECTORS PRACTICE  ////////

///Exercise to simulate a command-line interface to familiarize myself with vectors///

//Basic Commands to consider
//dir
//cd
//mkdir
//remdir
//type
//del
//cls
//time? (Already reserved) should use date instead
//exit




//Command function declaration
void dir_command();
void cd_command();
void mkdir_command();
void remdir_command();
void type_command();
void del_command();

//function to add default folders and files
void add_default_files();





//I need to contain an array within an array with the use of a vector class.





//text file struct
struct text_file
{
	string name = "";
	string content = "";
	text_file(string name, string content) : name(name), content(content) {}
};



//folder struct
struct folder
{
	//name of the folder
	string name;

	//name of the subfolder vector container
	vector<folder> subfolder;

	//name of the string file
	vector<text_file> file;

	folder(string name) : name(name) {}

} main_folder("C:");




//directory to alternate folders
folder &directory = main_folder;
//storage of previous folders
vector<folder> previous_folder;




//main
int main()
{
	//previous_folder.push_back(directory);

	//Add some default files and folder in the main folder
	add_default_files();

	//The command input
	string cli_input = "";

	//Loop
	while (1)
	{
		//set color to white
		textcolor(7);

		//display subfolders
		for (auto i : previous_folder)
		{
			cout << i.name << "/";
		}
		cout << directory.name;
		cout << ">>";

		//Ask for command
		cin >> cli_input;

		if (cli_input == "cd")
			cd_command();
		else if (cli_input == "dir")
			dir_command();
		else if (cli_input == "mkdir")
			mkdir_command();
		else if (cli_input == "remdir")
			remdir_command();
		else if (cli_input == "type")
			type_command();
		else if (cli_input == "del")
			del_command();
		else if (cli_input == "cls")
			clrscr();
		else if (cli_input == "date")
			system("date");
		else if (cli_input == "exit")
			return 0;
		else
		{
			cout << "command not found\n";
		}

		cin.clear();
		cin.ignore(1000, '\n');
		//getch();
	}
}
//end of main function




////// COMMANDS ///////
void dir_command()
{
	textcolor(3);
	//Print all the subfolder in the current folder
	for (auto i : directory.subfolder)
	{
		cout << "|" << i.name << "|\n";
	}

	textcolor(2);
	//Print text files
	for (auto i : directory.file)
	{
		cout << "|" << i.name << "|\n";
	}
	textcolor(7);
}



void cd_command()
{
	string folder_name;
	cin >> folder_name;
	
	if(folder_name==".."){
		//previous_folder.erase(previous_folder.begin());
		directory = previous_folder.back();
		previous_folder.pop_back();
		return;
		}

	for (auto i : directory.subfolder)
	{
		if (i.name == folder_name)
		{
			previous_folder.push_back(directory);
			directory = i;
			return;
		}
	}
	cout << "folder not found\n";
}



void mkdir_command()
{
	string folder_name;
	cin >> folder_name;
	folder f(folder_name);
	directory.subfolder.push_back(f);
}



void remdir_command()
{
	string folder_name;
	cin >> folder_name;
	for (auto i = directory.subfolder.begin(); i != directory.subfolder.end(); ++i)
	{
		if (i->name == folder_name)
		{
			directory.subfolder.erase(i);
			break;
		}
	}
	cout << "folder not found";
}



void type_command()
{
	string file_name;
	cin >> file_name;
	textcolor(YELLOW);
	for (auto i : directory.file)
	{
		if (file_name == i.name)
		{
			cout << i.content << "\n";
			return;
		}
	}
	cout << "file not found\n";
}



void del_command()
{
	string file_name;
	cin >> file_name;
	for (auto i = directory.file.begin(); i != directory.file.end(); ++i)
	{
		if (file_name == i->name)
		{
			directory.file.erase(i);
			return;
		}
	}
	cout << "file not found\n";
}



void add_default_files()
{
textcolor(11);
cout<<" _____  _     _____ \n"
"/  __ \| |   |_   _|\n"
"| /  \/| |     | |  \n"
"| |   | |     | |  \n"
"|  \__/\| |_____| |_ \n"
" \____/ \_____/  \___/ \n\n";
                    
                    
	
	text_file t1("test.txt", "Lorem ipsum banatag ang kaloobang di papipigil sa pighating nadaranasan ng malaman na may bago ka na.");
	main_folder.file.push_back(t1);
	
	text_file t2("welcome.txt", "Welcome to my simple command-line interface simulation. \nSome basic commands that are available for now are:\n\n$ cls - for clearing the screen\n$ cd - for changing directory\n$ dir - for viewing the current directory\n$ mkdir - for making your own directory\n$ remdir - for removing a directory\n$ type - for viewing text files\n$ del - for deleting text files\n$ date - for viewing the current time and date\n$ exit - for exiting the program\n");
	main_folder.file.push_back(t2);
	
	text_file t3("credits.txt", "Made by von.");
	main_folder.file.push_back(t3);
	
	folder n1("user");
	main_folder.subfolder.push_back(n1);

	folder n2("Download");
	main_folder.subfolder.push_back(n2);
	
	folder n4("Documents");
	main_folder.subfolder.push_back(n4);
	
	folder n3("bluetooth");
	main_folder.subfolder.push_back(n3);
	
	folder n5("test");
	main_folder.subfolder.push_back(n5);

	text_file test("Readme.md", "# Thank you for testing out my program. I appreciate it.");
	main_folder.file.push_back(test);
	
}
