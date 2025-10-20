#include <iostream>
using namespace std;

struct Produk {
    int id;
    Produk* kiri;
    Produk* kanan;
    Produk(int i): id(i), kiri(nullptr), kanan(nullptr) {}
};

Produk* tambahProduk(Produk* root, int id) {
    if (!root) return new Produk(id);
    if (id < root->id) root->kiri = tambahProduk(root->kiri, id);
    else if (id > root->id) root->kanan = tambahProduk(root->kanan, id);
    return root;
}

bool cariProduk(Produk* root, int id) {
    if (!root) return false;
    if (root->id == id) return true;
    return (id < root->id) ? cariProduk(root->kiri, id) : cariProduk(root->kanan, id);
}

void inorder(Produk* root) {
    if (!root) return;
    inorder(root->kiri);
    cout << root->id << " ";
    inorder(root->kanan);
}

void preorder(Produk* root) {
    if (!root) return;
    cout << root->id << " ";
    preorder(root->kiri);
    preorder(root->kanan);
}

void postorder(Produk* root) {
    if (!root) return;
    postorder(root->kiri);
    postorder(root->kanan);
    cout << root->id << " ";
}

int minProduk(Produk* root) {
    while (root && root->kiri) root = root->kiri;
    return root ? root->id : -1;
}

int maxProduk(Produk* root) {
    while (root && root->kanan) root = root->kanan;
    return root ? root->id : -1;
}

int hitungProduk(Produk* root) {
    if (!root) return 0;
    return 1 + hitungProduk(root->kiri) + hitungProduk(root->kanan);
}

int totalID(Produk* root) {
    if (!root) return 0;
    return root->id + totalID(root->kiri) + totalID(root->kanan);
}

int main() {
    Produk* root = nullptr;
    int pilih, id;
    do {
        cout << "\n=== Data ID Produk ===\n";
        cout << "1.Tambah  2.Cari  3.Inorder  4.Preorder  5.Postorder\n";
        cout << "6.Min  7.Max  8.Hitung  9.Total ID  10.Keluar\nPilih: ";
        cin >> pilih;
        if (pilih == 1) { cout << "Masukkan ID produk: "; cin >> id; root = tambahProduk(root, id); }
        else if (pilih == 2) { cout << "Cari ID: "; cin >> id; cout << (cariProduk(root, id) ? "Ditemukan\n" : "Tidak ada\n"); }
        else if (pilih == 3) { inorder(root); cout << endl; }
        else if (pilih == 4) { preorder(root); cout << endl; }
        else if (pilih == 5) { postorder(root); cout << endl; }
        else if (pilih == 6) { cout << "ID terkecil: " << minProduk(root) << endl; }
        else if (pilih == 7) { cout << "ID terbesar: " << maxProduk(root) << endl; }
        else if (pilih == 8) { cout << "Jumlah produk: " << hitungProduk(root) << endl; }
        else if (pilih == 9) { cout << "Total semua ID: " << totalID(root) << endl; }
    } while (pilih != 10);
}
