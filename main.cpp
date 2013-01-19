#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "huffman.h"
#include "convert.h"

using namespace std;

int main(void)
{
 int pil;
 string line,teks,hexa;
 char *input, *input2;
 char lagi[2]; 
 ofstream saveoutput;
 
while (lagi!="t")
{
 system("cls");
 cout<<"Pilih menu kompresi Huffman : "<<endl;;
 cout<<"1. Encoding"<<endl;
 cout<<"2. Decoding"<<endl;
 cout<<"3. Keluar"<<endl;
 cout<<"Pilihan : ";cin>>pil;

  ifstream myfile ("input/input_teks2.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
	}
  }
  else cout << "File tidak bisa dibuka"; 
	input = new char[(line.length())+1];

    strcpy(input,line.c_str());

	htTree *codeTree = buildTree(input);
	hlTable *codeTable = buildTable(codeTree);
	myfile.close(); 
if (pil==1) 
{ 
	system("cls");
	encode(codeTable,input);
	ifstream myfile2 ("output/temp.txt");
	if (myfile2.is_open())
    {
     while ( myfile2.good() )
     {
      getline (myfile2,teks);
	 }
    }
    else cout << "File tidak bisa dibuka"; 	
	input2 = new char[(teks.length())+1];
    strcpy(input2,teks.c_str());
	ConvertAscii(input2);		
    delete []input2;
	cout<<"\nLagi ? [y/t]"; cin>>lagi;
	if (lagi=="t")
	{
		return 0;
	}
}
else if (pil==2)
{
	system("cls");
	ifstream myfile2 ("output/temp.txt");
	if (myfile2.is_open())
    {
     while ( myfile2.good() )
     {
      getline (myfile2,teks);
	 }
    }
    else cout << "File tidak bisa dibuka"; 
    
	input2 = new char[(teks.length())+1];
    strcpy(input2,teks.c_str());
	decode(codeTree,input2);		
	delete []input2;
    cout<<"\nLagi ? [y/t]"; cin>>lagi;
	if (lagi=="t")
	{	
		return 0;
	}
}
else if (pil==3)
{
	return 0;
}
else
{
	system("cls");
	cout<<"Pilihan salah";
    cout<<"\nLagi ? [y/t]"; cin>>lagi;
	if (lagi=="t")
	{
		return 0;
	}
		
}
}
}
