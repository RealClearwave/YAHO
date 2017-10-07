#include <bits/stdc++.h>
using namespace std;

const string apha = "abcdefghijklmnopqrstuvwxyzl";
const string aval = "01234567895";

string wstdim(){
	string s,nam,val;
	for (int i=1;i<=3+rand()%12;i++)
		nam += apha[rand()%26];
	
	for (int i=1;i<=rand()%9;i++)
		val += aval[rand()%10];
		
	s = "int " + nam + " = " + val +";";
	return s;
}

string wstif(){
	string s,v0,v1;
	for (int i=1;i<=rand()%9;i++)
		v0 += aval[rand()%10];	
		
	for (int i=1;i<=rand()%9;i++)
		v1 += aval[rand()%10];
		
	s = "if(" + v0 +" == " + v1 + ") " + wstdim() + " else " + wstdim();
	return s;
}

string wstfor(){
	string s,v0,nam,v1,v2,na2;
	for (int i=1;i<=3+rand()%12;i++)
		nam += apha[rand()%26];
	
	for (int i=1;i<=3+rand()%12;i++)
		na2 += apha[rand()%26];
		
	for (int i=1;i<=rand()%9;i++)
		v0 += aval[rand()%10];
	
	for (int i=1;i<=rand()%9;i++)
		v1 += aval[rand()%10];
	
	for (int i=1;i<=rand()%9;i++)
		v2 += aval[rand()%10];
	s = "int " + nam + " = " + v0 +";\n" + "for (int " + na2 + " = " + v1 + "; " \
	+ na2 + " <= " + v2 + "; " + na2 + "++) " + nam + " += " + na2 + ";";
	return s;
}
int main(){
	srand((unsigned)time(NULL));
	cout<<wstfor()<<endl;
	return 0;
}
