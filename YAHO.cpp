//yaho release 3.6
#include <bits/stdc++.h>
using namespace std;

//args
bool kcs = false;
int wnm = 3;

int mapp = 0;
bool ext,typ = false;
const string apha = "abcdefghijklmnopqrstuvwxyzl";
const string aval = "11234567895";
//waste gen
string wstdim() {
	string s,nam,val;
	for (int i=1; i<=3+rand()%12; i++)
		nam += apha[rand()%26];

	for (int i=1; i<=1+rand()%8; i++)
		val += aval[rand()%10];

	s = "int " + nam + " = " + val +";\n";
	return s;
}

string wstfor() {
	string s,v0,nam,v1,v2,na2;
	for (int i=1; i<=3+rand()%12; i++)
		nam += apha[rand()%26];

	for (int i=1; i<=3+rand()%12; i++)
		na2 += apha[rand()%26];

	for (int i=1; i<=1+rand()%9; i++)
		v0 += aval[rand()%10];

	for (int i=1; i<=1+rand()%2; i++)
		v1 += aval[rand()%10];

	for (int i=1; i<=1+rand()%2; i++)
		v2 += aval[rand()%10];
	s = "\nint " + nam + " = " + v0 +";\n" + "for (int " + na2 + " = " + v1 + "; " \
	    + na2 + " <= " + v2 + "; " + na2 + "++) " + nam + " += " + na2 + ";\n";
	return s;
}

string wstif() {
	string s,v0,v1;
	for (int i=1; i<=1+rand()%8; i++)
		v0 += aval[rand()%10];

	for (int i=1; i<=1+rand()%8; i++)
		v1 += aval[rand()%10];

	s = "if(" + v0 +" == " + v1 + ") " + wstdim() + " else " + wstdim() +"\n";

	return s;
}


void wstgen(int a,int b,int c) {
	for (int i=1; i<=rand()%a; i++) cout<<wstdim();
	for (int i=1; i<=rand()%b; i++) cout<<wstfor();
	for (int i=1; i<=rand()%c; i++) cout<<wstif();
}

//~wstgen
//string del(string s){
//	int i=0;
//	while(i < s.length() && s[i] != ' ') i++;
//	if (s[i] == ' '){
//		for (int j = i+1;j<s.length();j++)
//			s[i] = s[i+1];
//		s = del(s);
//	}
//	return s;
//}
string chkhead(string a) {
	int x = 0;
	while (!((a[x]>='A' && a[x]<='Z') || (a[x]>='a' && a[x]<='z') || a[x] == '_' || a[x] == '#' || a[x] == '{' \
	         || a[x] == '/' || a[x] == '}' || a[x] == '\t') && x < a.size()) {
		a[x] = ' ';
		x++;
	}

	return a;
}

string chkrem(string a) {
	for (int i=0; i<a.size()-1; i++) {
		if (a[i] == '/' && a[i+1] == '/') {
			for (int j=i; j<a.size(); j++) a[j] = ' ';
		} else if (a[i] == '/' && a[i+1] == '*') {
			while (!(a[i] == '*' && a[i+1] == '/') && i<a.size()-1) {
				a[i] = ' ';
				i++;
			}
			a[i] = ' ';
			a[i+1] = ' ';
		} else if (a[i] == ';' && a[i+1] == ';') {
			a[i] = ' ';
		}
	}

	return a;
}

bool wchk(string s) {
	for (int i=0; i<s.size(); i++)
		if (s[i] == '{')
			mapp++;
		else if (s[i] == '}' && mapp >0)
			mapp--;
			
	if (mapp == 0) typ = false;
	int len = s.length();
	int hd = 0;while(s[hd] == ' ') hd++;
	//cerr<<typ<<endl;
	//cerr<<s[hd+0]<<s[hd+1]<<s[hd+2]<<s[hd+3]<<s[hd+4]<<s[hd+5]<<endl;
	if (s[hd+0] == 'c' && s[hd+1] == 'l' && s[hd+2] == 'a' && s[hd+3] == 's' && s[hd+4] == 's') typ = true;
	if (s[hd+0] == 's' && s[hd+1] == 't' && s[hd+2] == 'r' && s[hd+3] == 'u' && s[hd+4] == 'c' && s[hd+5] == 't') typ = true;
	for (int i=0; i<len; i++) {
		if (i < len-1 && s[i] == 'i' && s[i+1] == 'f') return false;
		if (i < len-1 && s[i] == 'd' && s[i+1] == 'o') return false;
		if (i < len-2 && s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'r') return false;
	}
	return true;
}
int main(int argc,char **argv) {
	srand((unsigned)time(NULL));
	if (argc < 3) {
		cerr<<"Too few arguments."<<endl;
		return 1;
	}else
		cerr<<"Argc is "<<argc<<endl;
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);

	if (argc >= 4) {
		for (int i=4; i<=argc; i++) {
			if (!strcmp(argv[i-1],"-k")) {
				kcs = true;
				cerr<<"Running in KCS Mode."<<endl;
			} else if (!strcmp(argv[i-1],"-s")) {
				wnm += 2;
				cerr<<"Running in Super Mode with number of wastes "<<wnm<<"."<<endl;
			}
		}
	}
	string s;
	while (getline(cin,s)) {
		cerr<<"processing "<<s<<" ...\n";
		if (s != "") {
			s = chkhead(s);
			s = chkrem(s);
			//s = del(s);
		}
		cout<<s<<endl;
		ext = wchk(s);
		if (mapp>0 && ext && !kcs && !typ) cerr<<"genarating waste...\n";
		if (mapp > 0 && ext && !kcs && !typ) wstgen(wnm,wnm,wnm);
		//cout<<"*********"<<mapp<<"**********"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	cerr<<"Calling Astyle..."<<endl;
	string t = string("astyle\\bin\\astyle.exe ") + argv[2];
	system(t.c_str());
	cerr<<"All Done,Have Fun!"<<endl;
	return 0;
}
