//yaho release 3.0 
#include <bits/stdc++.h>
using namespace std;

//args
bool kcs = false;

int mapp = 0;
bool ext;
const string apha = "abcdefghijklmnopqrstuvwxyzl";
const string aval = "11234567895";
//waste gen
string wstdim(){
	string s,nam,val;
	for (int i=1;i<=3+rand()%12;i++)
		nam += apha[rand()%26];
	
	for (int i=1;i<=1+rand()%8;i++)
		val += aval[rand()%10];
		
	s = "int " + nam + " = " + val +";\n";
	return s;
}

string wstfor(){
	string s,v0,nam,v1,v2,na2;
	for (int i=1;i<=3+rand()%12;i++)
		nam += apha[rand()%26];
	
	for (int i=1;i<=3+rand()%12;i++)
		na2 += apha[rand()%26];
		
	for (int i=1;i<=1+rand()%9;i++)
		v0 += aval[rand()%10];
	
	for (int i=1;i<=1+rand()%2;i++)
		v1 += aval[rand()%10];
	
	for (int i=1;i<=1+rand()%2;i++)
		v2 += aval[rand()%10];
	s = "\nint " + nam + " = " + v0 +";\n" + "for (int " + na2 + " = " + v1 + "; " \
	+ na2 + " <= " + v2 + "; " + na2 + "++) " + nam + " += " + na2 + ";\n";
	return s;
}

string wstif(){
	string s,v0,v1;
	for (int i=1;i<=1+rand()%8;i++)
		v0 += aval[rand()%10];	
		
	for (int i=1;i<=1+rand()%8;i++)
		v1 += aval[rand()%10];
		
	s = "if(" + v0 +" == " + v1 + ") " + wstdim() + " else " + wstdim() +"\n";
		
	return s;
}


void wstgen(int a,int b,int c){
	for (int i=1;i<=rand()%a;i++) cout<<wstdim();
	for (int i=1;i<=rand()%b;i++) cout<<wstfor();
	for (int i=1;i<=rand()%c;i++) cout<<wstif();
}

//~wstgen
string chkhead(string a){
	int x = 0;
	while (!((a[x]>='A' && a[x]<='Z') || (a[x]>='a' && a[x]<='z') || a[x] == '_' || a[x] == '#' || a[x] == '{' \
	|| a[x] == '/' || a[x] == '}' || a[x] == '\t') && x < a.size()){
		a[x] = ' ';x++;
	}
	
	return a;
}

string chkrem(string a){
	for (int i=0;i<a.size()-1;i++){
		if (a[i] == '/' && a[i+1] == '/'){
			for (int j=i;j<a.size();j++) a[j] = ' ';
		}else if (a[i] == '/' && a[i+1] == '*'){
			while (!(a[i] == '*' && a[i+1] == '/') && i<a.size()-1){
				a[i] = ' ';i++;
			}
			a[i] = ' ';a[i+1] = ' ';
		}
	}
	
	return a;
}

bool wchk(string s){
	for (int i=0;i<s.size();i++)
	if (s[i] == '{')
		mapp++;
	else if (s[i] == '}')
		mapp--;
			
	int len = s.length();
	for (int i=0;i<len;i++){
		if (i != len-1 && s[i] == 'i' && s[i+1] == 'f') return false;
		if (i != len-1 && s[i] == 'd' && s[i+1] == 'o') return false;
		if (i != len-2 && s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'r') return false;
	}
	return true;
}
int main(int argc,char **argv){
	srand((unsigned)time(NULL));
	if (argc < 3) {cout<<"Too few arguments."<<endl;return 1;}
	freopen(argv[1],"r",stdin);
	freopen(argv[2],"w",stdout);
	
	if (argc >= 4 && !strcmp(argv[3],"-k")) {
		kcs = true;
		cerr<<"二逼题目又要卡常数了啊。。。"<<endl;
	}
	string s;
	while (getline(cin,s)){
		cerr<<"processing "<<s<<" ...\n";
		if (s != ""){
			s = chkhead(s); 
			s = chkrem(s);
		}
		cout<<s<<endl;
		ext = wchk(s);
		if (mapp>0 && ext && !kcs) cerr<<"genarating waste...\n";
		if (mapp > 0 && ext && !kcs) wstgen(3,3,3);
	} 
	
	cerr<<"All Done,Have Fun!"<<endl;
	return 0;
}
