#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRANSAKSI 100
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// Struktur untuk menyimpan data transaksi
typedef struct {
    int id;
    char tanggal[11]; // Format YYYY-MM-DD
    char keterangan[255];
    double jumlah;
} Transaksi;

// Prototipe fungsi
void tampilkanMenuUtama();
void tambahTransaksi(Transaksi transaksi[], int *n);
void tampilkanTransaksi(Transaksi transaksi[], int n);
void urutkanTransaksi(Transaksi transaksi[], int n);
int jumpSearch(Transaksi transaksi[], int n, char* key);
void cariTransaksi(Transaksi transaksi[], int n);

int main() {
    Transaksi transaksi[MAX_TRANSAKSI];
    int jumlahTransaksi = 0;
    int pilihanMenu;

    do {
        tampilkanMenuUtama();
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihanMenu);
        switch (pilihanMenu) {
            case 1:
                tambahTransaksi(transaksi, &jumlahTransaksi);
                break;
            case 2:
                tampilkanTransaksi(transaksi, jumlahTransaksi);
                break;
            case 3:
                cariTransaksi(transaksi, jumlahTransaksi);
                break;
            case 4:
                printf("terima kasih, semoga anda good rekening terus :)\n");
                pilihanMenu = 4;
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihanMenu != 4);

}

void tampilkanMenuUtama() {
    printf("\n=== Aplikasi Pengelolaan Keuangan Pribadi ===\n");
    printf("1. Tambah Transaksi\n");
    printf("2. Tampilkan Transaksi\n");
    printf("3. Cari Transaksi\n");
    printf("4. Keluar\n");
}

void tambahTransaksi(Transaksi transaksi[], int *n) {
    if (*n >= MAX_TRANSAKSI) {
        printf("Memori transaksi penuh!\n");
        return;
    }

    printf("Masukkan tanggal transaksi (YYYY-MM-DD): ");
    scanf("%s", transaksi[*n].tanggal);
    printf("Masukkan keterangan transaksi: ");
    scanf(" %[^\n]s", transaksi[*n].keterangan); // Read string with spaces
    printf("Masukkan jumlah transaksi: ");
    scanf("%lf", &transaksi[*n].jumlah);

    transaksi[*n].id = *n + 1; // Auto-increment ID
    (*n)++;
    printf("Transaksi berhasil ditambahkan!\n");
}

void tampilkanTransaksi(Transaksi transaksi[], int n) {
    printf("\nDaftar Transaksi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s: %.2f\n", transaksi[i].id, transaksi[i].tanggal, 
		transaksi[i].keterangan, transaksi[i].jumlah);
    }
}

void urutkanTransaksi(Transaksi transaksi[], int n) {
    int i, j;
    Transaksi temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (strcmp(transaksi[j].tanggal, transaksi[j + 1].tanggal) > 0) {
                temp = transaksi[j];
                transaksi[j] = transaksi[j + 1];
                transaksi[j + 1] = temp;
            }
        }
    }
}

int jumpSearch(Transaksi transaksi[], int n, char* key) {
    int step = sqrt(n);
    int prev = 0;

    while (strcmp(transaksi[MIN(n, prev + step) - 1].tanggal, key) < 0) {
        prev += step;
        if (prev >= n) return -1;
    }

    while (prev < MIN(n, prev + step) && strcmp(transaksi[prev].tanggal, key) < 0) {
        prev++;
        if (prev == n) return -1;
    }

    if (prev < n && strcmp(transaksi[prev].tanggal, key) == 0)
        return prev;

    return -1;
}

void cariTransaksi(Transaksi transaksi[], int n) {
    char tanggalCari[11];
    printf("Masukkan tanggal transaksi yang dicari (YYYY-MM-DD): ");
    scanf("%s", tanggalCari);
    urutkanTransaksi(transaksi, n);
    int index = jumpSearch(transaksi, n, tanggalCari);
    if (index != -1)
        printf("Transaksi ditemukan: %d. %s - %s: %.2f\n", transaksi[index].id, 
		transaksi[index].tanggal, transaksi[index].keterangan, transaksi[index].jumlah);
    else
        printf("Transaksi tidak ditemukan.\n");
}