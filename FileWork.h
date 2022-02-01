#pragma once
#include <fstream>
#include <vector>




void DeleteFile(const char* filename)
{
	fstream file;
	file.open(filename, ios::out | ios::in | ios::trunc);
	file.close();
}

template <class type>
bool Read(const char* filename, std::vector<type> data)
{
	fstream file;
	file.open(filename, ios::out | ios::in | ios::binary | ios::app);
	file.seekg(0, ios::end);
	int sizeof_st = sizeof(type),
		number_st = file.tellg() / sizeof_st;
	if(number_st)
	{
		type st;
		file.seekg(0, ios::beg);
		for (int i = 0; i < number_st; i++)
		{
			file.read((char*)&st, sizeof_st);
			data.push_back(st);
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}

}

template <class type>
void Write(const char* filename, std::vector<type> data)
{
	DeleteFile(filename);
	int sizeof_st = sizeof(type);
	fstream file;
	file.open(filename, ios::out | ios::in | ios::binary | ios::app);
	file.seekg(ios::beg);
	for (int i = 0; i < data.size(); i++)
	{
		file.write((char*)&data[i], sizeof_st);
	}
	file.close();
}
