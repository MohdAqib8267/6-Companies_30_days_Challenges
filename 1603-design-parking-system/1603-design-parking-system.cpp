class ParkingSystem {
public:
    int b1=0;
    int m1=0;
    int s1=0;
    ParkingSystem(int big, int medium, int small) {
        b1=big;
        m1=medium;
        s1=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            //big
            if(b1>0){
                b1--;
                return true;
            }
            else{
                return false;
            }
        }
        else if(carType==2){
            
            //medium
            if(m1>0){
                m1--;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(s1>0){
                s1--;
                return true;
            }
            else{
                return false;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */