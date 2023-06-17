﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <format>
#include "myweb.h"

int main() {
	ztWeb ZtWeb;

	ZtWeb.addHeader("Content-type", "text/html");
	ZtWeb.addBody(std::format(R"(

<h1>Hello world!</h1>
<h2>By {}</h2>
<h2>your path is :<h3>{}</h3></h2>
"hello"
)",
	"Zengtudor",
	getenv("QUERY_STRING")
	));

	ZtWeb.send();
}