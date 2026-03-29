#include <iostream>
#include <clocale>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

#define MAXEGIM 35
#define ORTSURTUNME 0.5
#define ORTSICAKLIK 20
void geri_git(){
    // Geri gitmesi için motor kodu
}
void metre_git(int x){
    //Motor enkoderi ile metre hesaplanır ve x kadar metre yol gidilir.
    return x;
}
int mesafe_olc(int x){
    //Motor enkoder verileri ile gidilen mesafeyi ölçer ve geri döndürür
    return x;
}

bool right_control(int x, int y){
    // Sağda engel varsa = return 0; 
    // Sağda engel yoksa = return 1; 

}

void go_around(){
    // Kaşılaşılan sorunun etrafından dolaşmaya yönelik fonksiyon
}

vector<int> get_values(int x, int y, int z, int a, int b){  //Sensör okuma verileri
    std::vector<int> values = {x,y,z,a,b};
    return values;
}

int e_way(){
    // Haritadan alınan verilere göre en kısa yolu belirleyen matematik formülü
}
int main(){
    setlocale(LC_ALL, "Turkish");
    int egim, surtunme, cukur, kaya, sicaklik, kalan_mesafe, rotasyon,rpm,tork,mesafe;
    rpm = 250;
    tork = 100; 
    rotasyon = 0; // Rover'ın yönü
    int sayac = 0;
    while(true){
        this_thread::sleep_for(chrono::seconds(0.1));
        get_values(egim,surtunme,cukur,kaya,sicaklik,kalan_mesafe);
        vector<int> konum = {50,50,50}; // Örnek bir x,y,z türünden konum
        vector<int> yeni_degerler;
        vector<int> degerler = {get_values(egim),get_values(surtunme),get_values(cukur),get_values(kaya),get_values(sicaklik),get_values(kalan_mesafe)};
        if(degerler == yeni_degerler){
            yeni_degerler = degerler;
            sayac = sayac+=1;
            if(sayac >= 20){
                rpm = rpm-=50;
                tork = tork-=50;
                if(right_control == 1){
                    rotasyon = rotasyon += 90;
                    metre_git(5);
                }
                if(right_control == 0);{
                    rotasyon = rotasyon -= 90;
                    metre_git(5);
                }
            }
        }
        else{
            yeni_degerler = degerler;
            sayac = 0;
        }
        
        if(egim>MAXEGIM){
            while(egim>MAXEGIM){
                get_values(egim,surtunme,cukur,kaya,sicaklik,kalan_mesafe);
                geri_git();
            }
            if(egim<MAXEGIM){
                rotasyon = rotasyon += 90; 
                metre_git(10);
            }
        }
        if(surtunme > ORTSURTUNME+0.3){
            while(surtunme > ORTSURTUNME+0.3){
                get_values(egim,surtunme,cukur,kaya,sicaklik,kalan_mesafe);
                geri_git();
                mesafe = mesafe_olc();
            }
            if(right_control == 1){
                rotasyon = rotasyon += 90;
                metre_git(mesafe);
            }
            if(right_control == 0){
                rotasyon = rotasyon -= 90;
                metre_git(mesafe);
            }
        }
        if(ORTSICAKLIK+150<sicaklik || ORTSICAKLIK-250> sicaklik){
            if(right_control == 1){
                rotasyon = rotasyon += 90;
                metre_git(5);
            }
            if(right_control == 0){
                rotasyon = rotasyon -= 90;
                metre_git(5);
            }
        }
        if(cukur == 1){
            if(right_control == 1){
                rotasyon = rotasyon += 90;
                go_around();
            }
            if(right_control == 0){
                rotasyon = rotasyon -= 90;
                go_around();
            }
        }
        if(kaya == 1){
            if(right_control == 1){
                rotasyon = rotasyon += 90;
                go_around();
            }
            if(right_control == 0){
                rotasyon = rotasyon -= 90;
                go_around();
            }
        }
        if(kalan_mesafe==0){
            break;
        }       
    }
}