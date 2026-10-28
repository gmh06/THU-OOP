#pragma once
# include <string>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy: public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		std::string enc_mes;
		for(int i = 0; i < mes.size(); i ++){
			enc_mes.push_back(mes[i]);
			enc_mes.push_back('#');
		}

		return enc_mes;
	}
};

class InvertStrategy: public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		int _size = mes.size();
		for(int i = 0; i < _size/2; i ++){
			char temp = mes[i];
			mes[i] = mes[_size - 1 - i];
			mes[_size - 1 - i] = temp;
		}

		return mes;
	}
};