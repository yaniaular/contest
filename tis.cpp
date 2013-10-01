#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stack>
#include <sstream>

using namespace std;

int main(){
    string input_line;
    string a,b;
    stack<string> pila;

    while(true){
        getline(cin, input_line);
        
        if(input_line == "*"){
            break;
        }
        else{
            cout << input_line.substr( 0, input_line.find(":") +1 ) << ' ';
            input_line = input_line.substr( input_line.find(":") + 1 );      
            for(int i = input_line.size()-1; i > -1; i--){
                if( isalpha( input_line.at(i) ) ){ 
                    stringstream ss; string s;
                    ss << input_line.at(i); ss >> s;
                    pila.push( s );
                }
                else{
                    if( input_line.at(i) == '&' ){
                       a = pila.top(); pila.pop();
                       b = pila.top(); pila.pop();
                       if( a.at(0) == '(' ){
                           a = a.substr(1, a.size()-2 );
                       }
                       if( b.at(0) == '(' ){
                           b = b.substr(1, b.size()-2 );
                       }
                       pila.push( "(" + a + ", " + b + ")" );
                    }
                    if( input_line.at(i) == '@' ){
                       a = pila.top(); pila.pop();
                       b = pila.top(); pila.pop();
                       pila.push( a + " -> " + b );
                    }
                }
            }
            cout << pila.top() << endl;
        }
    }
    return 0;
}
