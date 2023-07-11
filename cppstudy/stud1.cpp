#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define WITDH 6


int main(){
char line[WITDH];
cin.getline(line, WITDH+1);
cout << line << endl;
string s = line;
cout << s << endl;
return 0;
}

