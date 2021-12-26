#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
	char nama[20];
	int npm;
	int mk1;
	int mk2;
	int mk3;
	int mk4;
	int mk5;
};
data mahasiswa[100];
char cari[50];
int find;
int key;
int a , b, c;

void tampilmk1(int i) {
	if (mahasiswa[i].mk1 != 1){
		printf(" Pemrograman lanjut : Tidak Terdaftar\n");
	} else  {
		printf(" Pemrograman lanjut : Terdaftar\n");
	}
}

void tampilmk2(int i) {
	if (mahasiswa[i].mk2 != 1){
		printf(" Matematika Diskrit : Tidak Terdaftar\n");
	} else {
		printf(" Matematika Diskrit : Terdaftar\n");
	}
}

void tampilmk3(int i) {
	if (mahasiswa[i].mk3 != 1){
		printf(" Desain Basis Data  : Tidak Terdaftar\n");
	} else {
		printf(" Desain Basis Data  : Terdaftar\n");
	}
}

void tampilmk4(int i) {
	if (mahasiswa[i].mk4 != 1){
		printf(" Sistem Digital     : Tidak Terdaftar\n");
	} else {
		printf(" Sistem Digital     : Terdaftar\n");
	}
}

void tampilmk5(int i) {
	if (mahasiswa[i].mk5 != 1){
		printf(" Sistem Operasi     : Tidak Terdaftar\n");
	} else {
		printf(" Sistem Operasi     : Terdaftar\n");
	}
}

void inputdata() {
	printf(" Masukkan Jumlah Data Yang Akan diinput : ");
	scanf("%i", &b);
	printf("\n Masukan 1 jika mendaftar Mata Kuliah!!\n");
	printf(" Masukan 0 jika tidak!!\n");
	for(c = 0; c < b; c++) {
		printf("\n Data Mahasiswa ke- %d\n", a+1);
		printf(" Nama\t\t    : ");
		scanf("%s", &mahasiswa[a].nama);
		printf(" NPM\t\t    : ");
		scanf("%d", &mahasiswa[a].npm);
		printf(" Pemrograman Lanjut : ");
		scanf("%d", &mahasiswa[a].mk1);
		printf(" Matematika Diskrit : ");
		scanf("%d", &mahasiswa[a].mk2);
		printf(" Desain Basis Data  : ");
		scanf("%d", &mahasiswa[a].mk3);
		printf(" Sistem Digital     : ");
		scanf("%d", &mahasiswa[a].mk4);
		printf(" Sistem Operasi     : ");
		scanf("%d", &mahasiswa[a].mk5);
		a++;
	}
	printf("\n");
}

void tampildata() {
	int i, j;
	j = 0;
	for(i = 0; i < a; i++) {
		printf(" Data mahasiswa ke- : %d\n", j+1);
		printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
		printf(" NPM\t\t    : %i\n",mahasiswa[i].npm);
		printf("\n Mata Kuliah yang diambil : \n");
		tampilmk1(i);
		tampilmk2(i);
		tampilmk3(i);
		tampilmk4(i);
		tampilmk5(i);
		printf("\n");
		j++;
	}
}

void search_nama() {
	int i, j;
	printf("\n Masukan nama yang ingin Dicari  : ");
    scanf("%s", &cari);
    j = 0;
    data temp;
    for(i = 0; i < a; i++) {
        if(strcmp (cari, mahasiswa[i].nama) == 0) {
        	printf("\n Data ditemukan pada indeks ke-%i\n", i+1);
        	printf(" Nama : %s\n", mahasiswa[i].nama);
        	printf(" NPM : %d\n", mahasiswa[i].npm);
        	tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
        	printf("\n");
        	j++;
		}
    }
    if (j > 0){
    	printf(" Pencarian Selesai!!\n");
	}  else {
        printf("\n Data Tidak Ditemukan!!\n");
        printf(" Pencarian Selesai!!\n\n");
	}
}

void ascins_nama(data total []) {
	int f, g;
 	char cari;
 	int min, ada;
 	data temp;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min)-> nama,(total + g) -> nama)) > 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
	search_nama();
}

void descins_nama(data total []) {
	int f, g;
 	char cari;
 	int min, ada;
 	data temp;
	for (f = 0; f < a; f++) {
 		min = f;
	 	for (g = f; g < a; g++) {
	 		if ((strcmp ((total + min) -> nama,(total + g) -> nama)) < 0) {
	 			min = g;
	 		}
	 		temp = total [f];
	 		total [f] = total [min];
	 		total [min] = temp;
	 	}
	}
	search_nama();
}

void linsearch_nama() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Nama\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascins_nama(mahasiswa);
		break;
		case 2:
			descins_nama(mahasiswa);
		break;
	}
}

void search_npm() {
	int low = 0;
	int high = a-1;
	int mid = -1;
	printf("\n Masukan NPM yang akan dicari : ");
	scanf("%d", &key);
	while(low <= high) {
		mid = low + (((high - low) * (key - mahasiswa[low].npm) / (mahasiswa[high].npm - mahasiswa[low].npm)));
		if(mahasiswa[mid].npm == key) {
			printf("\n Data mahasiswa ke- : %d\n", mid+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[mid].nama);
			printf(" NPM\t\t    : %i\n",mahasiswa[mid].npm);
			printf(" Mata Kuliah yang diambil : \n");
			tampilmk1(mid);
			tampilmk2(mid);
			tampilmk3(mid);
			tampilmk4(mid);
			tampilmk5(mid);
			printf("\n");
			find++;
			break;
		} else {
			if(mahasiswa[mid].npm < key) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}
	if (find > 0){
    	printf(" Pencarian Selesai!!\n");
	}  else {
        printf("\n Data Tidak Ditemukan!!\n");
        printf(" Pencarian Selesai!!\n\n");
	}
}

void ascsel_npm() {
 	int i, j, indeks;
	data temp;
	for(i = 0; i < a-1; i++){
		indeks = i;
		for (j = i + 1; j < a; j++){
		if(mahasiswa[indeks].npm > mahasiswa[j].npm){
			indeks = j;
			}
		}
		temp = mahasiswa[i];
		mahasiswa[i] = mahasiswa[indeks];
		mahasiswa[indeks] = temp;
	}
	search_npm();
}

void descsel_npm() {
 	int i, j, indeks;
	data temp;
	for(i = 0; i < a-1; i++){
		indeks = i;
		for (j = i + 1; j < a; j++){
		if(mahasiswa[indeks].npm < mahasiswa[j].npm){
			indeks = j;
			}
		}
		temp = mahasiswa[i];
		mahasiswa[i] = mahasiswa[indeks];
		mahasiswa[indeks] = temp;
	}
	search_npm();
}

void intersearch_npm() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan NPM\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascsel_npm();
		break;
		case 2:
			descsel_npm();
		break;
	}
}

void ascbub_mk1() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk1<mahasiswa[j].mk1){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk1)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void descbub_mk1() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk1>mahasiswa[j].mk1){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk1)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void linsearch_mk1() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Mata Kuliah Pemrograman Lanjut\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascbub_mk1();
		break;
		case 2:
			descbub_mk1();
		break;
	}
}

void ascbub_mk2() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk2<mahasiswa[j].mk2){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk2)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void descbub_mk2() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk2>mahasiswa[j].mk2){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk2)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void linsearch_mk2() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Mata Kuliah Matematika Diskrit\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascbub_mk2();
		break;
		case 2:
			descbub_mk2();
		break;
	}
}

void ascbub_mk3() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk3<mahasiswa[j].mk3){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk3)
        {
        	ada = 1;
			printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void descbub_mk3() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk3>mahasiswa[j].mk3){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk3)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void linsearch_mk3() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Mata Kuliah Desain Basis Data\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascbub_mk3();
		break;
		case 2:
			descbub_mk3();
		break;
	}
}

void ascbub_mk4() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk4<mahasiswa[j].mk4){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk4)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void descbub_mk4() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk4>mahasiswa[j].mk4){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk4)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void linsearch_mk4() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Mata Kuliah Pemrograman Lanjut\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascbub_mk4();
		break;
		case 2:
			descbub_mk4();
		break;
	}
}

void ascbub_mk5() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk5<mahasiswa[j].mk5){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk5)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void descbub_mk5() {
	int i, j, k;
	int cari;
	int ada;
 	data temp;
	for(int i=0; i<a-1; i++){
		for(int j=0; j<a-1; j++){
			if(mahasiswa[j+1].mk5>mahasiswa[j].mk5){
				temp=mahasiswa[j];
				mahasiswa[j]=mahasiswa[j+1];
				mahasiswa[j+1]=temp;
			}
		}
	}
	
	printf("\n petunjuk\n");
	printf(" Masukkan '1' jika mengikuti mata kuliah\n");
	printf(" masukkan '0' jika tidak\n\n");
	printf(" Input Data yang Dicari (0/1): ");
    scanf("%d", &cari);
    for(i = 0; i < a; i++)
    {
        if(cari == mahasiswa[i].mk5)
        {
        	ada = 1;
        	printf(" Data mahasiswa ke- : %d\n", i+1);
			printf(" Nama\t\t    : %s\n",mahasiswa[i].nama);
			printf(" NPM\t\t    : %d\n",mahasiswa[i].npm);
			printf(" Mata Kuliah\t    : \n");
			tampilmk1(i);
			tampilmk2(i);
			tampilmk3(i);
			tampilmk4(i);
			tampilmk5(i);
			printf("\n");
        }
    }
    if(ada != 1) {
    	printf(" Hasil Pencarian\t: Data Tidak Ditemukan!\n");
	}
}

void linsearch_mk5() {
	int pilihan;
	system("cls");
	printf(" Pencarian Berdasarkan Mata Kuliah Pemrograman Lanjut\n");
	printf(" ===================================================\n");
	printf(" 1. Pencarian Ascending\n");
	printf(" 2. Pencarian Descending\n");
	printf(" ===================================================\n");
	printf(" Masukan pilihan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			ascbub_mk5();
		break;
		case 2:
			descbub_mk5();
		break;
	}
}

void menucari() {
	system("cls");
	int pilihan;
	printf(" Pencarian Data Mahasiswa\n");
	printf(" =========================================\n");
	printf(" 1. Pencarian Berdasarkan Nama\n");
	printf(" 2. Pencarian Berdasarkan NPM\n");
	printf(" 3. Pencarian Berdasarkan Mata Kuliah Pemrograman Lanjut\n");
	printf(" 4. Pencarian Berdasarkan Mata Kuliah Matematika Diskrit\n");
	printf(" 5. Pencarian Berdasarkan Mata Kuliah Desain Basis Data\n");
	printf(" 6. Pencarian Berdasarkan Mata Kuliah Sistem Digital\n");
	printf(" 7. Pencarian Berdasarkan Mata Kuliah Sistem Operasi\n");
	printf(" =========================================\n");
	printf(" Masukan metode pencarian yang akan digunakan : ");
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1:
			linsearch_nama();
		break;
		case 2:
			intersearch_npm();
		break;
		case 3:
			linsearch_mk1();
		break;
		case 4:
			linsearch_mk2();
		break;
		case 5:
			linsearch_mk3();
		break;
		case 6:
			linsearch_mk4();
		break;
		case 7:
			linsearch_mk5();
		break;
	}
}

int getoption(){
	int input;
	system("cls");
	printf(" Program Siamik Lite Version\n");
	printf(" ================================\n");
	printf(" 1. Input Data\n");
	printf(" 2. Tampilkan Data\n");
	printf(" 3. Mencari Data\n");
	printf(" 4. Selesai\n");
	printf(" ================================\n");
	printf(" Pilih (1-4) : ");
	scanf("%d",&input);
	return input;
}

int main(){
	
	int pilihan = getoption();
	char lanjut;
	
	while(pilihan != 4){
		switch(pilihan){
			case 1:
				inputdata();
			break;
			case 2:
				tampildata();
			break;
			case 3:
				menucari();
			break;
			default:
				printf(" Pilihan tidak ditemukan\n");
			break;
		}
		printf(" Lanjutkan (y/n) : ");
		lanjutkan:
		scanf("%c",&lanjut);
		if ( (lanjut == 'y') | (lanjut == 'Y')){
			pilihan = getoption();		
		} else if ((lanjut == 'n') | (lanjut == 'N')){
			break;
		} else {
			goto lanjutkan;
		}
	}
	printf ("\nProgram telah berakhir");
	return 0;
}
