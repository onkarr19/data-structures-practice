 #include <iostream>
 using namespace std;
 #define get(a) int a; cin >> a;
 #define println(a) cout << a << "\n";
 #define print(a) cout << a;
 

char lostCharNW(string stringSent, string stringRec) {
	char answer;

	for (int i = 0; stringRec[i]; ++i)
	{
		if (stringSent[i]!=stringRec[i])
		{
			answer = stringSent[i];
		}
	}

	return answer;
}

 
 int main() {
 	println(lostCharNW("cshvbhfauh", "cshvbhfauht"));
 	
 	return 0;
 }