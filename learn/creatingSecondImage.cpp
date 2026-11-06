#include<iostream>

using namespace std;

int main(){
    int image_width = 256;
    int image_height = 256;

    cout<<"P3\n"
    <<image_height<<" "<<image_width<<" "<<"\n255\n";

    for(int i =0;i<image_height;i++){
        for(int j=0;j<image_width;j++){
            auto r = double(i)/(image_height-1);
            auto g = double(j)/(image_width-1);
            auto b = double(r+g)/2;

            int ir = int(r*255.999);
            int ig = int(g*255.999);
            int ib = int(b*255.999);

            cout<<ir<<" "<<ig<<" "<<ib<<endl;
        }
    }
}