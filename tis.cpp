#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stack>
#include <sstream>
using namespace std;

int main(){
    string input_line;
    string ini, ejem;
    int band = 1;
    
    string a,b;
    stack<string> pila;

    while(band){
        getline(cin, input_line);
        
        if(input_line == "*"){
            band = 0;
        }
        else{
            ejem = input_line.substr( input_line.find(":") + 1 );      
            ini = input_line.substr( 0, input_line.find(":") +1 );
            for(int i = ejem.size()-1; i > -1; i--){
                if( isalpha( ejem.at(i) ) ){ 
                    char c = ejem.at(i);
                    stringstream ss; string s;
                    ss << c; ss >> s;
                    pila.push( s );
                }
                else{
                    if( ejem.at(i) == '&' ){
                       a = pila.top(); pila.pop();
                       b = pila.top(); pila.pop();
                       if( a.at(0) == '(' ){
                           a = a.substr(1, a.size()-2 );
                       }
                       pila.push( "(" + a + ", " + b + ")" );
                    }
                    if( ejem.at(i) == '@' ){
                       a = pila.top(); pila.pop();
                       b = pila.top(); pila.pop();
                       pila.push( a + " -> " + b );
                    }
                }
            }
            cout << ini << ' '<< pila.top() << endl;
        }
    };
    return 0;
}
