#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    getline(cin, str);
    
    
    again_1:
    while(1) {
        for(int i = 0; i < str.length(); i++) {
            if(str[0] == ' ') {
                str.erase(0, 1);
                goto again_1;
            } else if(str[str.length() - 1] == ' ') {
                str.erase(str.length() - 1, 1);
                goto again_1;
            }
        }
        break;
    }
    again_2:
    while(1) {
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == ' ' && str[i + 1] == ' ') {
                str.erase(i + 1, 1);
                goto again_2;
            }
        }
        break;
    }
    for(int i = 0; i < str.length(); i++) {
        if(i == 0 && str[i] > 90) {
            str[i] -= 32;
        } else if(str[i] == ' ' && str[i + 1] > 90) {
            str[i + 1] -= 32;
        } else if(str[i] != ' ' && str[i] < 97 && str[i - 1] != ' ') {
            str[i] += 32;
        }
    }
    std::cout << str;

    return 0;
}

