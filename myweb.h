#pragma once
#include<iostream>
#include<vector>
#include<format>
class ztWeb {
private:
	struct Header
	{
		std::string first;
		std::string second;
	};
	std::vector<Header> headers;
	std::vector<std::string> mess;
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

	}
private:

};