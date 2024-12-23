#include <stdio.h>
#include <string.h>

#define JUMLAH_MAHASISWA 10

typedef struct {
    char npm[20];
    char nama[50];
    char prodi[30];
    float ipk;
} Mahasiswa;

// Deklarasi fungsi
void tampilkanMahasiswa(Mahasiswa *mhs, int jumlah);
void selectionSortByNPM(Mahasiswa *mhs, int jumlah);
void selectionSortByIPK(Mahasiswa *mhs, int jumlah);
void insertionSortByNPM(Mahasiswa *mhs, int jumlah);
void insertionSortByIPK(Mahasiswa *mhs, int jumlah);

void tampilkanMahasiswa(Mahasiswa *mhs, int jumlah) {
    printf("Daftar Mahasiswa:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("NPM   : %s\n", mhs[i].npm);
        printf("Nama  : %s\n", mhs[i].nama);
        printf("Prodi : %s\n", mhs[i].prodi);
        printf("IPK   : %.2f\n", mhs[i].ipk);
        printf("\n");
    }
}

void selectionSortByNPM(Mahasiswa *mhs, int jumlah) {
    int minIndex;
    Mahasiswa temp;
    for (int i = 0; i < jumlah - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (strcmp(mhs[j].npm, mhs[minIndex].npm) < 0) {
                minIndex = j;
            }
        }
        temp = mhs[i];
        mhs[i] = mhs[minIndex];
        mhs[minIndex] = temp;
    }
}

void selectionSortByIPK(Mahasiswa *mhs, int jumlah) {
    int minIndex;
    Mahasiswa temp;
    for (int i = 0; i < jumlah - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < jumlah; j++) {
            if (mhs[j].ipk < mhs[minIndex].ipk) {
                minIndex = j;
            }
        }
        temp = mhs[i];
        mhs[i] = mhs[minIndex];
        mhs[minIndex] = temp;
    }
}

void insertionSortByNPM(Mahasiswa *mhs, int jumlah) {
    Mahasiswa key;
    int j;
    for (int i = 1; i < jumlah; i++) {
        key = mhs[i];
        j = i - 1;
        while (j >= 0 && strcmp(mhs[j].npm, key.npm) > 0) {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = key;
    }
}

void insertionSortByIPK(Mahasiswa *mhs, int jumlah) {
    Mahasiswa key;
    int j;
    for (int i = 1; i < jumlah; i++) {
        key = mhs[i];
        j = i - 1;
        while (j >= 0 && mhs[j].ipk > key.ipk) {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j + 1] = key;
    }
}

int main() {
    Mahasiswa mhs[JUMLAH_MAHASISWA] = {
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

    int pilihan, kriteria;
    printf("Pilih metode pengurutan:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    printf("\nPilih kriteria pengurutan:\n");
    printf("1. Berdasarkan NPM\n");
    printf("2. Berdasarkan IPK\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &kriteria);

    if (pilihan == 1) { // Selection Sort
        if (kriteria == 1) {
            selectionSortByNPM(mhs, JUMLAH_MAHASISWA);
        } else if (kriteria == 2) {
            selectionSortByIPK(mhs, JUMLAH_MAHASISWA);
        } else {
            printf("Pilihan kriteria tidak valid!\n");
            return 1;
        }
    } else if (pilihan == 2) { // Insertion Sort
        if (kriteria == 1) {
            insertionSortByNPM(mhs, JUMLAH_MAHASISWA);
        } else if (kriteria == 2) {
            insertionSortByIPK(mhs, JUMLAH_MAHASISWA);
        } else {
            printf("Pilihan kriteria tidak valid!\n");
            return 1;
        }
    } else {
        printf("Pilihan metode tidak valid!\n");
        return 1;
    }

    printf("\nData Mahasiswa Setelah Diurutkan:\n");
    tampilkanMahasiswa(mhs, JUMLAH_MAHASISWA);

    return 0;
}
