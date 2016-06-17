#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
string word;
string sentence;
vector<string> words;
getline(cin,sentence);
istringstream iss(sentence);
while(iss>>word)
{
	words.push_back(word);
}

for(int i=0; i<words.size()-1; i++)
for(int j=i+1; j<words.size(); j++)
if(words[i]==words[j])
	cout << words[i] << endl;

}
