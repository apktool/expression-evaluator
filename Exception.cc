#include"Exception.h"
#include<execinfo.h>
#include<cstdio>
#include<cstdlib>

const char* Exception::what() const throw(){
	return message_.c_str();
}

const char* Exception::StackTrace() const throw(){
	return stackTrace_.c_str();
}

//栈回溯
void Exception::FillStackTrace(){
	const int len=200;
	void* buffer[len];
	int nptrs=::backtrace(buffer,len);
	char** strings=::backtrace_symbols(buffer,nptrs);
	if(strings){
		for(int i=0;i<nptrs;++i){
			stackTrace_.append(strings[i]);
			stackTrace_.push_back('\n');
		}
		free(strings);
	}
}