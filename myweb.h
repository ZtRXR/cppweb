#pragma once
#pragma execution_character_set("utf-8")  

#include<iostream>
#include<vector>
#include<format>
#include<map>
#include<sstream>
class ztWeb {
private:
	struct Header
	{
		std::string first;
		std::string second;
	};
	std::vector<Header> headers;
	std::vector<std::string> mess;
	std::map<std::string, std::string> query;
public:
	std::string getQuery(std::string s) {
		return query[s].size() ? query[s] : "无";
	}

public:
	void addHeader(std::string fir, std::string sec) {
		headers.push_back({
			fir,
			sec
			});
	}
	void send() {
		for (Header i : headers) {
			std::cout << std::format("{}: {}\r", i.first, i.second);
		}
		std::cout << std::format("\n\r\n");
		for (std::string i : mess) {
			std::cout <<std::format("{}\r",i);
		}
	}
	void addBody(std::string mes) {
		mess.push_back(mes);
	}

	ztWeb() {
		std::string Query{getenv("QUERY_STRING")};
		decodeUrl(Query);
		std::map<std::string, std::string> queryMap;
		m_to_query(Query);
	}
private:
	void decodeUrl(std::string &encodedUrl) {
		std::stringstream decoded;
		for (size_t i{ 0 }; i < encodedUrl.size(); i++) {
			if (encodedUrl[i] == '%') {
				std::string encodedChar = encodedUrl.substr(i + 1, 2);
				int charCode{ 0 };
				std::stringstream ss;
				ss << std::hex << encodedChar;
				ss >> charCode;
				decoded << (char)charCode;
				i += 2;
			}
			else if (encodedUrl[i] == '+')
			{
				decoded << " ";
			}
			else {
				decoded << encodedUrl[i];
			}
		}
		encodedUrl = decoded.str();
	}
	void m_to_query(std::string& s) {
		std::vector<std::string> v;
		m_split(s, "&", v);
		std::vector<std::string> querys;
		for (std::string i : v) {
			m_split(i, "=", querys);
			if (querys.size()>=2)
			{
				query[querys[0]] = querys[1];
			}
		}
	}
	void m_split(std::string& s,std::string to_split ,std::vector<std::string>& v) {
		std::string myStr = s;
		v.clear();
		int sf{ 0 };
		while (sf = myStr.find(to_split),sf != std::string::npos) {
			v.push_back(myStr.substr(0, sf));
			myStr = myStr.substr(sf + 1, myStr.size());
		}
		if (myStr.size()>0)
		{
			v.push_back(myStr);
		}
	}
};