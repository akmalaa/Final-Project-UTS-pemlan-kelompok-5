#include <iostream>

using namespace std;


struct data{
    string nama;
    int npm;
    int matkul1;
    int matkul2;
            }mahasiswa[100];

void inputdata(int n){
    for (int a=0; a<n; a++){
    cout << "mahasiswa ke- " << a+1 << endl;
    cout << "nama: "; cin >> mahasiswa[a].nama;
    cout << "npm: ";cin >> mahasiswa[a].npm;
    cout << "pemrograman: ";cin >> mahasiswa[a].matkul1;
    cout << "matdis: ";cin >> mahasiswa[a].matkul2;
    cout << "\n";
  }
}

void tampildata(int n){
    for (int a=0; a<n; a++){
    cout << "mahasiswa ke- " << a+1 << endl;
    cout << "nama: " << mahasiswa[a].nama << endl;
    cout << "npm: " << mahasiswa[a].npm << endl;
    cout << "matkul yang diikuti: \n";
    if(mahasiswa[a].matkul1==1){
       cout << "pemrograman \n";
    }
     if(mahasiswa[a].matkul2==1){
       cout << "matdis \n";
    }
    cout << "\n";
  }
}

int main()
{
  char pilihan1, pilihan2;
  int n;
  cout << "masukkan data yang ingin diinput: "; cin >> n;

  cout << "\nKETIK 1 JIKA KAMU MENGIKUTI MATA PERKULIAHAN TERSEBUT, KETIK 0 JIKA TIDAK\n" << endl;

  inputdata(n);

  cout << "1. tampilkan data\n2. cari data\n\n="; cin >> pilihan1;

  if (pilihan1=='1'){

    tampildata(n);

  } else if(pilihan1=='2'){

      cout << "cari berdasarkan apa?" << endl;
      cout << "1. nama\n2. npm\n3. matkul pemrograman\n4. matkul matdis\n\n="; cin >> pilihan2;

      if(pilihan2=='1'){

      }else if(pilihan2=='2'){

      }else if(pilihan2=='3'){

      }else if(pilihan2=='4'){

      }

  }

  cout<< ""

    return 0;
}
