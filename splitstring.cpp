#include<bits/stdc++.h>

using namespace std;

void splitString(string s){
	string no, peso;
	int p;
	bool negativo=false;
	for(int i=0;i<s.length();i++){
		if(!isdigit(s[i]) && s[i] != '-'){
			no.push_back(s[i]);
		}
		else if(s[i] == '-'){
			negativo = true;
		}
		else{
			peso.push_back(s[i]);
		}
	}
	p = stoi(peso);
	if(negativo == true){
		p *= (-1);
	}

	cout << no << " " << p << endl;//no = string && p = numeric
}

int main(){
	
	string s;
	cin >> s;
	splitString(s);


	return 0;
}
