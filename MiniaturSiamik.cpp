#include <stdio.h>
#include <stdlib.h>

struct data {
	char *nama[10];
	char *npm [10];
	char *matkul [20];
	char *kodeKelas [10];
};
struct data mahasiswa[50];

int a,b,c,d;

void add(int n){
	
	for (int i=0 ; i<n ; i++){
		printf("Data ke: %i\n", i+1);
		printf("Masukkan Nama Mahasiswa	: ");
		scanf ("%s", &mahasiswa[i].nama);
		printf("Masukkan NPM mahasiswa	: ");
		scanf ("%s", &mahasiswa[i].npm);
		printf("Masukkan Mata Kuliah	: ");
		scanf ("%s", &mahasiswa[i].matkul);
		printf("Masukkan Kode Kelas	: ");
		scanf ("%s", &mahasiswa[i].kodeKelas);
		printf("\n\n");
		
	}
}

void show(int n){
	
	printf("Data Yang Diinput Adalah\n");
	for (int i=0 ; i<n ; i++){
		printf("Data ke: %i\n", i+1);
		printf("Nama Mahasiswa	: %s\n", mahasiswa[i].nama);
		printf("NPM Mahasiswa	: %s\n", mahasiswa[i].npm);
		printf("Mata Kuliah	: %s\n", mahasiswa[i].matkul);
		printf("Kode Kelas	: %s\n", mahasiswa[i].kodeKelas);
		printf("\n");
	}
}

int main() {
	
	printf ("Masukkan jumlah data: ");
	scanf ("%i", &a);
	printf("\n");
	
	add(a);
	show(a);
}
