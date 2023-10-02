#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout << "Reference Frequency: 16.5 Hz" << endl;
    cout << "Speed of Sound: 345 m/s" << endl;
    
    float freq1 = 16.35 * pow(2, 0) * pow((pow(2, 1 / 12.0)),0);
    float wave1 = 345 / freq1 * 100;
    cout << "Note: C0; nu: 0; k: 0; frequency: " << freq1 << " Hz; wavelength: " << wave1 << " cm" << endl;
    
    float freq2 = 16.35 * pow(2, 0) * pow((pow(2, 1 / 12.0)),1);
    float wave2 = 345 / freq2 * 100;
    cout << "Note: C#0; nu: 0; k: 1; frequency: " << freq2 << " Hz; wavelength: " << wave2 << " cm" << endl;
    
    float freq3 = 16.35 * pow(2, 0) * pow((pow(2, 1 / 12.0)),2);
    float wave3 = 345 / freq3 * 100;
    cout << "Note: D0; nu: 0; k: 2; frequency: " << freq3 << " Hz; wavelength: " << wave3 << " cm" << endl;
   
    float freq4 = 16.35 * pow(2, 4) * pow((pow(2, 1 / 12.0)),0);
    float wave4 = 345 / freq4 * 100;
    cout << "Note: C4; nu: 4; k: 0; frequency: " << freq4 << " Hz; wavelength: " << wave4 << " cm" << endl;
   
    float freq5 = 16.35 * pow(2, 7) * pow((pow(2, 1 / 12.0)),3);
    float wave5 = 345 / freq5 * 100;
    cout << "Note: D#7; nu: 7; k: 3; frequency: " << freq5 << " Hz; wavelength: " << wave5 << " cm" << endl;
    
    float freq6 = 16.35 * pow(2, 8) * pow((pow(2, 1 / 12.0)),0);
    float wave6 = 345 / freq6 * 100;
    cout << "Note: C8; nu: 8; k: 0; frequency: " << freq6 << " Hz; wavelength: " << wave6 << " cm" << endl;
    return 0;
}