#pragma once
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

void RemoveWordFromString(std::string& Word, std::string WordToDelete);

class FileRenamer final
{
public:
	FileRenamer() = delete;
	FileRenamer(std::string path, std::string FilesExtensionToRename);

private:
	std::vector<std::filesystem::directory_entry> FilesToRename;
	std::string RemoveWordFromFilename(fs::directory_entry file, const std::string WordToDelete);
	void RenameFiles();
};

