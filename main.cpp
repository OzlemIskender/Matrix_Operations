#include <iostream>

using namespace std;

int main(int argc, char **argv) {


  int sec=1;
  switch(sec){
    case 1 :
      Matrix<int> *a=new Matrix<int>(2,3,1);
      a->MatrixPrint();
      Matrix<double> b(2,3,9.);
      b.print();
      a = b + a*1;
      a.print("file.txt"); 
      break;
    case 2 :
      Matrix<double> m1(4,4,'e');
      Matrix<double> m2(4,4,'r'); 
      m2.print();
      m1 = m1 * m2;
      m1.print();
      break;
    case 3 :
      
      Matrix<double> m3(5,4,1);
      m3.print();

      m3.resize(10,3);

      m3.print();
      break;
    case 4 :
     
      Matrix<double> m4(2,2,'L');
      Matrix<double> m5 = m4 * m4.inv();
      m5.print(); 

      Matrix<double> m6(3,3,'L');
      cout<<m6.det(); 
      break;
    case 5 :
   
      break;
    case 6 :
      Image im1("custom.bin");
      im1.threshold(128);
      im1.print("custom2.bin");
      break;
    case 7 :
      Image im2("imfile.bmp");
      im2.print("imfile2.bmp");
      break;
    case 8 :
      Image im3("custom.bin");
      im3.threshold(128);
      im3.erosion();
      im3.print("custom2.bin");
      break;
    case 9 :
   
      Table<int> t1(4,4,1);
      t1.print(); 
      string s = {"Sat1","Sat2"};
      t1.setRowNames(s,2);
      t1.print();
      break;
    case 10 :
      Table<int> t2(3,4,'r');
      t2.print();
      cout<<t2.itemAt(1,1)<<endl;
      cout<<t2.itemAt("A2")<<endl;  
      string s2 = {"S1","S2","S3"};
      t1.setColNames(s2,3);
      cout<<t2.itemAt("1","S2")<<endl;  
      break;
  }
}
