//tdduong a.k.a Han
#ifndef __Vector__
#define __Vector__
#include<bits/stdc++.h>
#define Han signed main

using namespace std;

template<class T>
class Vector{
    private:
        T* elem;
        size_t size;
        size_t space;
    public:
        Vector() : space(10), size(0){
            elem = new T[space];
        }
        Vector(size_t newmalloc):space(newmalloc), size(0){
            elem = new T[space];
        }
        ~Vector(){
            delete[] elem;
        }  

        void resize(){
            space *= 2;
            T* newelem = new T[space];
            for(size_t i = 0; i < size; ++i) newelem[i] = elem[i];
            delete[] elem;
            elem = newelem;
        }

        void push_back(const T& val){
            if(size == space) resize();
            elem[size++] = val;
        }

        T& operator[](size_t index){
            return elem[index];
        }

        const T& operator[](size_t index) const{
            return elem[index];
        }

        size_t getSize() const{
            return size;
        }

        void erase(size_t index){
            if(index >= size) return;
            for(size_t i = 0; i < size - 1; ++i) elem[i] = elem[i + 1];
            --size;
        }

        void clear(){
            size = 0;
        }
};
#endif