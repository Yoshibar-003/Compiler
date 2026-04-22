#include <iostream>

int main(){
    int h = 10;
    int s = 2;
    for(int i = 0; i < h; i += s){
        std::cout << i << " ";
        h++;
        s++;
        i++;
    }
}