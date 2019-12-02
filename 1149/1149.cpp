#include <iostream>
using namespace std;

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
};

int main() {
    int num_house;
    int red, green, blue;
    int min_red=0, min_green=0, min_blue=0;
    int next_red, next_green, next_blue;
    cin>>num_house;

    while (num_house--) {
        cin>>red>>green>>blue;
        next_red = min(min_green, min_blue) + red;
        next_green = min(min_red, min_blue) + green;
        next_blue = min(min_red, min_green) + blue;
        min_red = next_red;
        min_green = next_green;
        min_blue = next_blue;
    }

    cout<<min(min(min_red, min_green), min_blue)<<"\n";

    return 0;
}