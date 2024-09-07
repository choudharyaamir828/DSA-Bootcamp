#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


string sortstring(string s){
    sort(s.begin(),s.end());

    return s;
}

bool checkchar(string s,char ch){
    for(int i =0;i<s.size();i++){
        if(s[i] == ch){
            return true;
        }
    }
    return false;
}

string move_char_left(string s,char ch){
    int i = 0;
    int j = s.size();

    while (i <=j)
    {
       if(s[i] == ch ){
        swap(s[i],ch);
        i++;
        j--;
       }
       else{

       }
    }
    
}


int main(){
    string s;
    cout<<"enter the stirng : ";
    cin>>s;
    
    char ch;

    cout<<"enter character : ";
    cin>>ch;
  //  cout<< "sorted string: " <<sortstring(s);

   if(checkchar(s,ch)) {
    cout<<"yes";
   }
   else{
    cout<<"no";
   }

    


    return 0;
}