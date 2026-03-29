#include <clocale>
#include <vector>
#include <chrono>
#include <thread>

#define MAXSLOPE 35
#define AVRGFRICTION 0.5
#define AVRGTEMP 20

using namespace std;
void backward(int x){
    // Geri gitmesi için motor kodu
}

void forward(int x){
    //Motor enkoderi ile metre hesaplanır ve x kadar metre yol gidilir.
    return x;
}

int measureTheDistance(int x){
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

vector<int> sensorData(int x, int y, int z, int a, int b){  //Sensör okuma verileri
    vector<int> values = {x,y,z,a,b};
    return values;
}

int routeCalc(){
    // Haritadan alınan verilere göre en kısa yolu belirleyen matematik formülü
}
int main(){
    int ground_slope, friction, crater, obstacle, temperature, restOfDist, rotation,rpm,torque,distance;
    int rpm = 250;
    int torque = 100; 
    int rotation = 0; // Rover'ın yönü
    int count = 0;

    vector<int> location = {50,50,50}; // Örnek bir x,y,z türünden konum
    vector<int> datas;
    vector<int> newDatas = {sensorData(ground_slope),sensorData(friction),sensorData(crater),sensorData(obstacle),sensorData(temperature),sensorData(kalan_mesafe)};
    while(true){
        this_thread::sleep_for(chrono::seconds(0.1));
        get_values(ground_slope,friction,crater,obstacle,temperature,restOfDist);
        if( datas == newDatas){
            newDatas = datas;
            count += 1;
            if(count >= 20){
                rpm -= 50;
                torque -= 50;
                if(right_control == 1){
                    rotation += 90;
                    forward(5);
                }
                if(right_control == 0);{
                    rotation -= 90;
                    forward(5);
                }
            }
        }
        else{
            newDatas = datas;
            count = 0;
        }
        
        if(ground_slope>MAXSLOPE){
            while(ground_slope>MAXSLOPE){
                get_values(ground_slope,friction,crater,obstacle,temperature,restOfDist);
                backward(10);
            }
            if(ground_slope<MAXSLOPE){
                rotation += 90; 
                forward(10);
            }
        }
        if(friction > AVRGFRICTION+0.3){
            while(friction > AVRGFRICTION+0.3){
                get_values(ground_slope,friction,crater,obstacle,temperature,restOfDist);
                backward(10);
                distance = measureTheDistance();
            }
            if(right_control == true){
                rotation += 90;
                forward(distance);
            }
            else{
                rotation -= 90;
                backward(distance);
            }
        }
        if(AVRGTEMP+150<temperature || AVRGTEMP-250> temperature){
            if(right_control == true){
                rotation += 90;
                forward(5);
            }
            else{
                rotation -= 90;
                forward(5);
            }
        }
        if(crater == 1){
            if(right_control == true){
                rotation += 90;
                go_around();
            }
            else{
                rotation -= 90;
                go_around();
            }
        }
        if(obstacle == 1){
            if(right_control == true){
                rotation += 90;
                go_around();
            }
            else{
                rotation -= 90;
                go_around();
            }
        }
        if(restOfDist==0){
            break;
        }       
    }
}