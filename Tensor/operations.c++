#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;





 std::vector<float> create(float a,float b){
    vector <float> value={};
    for(int i=1;i<=a*b;i++){
        value.push_back(0);

    }
    return value;


    
    





}


int main(){
    int a;
    int b;
    cout<< "what is the shape";
    cin >> a >> b;

    
    vector<int> shape;
    shape.push_back(a);
    shape.push_back(b);

    vector<float> tensor =create(a,b);

    
    
    

    return 0;
}