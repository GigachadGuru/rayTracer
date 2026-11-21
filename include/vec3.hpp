#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<iostream>

class vec3 {
    double e[3];

    vec3(double e1=0,double e2=0,double e3=0):e{e1,e2,e3}{}

    double x(){return e[0]}
    double y(){return e[1]}
    double z(){return e[2]}

    vec3 operator -(){return vec3(-e[0],-e[1],-e[2]);}//1
    double operator[](int i){return e[i];}//2
    double &operator[](int i){return e[i];}//3

    vec3& operator+=(vec3& v){//4
        e[0]+=v[0];//reference to operator no 3
        e[1]+=v[1];
        e[2]+=v[2];
        return *this;
    }

    vec3& operator*=(double t){
        e[0]*=t;
        e[1]*=t;
        e[2]*=t;
        return *this;
    }
    vec3& operator/=(double t){
        return *this*=(1/t);
    }

    double length_squared(){
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    double length(){
        return std::sqrt(length_squared());
    }
}

//vector utility functions 

inline std::ostream& operator<<(std::ostream&out,const vec3& v){
    return out<<v[0]<<' '<<v[1]<<' '<<v[2];
}
//in modern c++ inline finction has eveolved to "multiple function defintions are allowed" thsi does not 
//allows the function body to be defined in multiple files and the linker doesnt throw an error

inline vec3 operator+(const vec3& u,const &vec3 v){
    return vec3(u[0]+v[0],u[1]+ v1[1],u[2]+v[2]);
}

inline vec3 operator-(const vec3&u,const vec3&v){
    return vec3(u[0]-v[0],u[1]-v[1],u[2]-v[2]);
}

inline vec3 operator*(const vec3&u,const vec3&v){
    return vec3(u[0]*v[0],u[1]*v[1],u[2]*v[2]);
}

inline vec3 operator*(const vec3& v, double t){
    return vec3(v[0]*t,v[1]*t,v[2]*t);
}

inline vec3 operator*(double t,const vec3& v){
    return t*v;
}

inline vec3 operator/(double t,const  vec3&v){
    return v*(1/t);
}

inline double dot(const vec3&u,const vec3& v){
    return u[0]*v[0] + u[1]*v[1] + u[2]*v[2]; 
}

inline vec3 cross(const vec3&u,const vec3& v){
    return vec3(u[1]*v[2] - u[2]*v[1],v[0]*u[2] - u[0]*v[2],u[0]*v[1] - u[1]*v[0]);
}

inline vec3 cross(const vec3&u){
    return u/u.length();
}

