#include <iostream>
#include <string>
#include "FileRenamer.h"

int main()
{
	system("chcp 1251>NULL");
	std::string path = "D:/Test";
	std::cout << "������� ������ ���� ��� �������� �� ����� � ���������� � ���� ����:\\���� : ";
	std::getline(std::cin, path);
	std::cout << "���������� ����� ��� �������������� � ���� .����������: ";
	std::string FileExtention;
	std::getline(std::cin, FileExtention);

	FileRenamer FileRenamer(path, FileExtention);
	system("pause >NULL");
}