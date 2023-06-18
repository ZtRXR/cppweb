#define _CRT_SECURE_NO_WARNINGS
#pragma execution_character_set("utf-8")  


#include <iostream>
#include <format>
#include "myweb.h"

int main() {
	ztWeb ZtWeb;

	ZtWeb.addHeader("Content-type", "text/html;charset=utf-8");
	ZtWeb.addBody(std::format(R"(

<h1>Hello world!</h1>
<h2>By '{}'</h2>
<h2>your age is :<h3>'{}'</h3></h2>
)",
ZtWeb.getQuery("name"),
ZtWeb.getQuery("age")
));

	ZtWeb.send();
}