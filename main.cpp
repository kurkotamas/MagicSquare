#include <iostream>
#include <math.h>
#define n 3
using namespace std;

int osszeg = n * (pow(n, 2) + 1) / 2;
int N = n * n;
int nr = 0;

int sor(int buvos[][n], int s, int o){
    int osszeg = 0;
    for(int i = 0; i <= o; i++){
        osszeg = osszeg + buvos[s][i];
    }
    return osszeg;
}

int oszlop(int buvos[][n], int s, int o){
    int osszeg = 0;
    for(int i = 0; i <= s; i++){
        osszeg = osszeg + buvos[i][o];
    }
    return osszeg;
}

int foatlo(int buvos[][n], int s){
    int osszeg = 0;
    for(int i = 0; i <= s; i++){
        for(int j = 0; j <= s; j++){
            if(i == j){
                osszeg = osszeg + buvos[i][j];
            }
        }
    }
    return osszeg;
}
int mellekatlo(int buvos[][n], int s){
    int osszeg = 0;
    for(int i = 0; i <= s; i++){
        for(int j = 0; j < n; j++){
            if(i + j == n - 1){
                osszeg = osszeg + buvos[i][j];
            }
        }
    }
    return osszeg;
}

void kiir(int buvos [][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<buvos[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int ellenoriz(int buvos[][n], int s, int o){
        //sor
    if(o == n - 1){
        if(sor(buvos, s, o) != osszeg){
            return 0;
        }
    }
    else{
        if(sor(buvos, s, o) >= osszeg){
            return 0;
        }
    }
        //oszlop
    if(s == n - 1){
        if(oszlop(buvos, s, o) != osszeg){
            return 0;
        }
    }
    else{
        if(oszlop(buvos, s, o) >= osszeg){
            return 0;
        }
    }
    //foatlo
    if(s == o){
        if(s == n - 1){
            if(foatlo(buvos, s) != osszeg){
                return 0;
            }
        }
        else{
            if(foatlo(buvos, s) > osszeg){
                return 0;
            }
        }
    }
    //mellekatlo
    if(s + o == n - 1){
        if(s == n - 1){
            if(mellekatlo(buvos, s) != osszeg){
                return 0;
            }
        }
        else{
            if(mellekatlo(buvos, s) > osszeg){
                return 0;
            }
        }
    }
    return 1;
}

void BuvosNegyzet(int buvos[][n], int b[], int s, int o){
    for(int i = 1; i <= N; i++){
        if(b[i] == 0){
            buvos[s][o] = i;
            b[i]++;
            if(ellenoriz(buvos, s, o)){

                if(s == o && s == n - 1){
                    kiir(buvos);
                    nr++;
                }

                if(o == n - 1){
                    BuvosNegyzet(buvos, b, s + 1, 0);
                }
                else{
                    BuvosNegyzet(buvos, b, s, o + 1);
                }
            }
            b[i] = 0;
        }

    }
}

int main(){
    int b[N + 2];
    for(int i = 0; i <= N; i++){
        b[i] = 0;
    }
    int buvos[n][n];
    BuvosNegyzet(buvos, b, 0, 0);
    cout<<"Buvos negyzetek szama: "<<nr;
}
