#include"SymbolTable.h"
#include"Storage.h"
#include<assert.h>
#include<cmath>

Storage::Storage(SymbolTable& tbl){
	AddConstants(tbl);
}

void Storage::Clear(){
	cells_.clear();
	inits_.clear();
}

bool Storage::IsInit(unsigned int id) const{
	return id<cells_.size() && inits_[id];
}

void Storage::AddConstants(SymbolTable& tbl){
	unsigned int id;

	id=tbl.Add("e");
	AddValue(id,exp(1.0));

	id=tbl.Add("pi");
	AddValue(id,2.0*acos(0.0));//反余弦函数 pi=2*acos(0)
}

double Storage::GetValue(unsigned int id) const{
	assert(id<cells_.size());
	return cells_[id];
}

void Storage::SetValue(unsigned int id, double val){
	assert(id<=cells_.size());
	if(id<cells_.size()){
		cells_[id]=val;
		inits_[id]=true;
	}else if(id==cells_.size()){
		AddValue(id,val);
	}
}

void Storage::AddValue(unsigned int id, double val){
	cells_.resize(id+1);
	inits_.resize(id+1);
	cells_[id]=val;
	inits_[id]=true;
}