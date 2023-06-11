#include "FileRenamer.h"
#include <iostream>
#include <map>


FileRenamer::FileRenamer(std::string path, std::string FilesExtensionToRename)
{
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path().extension() != FilesExtensionToRename) continue;

		FilesToRename.push_back(entry);
	}

	if (FilesToRename.size() <= 0)
	{
		std::cout << "В директории нет файлов с заданным расширения\n";
		return;
	}

	RenameFiles();
}

std::string FileRenamer::RemoveWordFromFilename(fs::directory_entry file, const std::string WordToDelete)
{

	std::string NewFilename = file.path().filename().string();
	RemoveWordFromString(NewFilename, WordToDelete);
	fs::path NewPath = file.path();
	NewPath.replace_filename(NewFilename);
	try
	{
		fs::rename(file.path(), NewPath);
	}
	catch (fs::filesystem_error& error) // if the renaming was unsuccessful
	{
		std::cout << error.code() << "\n" << error.what() << "\n";
	}
	return NewFilename;
}

void FileRenamer::RenameFiles()
{
	std::string WordToDelete;
	std::cout << "Введите слово без пробелов для удаления из имени файлов: ";
	std::cin >> WordToDelete;
	std::cout << "\n";

	std::vector<std::string> NamesRenamedFiles;

	for (auto& File : FilesToRename)
	{
		std::string FileName = File.path().filename().string();
		if (FileName.find(WordToDelete) == std::string::npos) continue;


		NamesRenamedFiles.push_back(RemoveWordFromFilename(File, WordToDelete));

		if (NamesRenamedFiles.size() == 1)
		{
			std::cout << "Начало удаления " << WordToDelete << " из имён файлов : \n";
			std::cout << "Имена файлов для переименования:\n";
		}
		std::cout << FileName << "\n";

	}
	if (NamesRenamedFiles.size() <= 0)
	{
		std::cout << "В выбранной директории нечего переименовывать\n";
		return;
	}

	std::cout << "Имена переименованных файлов: \n";
	for (const auto& FileName : NamesRenamedFiles)
	{
		std::cout << FileName << "\n";
	}
}

void RemoveWordFromString(std::string& Word, std::string WordToDelete)
{
	auto iter = Word.find(WordToDelete);
	// Iterate through the whole string searching for desired substrings
	while (iter != std::string::npos)
	{
		Word.erase(iter, WordToDelete.length());
		iter = Word.find(WordToDelete, iter);
	}
}
