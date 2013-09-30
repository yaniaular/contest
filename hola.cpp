#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stack>
#include <sstream>

using namespace std;

int main(){

    string ejem = "@&&ACB&XY";
    string a,b;
    string u;
    char c;
    int i;
    stack<string> cola;

   
   cout << ejem << endl;

    for(i = ejem.size()-1; i > -1; i--){
        
       // cout << "****" << ejem.at(i) << endl;


        if( isalpha( ejem.at(i) )  ){ //Si es letra, encolo
            c = ejem.at(i);
           stringstream ss;
           string s;
            ss << c;
            ss >> s;
            cola.push( s );
                cout << s << endl;       
        }
        else{
            if( ejem.at(i) == '&' ){
               a = cola.top();
               cola.pop();
                cout << '&' << endl;       
               b = cola.top();
               cola.pop();
               
               if( a.at(0) == '(' ){
                   a = a.substr(1, a.size()-2 );
               }
                    u = "(" + a + "," + b + ")";
               cola.push( u );
               cout << u << endl;

            }
            if( ejem.at(i) == '@' ){
               a = cola.top();
               cola.pop();
               b = cola.top();
               cola.pop();
               u =  a + " -> " + b;
               cola.push( u );
               cout << u << endl;
            }
        }
    }
    return 0;
}
