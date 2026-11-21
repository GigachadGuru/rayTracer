#include<iostream>
#include "../include/vec3.hpp"
#include "../include/color.hpp"

int main(){
    int image_height = 256;
    int image_width = 256;
    
    //progress indicator
    int bar_width = 40;
    //render
    
    std::cout<<"P3\n"<<image_height<<" "<<image_width<<"\n255\n";

    for(int j = 0 ;j<image_height;j++){//add space bw the last letter and flush to avoid random output generation
        float progress = (j+1)/image_height;
        int pos = int(progress*bar_width);

        std::clog<<"\r[";
        for(int b =0;b<bar_width;b++){
            if(b<pos)std::clog<<"_";
            else if(b==pos) std::clog << "C";
            std::clog<<"_";
        }

        std::clog<<"] Progress: "<<int(progress*100)<<"%"<<std::flush;
        for(int i =0;i<image_width;i++){
            auto pixel_color = color(double(i)/(image_width-1),double(j)/(image_height-1),0);
            write_color(std::cout,pixel_color);
        }
    }
    std::clog<<"\rDone         \n";
}