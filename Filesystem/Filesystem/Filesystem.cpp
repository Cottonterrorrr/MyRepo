



#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;


void ListDirectory(std::string_view file)
{	
	
	fs::path currentPath{ file };
	std::vector<fs::directory_entry> dir_entries{};
	
	for (const auto& dir_entry : fs::recursive_directory_iterator{ currentPath })
	{
		dir_entries.push_back(dir_entry);
	}
	std::partition(dir_entries.begin(), dir_entries.end(), [](const fs::directory_entry& de) {
		return de.is_directory();
		});

	
	for (const auto& dir_entry : dir_entries) 
	{
		switch (const auto& p = dir_entry.path();/*dir_entry.status().type()*/ fs::status(p).type())
		{

			case fs::file_type::directory:
				std::cout << "[DIR]\t" << p.string() << std::endl;
				break;
			case fs::file_type::regular:
				//std::cout << '\t' << p.string() << '\t' << dir_entry.file_size() << std::endl;
			

				ifstream in;
			

				in.open(dir_entry);
				string s ;
				int sTotal = 0;
				while (!in.eof()) {
					getline(in, s);
					sTotal++;
				}
				cout << '\t' << p.string() << '\t' <<"Lines in the file: " <<  sTotal << std::endl;
				in.close();

				break;
		}
	}


}

int main()
{
    //fs::current_path(fs::temp_directory_path());
	/*
	
    for (auto& p : fs::recursive_directory_iterator("C:/Users/macie/Desktop/led_holder"))
    {
        std::cout << p.path() << '\n';
    }
   
	*/
   

	ListDirectory("C:\\Users\\macie\\Downloads\\filesystem");



}