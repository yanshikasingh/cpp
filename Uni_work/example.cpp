#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){


    int num = 0500;
    cout<<num;
map<string,int> student ={{"Yash",7800},{"Yukta",5555},{"Ritesh",8088},{"Vaibhav",0500}};
student.insert({"Yanshika",1276});
map<string,int> :: iterator itr;
for(itr = student.begin(); itr != student.end();itr++){
cout << (*itr).first << " " << (*itr).second << "\n";

}

return 0;}