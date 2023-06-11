#include <iostream>
#include <string>
#include "FileRenamer.h"

int main()
{
	system("chcp 1251>NULL");
	std::string path = "D:/Test";
	std::cout << "Введите полный путь без пробелов до папки с текстурами в виде диск:\\путь : ";
	std::getline(std::cin, path);
	std::cout << "Расширение файла для переименования в виде .Расширение: ";
	std::string FileExtention;
	std::getline(std::cin, FileExtention);

	FileRenamer FileRenamer(path, FileExtention);
	system("pause >NULL");
}