#pragma once

#include <string>

namespace elliott {

	class FileUtils
	{
	public:
		static std::string read_file(const char* filepath)
		{
			// r: read-only, t: text file
			FILE* file = fopen(filepath, "rt");

			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];

			// Set weird stuff to 0 so there's no weird chars in the string
			memset(data, 0, length + 1);

			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);

			fclose(file);

			std::string result(data);

			delete[] data;
			return result;
		}
	};

}