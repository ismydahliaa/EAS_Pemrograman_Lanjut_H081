#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char npm[20];
    char nama[40];
    char prodi[40];
    float ipk;
} Mahasiswa;

void tukar(Mahasiswa *a, Mahasiswa *b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

int perluTukar(Mahasiswa a, Mahasiswa b, int kolom, int ascending) {
    int result;
    switch (kolom) {
        case 1: result = strcmp(a.npm, b.npm); break;
        case 2: result = strcmp(a.nama, b.nama); break;
        case 3: result = strcmp(a.prodi, b.prodi); break;
        case 4: result = (a.ipk > b.ipk) - (a.ipk < b.ipk); break;
        default: return 0;
    }
    return ascending ? result > 0 : result < 0;
}

void urutkan(Mahasiswa data[], int n, int kolom, int ascending) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (perluTukar(data[j], data[j + 1], kolom, ascending))
                tukar(&data[j], &data[j + 1]);
}

void tampilkanData(Mahasiswa data[], int n) {
    printf("%-12s %-20s %-15s %-5s\n", "NPM", "Nama", "Prodi", "IPK");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-12s %-20s %-15s %.2f\n", data[i].npm, data[i].nama, data[i].prodi, data[i].ipk);
}

int main() {
    Mahasiswa data[MAX] = {
        {"23061010060", "ismy dahlia", "teknik industri", 3.90},
        {"23081010270", "dwi ariyanti", "informatika", 3.89},
        {"23041010133", "eva salsabila", "ilmu komunikasi", 3.60},
        {"23021010321", "shelina ramadhani", "akuntansi", 4.00},
        {"23091010085", "assyifa putri", "kedokteran", 4.00},
        {"23092010031", "sherly putri", "kedokteran gigi", 3.89},
        {"23022010118", "ayu andayani", "manajemen", 3.60},
        {"23071010001", "vanessa josy", "arsitektur", 3.94},
        {"23093010103", "cantika berliana", "psikolog", 3.76},
        {"23023010181", "revan putra", "agroteknologi", 3.81}
    };
    int kolom, urutan;

    printf("Data Sebelum Diurutkan:\n\n");
    tampilkanData(data, MAX);

    printf("\nUrutkan berdasarkan:\n1. NPM\n2. Nama\n3. Prodi\n4. IPK\nPilih kolom (1-4): ");
    while (scanf("%d", &kolom), kolom < 1 || kolom > 4)
        printf("Pilihan tidak valid. Silakan coba lagi: ");

    printf("\nUrutan:\n1. terkecil\n2. terbesar\nPilih urutan (1-2): ");
    while (scanf("%d", &urutan), urutan < 1 || urutan > 2)
        printf("Pilihan tidak valid. Silakan coba lagi: ");

    urutkan(data, MAX, kolom, urutan == 1);
    printf("\nData Setelah Diurutkan:\n");
    tampilkanData(data, MAX);

    return 0;
}

