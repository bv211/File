#include <cstdio>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const char path[]{ "file.txt" };

string read_file() {
	FILE* file = nullptr;
	auto error = fopen_s(&file, path, "r");

	if (error != NULL)
		return "empty";

	const int size = 256;
	char buffer[size]{};
	string text;

	while (fgets(buffer, size, file)) {
		text.append(buffer);
	}

	fclose(file);
	return text;
}

void write_file(const string& text) {
	FILE* file = nullptr;
	auto error = fopen_s(&file, path, "w");

	if (error != NULL)
	{
		cout << "Can't open the file" << endl;
		return;
	}

	fputs(text.c_str(), file);
	fclose(file);
}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	// Запись в файл
	string text;
	cout << "Enter the text" << endl;
	getline(cin, text);

	write_file(text);

	// Чтение
	cout << "Данные файла:" << endl;
	cout << read_file() << endl;

	return 0;
}