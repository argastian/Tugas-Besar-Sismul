#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ConvertAscii(const char* input)
{
	int panjang = strlen(input);     
	string as;
	int binary[8];    
	int asciiNum = 0;     
	char ascii;      
	ofstream saveoutput;
	cout << " ";
	
	int z = 0;   
	
	for(int x = 0; x < panjang / 8; x++)     
	{
		for(int a = 0; a < 8; a++)      
		{
			binary[a] = (int) input[z] - 48;      
			z++;
		}
		
		int power[8];    
		int counter = 7;        
		for(int x = 0; x < 8; x++)
		{
			power[x] = counter;     
			counter--;   
		}
		
		for(int y = 0; y < 8; y++)   
		{
			double a = binary[y];    
			double b = power[y];   
			
			asciiNum += a* pow(2, b);  
		}
		
		ascii = asciiNum;  
		asciiNum = 0;    
		as = as+ascii;
	
	}	
	saveoutput.open ("output/output_text.txt");
    saveoutput << as;
    saveoutput.close();	
}
