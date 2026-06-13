// projek sederhana pribadi terakhir :
// SPIE (Sistem Perbankan & Investasi ter-Enskripsi)
#include<iostream>
#include<string>
#include<random>
#include<cmath>
#include <iomanip>
#include<algorithm>
#include<cstdint>
#include<vector>
#include<chrono>
#include<thread>
#define ut uint32_t
using namespace std;

class Akun {
private :
    string nama_lengkap = "icip siricip";
    string nomor_telepon = "123";
    string password = "abcdef"; 
    string nomor_rekening = "0123456789"; 
    string nomor_pin =  "000000"; 
public :
    int dana = 10000000000;
    string username = "icip_promah";
    void awal(const string& nl,const string& nt,const string& us,const string& pas,const string& pin,const string& nr) {
        nama_lengkap = nl;
        nomor_telepon = nt;
        username = us;
        password = pas;
        nomor_pin = pin;
        nomor_rekening = nr;
    }
    void ubahNL(const string& x) {
        nama_lengkap = x;
    }
    void ubahNT(const string& x) {
        nomor_telepon = x;
    }
    void ubahPAS(const string& x) {
        password = x;
    }
    void ubahNP(const string& x) {
        nomor_pin = x;
    }
    void ubahUS(const string& x) {
        username = x;
    }
    void ubahDANA(int n) {
        dana = n;
    }
    string tampilkanNL() {
        return nama_lengkap;
    }
    string tampilkanNT() {
        return nomor_telepon;
    }
    string tampilkanPAS() {
        return password;
    }
    string tampilkanNR() {
        return nomor_rekening;
    }
    string tampilkanNP() {
        return nomor_pin;
    }
    string tampilkanUS() {
        return username;
    }
    int tampilkanDANA() {
        return dana;
    }
    bool cekNL(const string& x) {
        if(x == nama_lengkap) return true;
        else return false;
    }
    bool cekNT(const string& x) {
        if(x == nomor_telepon) return true;
        else return false;
    }
    bool cekPAS(const string& x) {
        if(x == password) return true;
        else return false;
    }
    bool cekNR(const string& x) {
        if(x == nomor_rekening) return true;
        else return false;
    }
    bool cekNP(const string& x) {
        if(x == nomor_pin) return true;
        else return false;
    }
    bool cekUS(const string& x) {
        if(x == username) return true;
        else return false;
    }
};

class pinjaman {
public :
    double total() {
        double sum = 0;
        for(int i = 0; i < riwayat_pinjaman.size(); i++) {
            sum += (riwayat_pinjaman[i].jumlah_pinjaman * (riwayat_pinjaman[i].persen_bunga + 1));
        }
        return sum;
    }
    void tambah(string a,double b,double c,double d) {
        riwayat_pinjaman.push_back({
            a,
            b,
            c,
            d,
        });
    };
    void tambah1(double i) {
        pinjaman_awal.push_back(i);
    }
    string tampilkanNB(int i) {
        return riwayat_pinjaman[i].nama_bank;
    }
    double tampilkanJP(int i) {
        return riwayat_pinjaman[i].jumlah_pinjaman;
    }
    double tampilkanPB(int i) {
        return riwayat_pinjaman[i].persen_bunga;
    }
    int tampilkanWP(int i) {
        return riwayat_pinjaman[i].waktu_pinjaman;
    }
    int ukuran() {
        return riwayat_pinjaman.size();
    }
    double tampilkanPA(int i) {
        return pinjaman_awal[i];
    }
    void ubahJP(int i,int n) {
        riwayat_pinjaman[i].jumlah_pinjaman = n;
    }
    void hapus(int i) {
        riwayat_pinjaman.erase(riwayat_pinjaman.begin() + i);
    }
private :
    struct Data_pinjaman {
        string nama_bank;
        double jumlah_pinjaman;
        double persen_bunga;
        double waktu_pinjaman;
    };
    vector<Data_pinjaman>riwayat_pinjaman; 
    vector<double>pinjaman_awal;
};

class investasi {
private:
    struct Investasi {
        string jenis_investasi; 
        string nama_investasi; 
        double jumlah_aset; 
        const double harga_beli;
        double harga_beli_sekarang;
        double total_nilai_aset; 
        double profit_rugi;
        double persen_profit;
    };
    vector<Investasi>Informasi_investasi;

public:
    void tambah(string a,string b, double c,double d,double e,double f,double g, double h) {
        Informasi_investasi.push_back({
            a,
            b,
            c,
            d,
            e,
            f,
            g,
            h,
        });
    }
    string tampilkanJI(int i) {
        return Informasi_investasi[i].jenis_investasi;
    }
    string tampilkanNI(int i) {
        return Informasi_investasi[i].nama_investasi;
    }
    double tampilkanJA(int i) {
        return Informasi_investasi[i].jumlah_aset;
    }
    double tampilkanHB(int i) {
        return Informasi_investasi[i].harga_beli;
    }
    double tampilkanHBS(int i) {
        return Informasi_investasi[i].harga_beli_sekarang;
    }
    double tampilkanTNI(int i) {
        return Informasi_investasi[i].total_nilai_aset;
    }
    double tampilkanPR(int i) {
        return Informasi_investasi[i].profit_rugi;
    }
    double tampilkanPP(int i) {
        return Informasi_investasi[i].persen_profit;
    }
    double jumlah_semua_harga_aset() {
        int sum = 0;
        for(int i = 0; i < Informasi_investasi.size(); i++) {
            sum += Informasi_investasi[i].total_nilai_aset;
        }
        return sum;
    }
    double jumlah_semua_profit() {
        int sum = 0;
        for(int i = 0; i < Informasi_investasi.size(); i++) {
            sum += Informasi_investasi[i].profit_rugi;
        }
        return sum;
    }
    double jumlah_semua_persen_profit() {
        int sum = 0;
        for(int i = 0; i < Informasi_investasi.size(); i++) {
            sum += Informasi_investasi[i].persen_profit;
        }
        return sum;
    }
    int ukuran() {
        return Informasi_investasi.size();
    }
    double asetEmas() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Emas digital") {
                sum += Informasi_investasi[i].total_nilai_aset;
            }
        }
        return sum;
    }
    double jumlahEmas() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Emas digital") {
                sum += Informasi_investasi[i].jumlah_aset;
            }
        }
        return sum;
    }
    double asetObligasi() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Surat Obligasi") {
                sum += Informasi_investasi[i].total_nilai_aset;
            }
        }
        return sum;
    }
    double jumlahObligasi() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Surat Obligasi") {
                sum += Informasi_investasi[i].jumlah_aset;
            }
        }
        return sum;
    }
    double asetSaham() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Saham") {
                sum += Informasi_investasi[i].total_nilai_aset;
            }
        }
        return sum;
    }
    double jumlahSaham() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Saham") {
                sum += Informasi_investasi[i].jumlah_aset;
            }
        }
        return sum;
    }
    double asetCrypto() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Crypto") {
                sum += Informasi_investasi[i].total_nilai_aset;
            }
        }
        return sum;
    }
    double jumlahCrypto() {
        int sum = 0;
        for(int i = 0; i < ukuran(); i++) {
            if(Informasi_investasi[i].nama_investasi == "Crypto") {
                sum += Informasi_investasi[i].jumlah_aset;
            }
        }
        return sum;
    }
};

class bahanInvestasi {
public:
    void ubahPersen(int i,double c) {
        database[i].persen_profit = c;
        double x = database[i].harga + c * database[i].harga;
        database[i].harga = x;
    }
    string tampilkan_jenis_investasi(int i) {
        return database[i].jenis_investasi;
    }
    string tampilkan_nama(int i) {
        return database[i].nama;
    }
    double tampilkan_harga(int i) {
        return database[i].harga;
    }
    double tampilkan_persen_profit(int i) {
        return database[i].persen_profit;
    }
private:
    struct bahan {
        string jenis_investasi;
        string nama;
        double harga;
        double persen_profit;
    };
    vector<bahan>database = {
        {"Emas","",2750000,0.2},
        {"Obligasi","Pemerintah",1000000,0.1},
        {"Saham","BBCA",5700,0.01}, 
        {"Saham","BBRI",2950,0.21},
        {"Saham","BUMI",168,0.34}, 
        {"Saham","TPIA",1785,-0.12},
        {"Saham","BMRI",4080,-0.23}, 
        {"Saham","CUAN",630,0},
        {"Saham","PSSA",492,0.1}, 
        {"Saham","BRPT",1940,0.023},
        {"Saham","PTRO",4670,0.01}, 
        {"Saham","WBSA",675,0.05},
        {"Saham","KJEN",212,-0.45}, 
        {"Saham","BREN",3300,0.1},
        {"Crypto","Bitcoin",1320000000,1},
        {"Crypto","Etherium",37700000,-1.2}
    };
};

class sha256 {
public :
    string has(string x) {
        return bit512(x);
    }
private :
    vector<string> k = {
        "01000010100010100010111110011000",
        "01110001001101110100010010010001",
        "10110101110000001111101111001111",
        "11101001101101011101101110100101",
        "00111001010101101100001001011011",
        "01011001111100010001000111110001",
        "10010010001111111000001010100100",
        "10101011000111000101111011010101",
        "11011000000001111010101010011000",
        "00010010100000110101101100000001",
        "00100100001100011000010110111110",
        "01010101000011000111110111000011",
        "01110010101111100101110101110100",
        "10000000110111101011000111111110",
        "10011011110111000000011010100111",
        "11000001100110111111000101110100",
        "11100100100110110110100111000001",
        "11101111101111100100011110000110",
        "00001111110000011001110111000110",
        "00100100000011001010000111001100",
        "00101101111010010010110001101111",
        "01001010011101001000010010101010",
        "01011100101100001010100111011100",
        "01110110111110011000100011011010",
        "10011000001111100101000101010010",
        "10101000001100011100011001101101",
        "10110000000000110010011111001000",
        "10111111010110010111111111000111",
        "11000110111000000000101111110011",
        "11010101101001111001000101000111",
        "00000110110010100110001101010001",
        "00010100001010010010100101100111",
        "00100111101101110000101010000101",
        "00101110000110110010000100111000",
        "01001101001011000110110111111100",
        "01010011001110000000110100010011",
        "01100101000010100111001101010100",
        "01110110011010100000101010111011",
        "10000001110000101100100100101110",
        "10010010011100100010110010000101",
        "10100010101111111110100010100001",
        "10101000000110100110011001001011",
        "11000010010010111000101101110000",
        "11000111011011000101000110100011",
        "11010001100100101110100000011001",
        "11010110100110010000011000100100",
        "11110100000011100011010110000101",
        "00010000011010101010000001110000",
        "00011001101001001100000100010110",
        "00011110001101110110110000001000",
        "00100111010010000111011101001100",
        "00110100101100001011110010110101",
        "00111001000111000000110010110011",
        "01001110110110001010101001001010",
        "01011011100111001100101001001111",
        "01101000001011100110111111110011",
        "01110100100011111000001011101110",
        "01111000101001010110001101101111",
        "10000100110010000111100000010100",
        "10001100110001110000001000001000",
        "10010000101111101111111111111010",
        "10100100010100000110110011101011",
        "10111110111110011010001111110111",
        "11000110011100010111100011110010"
    };
    const vector<string>H0 = { // 32 bit
        "01101010000010011110011001100111",
        "10111011011001111010111010000101",
        "00111100011011101111001101110010",
        "10100101010011111111010100111010",
        "01010001000011100101001001111111",
        "10011011000001010110100010001100",
        "00011111100000111101100110101011",
        "01011011111000001100110100011001",
    };
    string w[64];
    string h[8];
    string xr(const string& a,const string& b) {
        string baru;
        for(int i= 0; i < a.size(); i++) {
            if((a[i] == '1' && b[i] == '0') or (b[i] == '1' && a[i] == '0')) baru += "1";
            else baru += "0";
        }
        return baru;
    }
    string dan(const string& a,const string& b) {
        string baru;
        for(int i= 0; i < a.size(); i++) {
            if(a[i] == '1' and b[i] == '1') baru += "1";
            else baru += "0";
        }
        return baru;
    }
    string invers(const string& a) {
        string baru;
        for(int i= 0; i < a.size(); i++) {
            if(a[i] == '1') baru += "0";
            else baru += "1";
        }
        return baru;
    }
    string shr(const string& a,int n) {
        string baru(32,'0');
        for(int i = n; i < 32; i++) {
            baru[i] = a[i - n];
        }
        return baru;
    }
    string rotr(const string& a, int n) {
        n %= 32;
        return a.substr(32 - n) + a.substr(0, 32 - n);
    }
    string maj(const string& a,const string& b,const string& c) {
        string baru1,baru2,a1,a2,a3;
        a1 = dan(a,b);
        a2 = dan(a,c);
        a3 = dan(b,c);
        baru1 = xr(a1,a2);
        baru2 = xr(baru1,a3);
        return baru2;
    }
    string ch(const string& a,const string& b,const string& c) {
        string a1,a2,a3;
        a1 = dan(a,b);
        a2 = dan(invers(a),c);
        a3 = xr(a1,a2);
        return a3;
    }
    string tau0(const string& x) {
        string a,b,c,d;
        a = rotr(x,7);
        b = rotr(x,18);
        c = shr(x,3);
        a = xr(a,b);
        c = xr(a,c);
        return c;
    }
    string tau1(const string& x) {
        string a,b,c,d;
        a = rotr(x,17);
        b = rotr(x,19);
        c = shr(x,10);
        a = xr(a,b);
        c = xr(a,c);
        return c;
    }
    string sigma0(string x) {
        string a,b,c,d;
        a = rotr(x,2);
        b = rotr(x,13);
        c = rotr(x,22);
        a = xr(a,b);
        c = xr(a,c);
        return c;
    }
    string sigma1(string x) {
        string a,b,c,d;
        a = rotr(x,6);
        b = rotr(x,11);
        c = rotr(x,25);
        a = xr(a,b);
        c = xr(a,c);
        return c;
    }
    ut pembaca(const string& hasil) {
        ut n = 0;
        for (char c : hasil) {
            n = (n << 1) | (c == '1');
        }
        return n;
    }
    string biner(ut x) {
        string m;
        if(x == 0) return "0";
        while(x > 0) {
            if(x % 2 == 0) m += "0";
            else m += "1";
            x /= 2;
        }
        reverse(m.begin(),m.end());
        return m;
    }
    string bit8(string abc) {
        while(abc.size() < 8) {
            abc = "0" + abc;
        }
        return abc;
    }
    string bit32(string abc) {
        while(abc.size() < 32) {
            abc = "0" + abc;
        }
        return abc;
    }
    string bit64(string abc) {
        string bit;
        bit += biner(abc.size() * 8);
        string x;
        for(int i = 0; i < 64 - bit.size(); i++) {
            x+= "0";
        }
        bit = x + bit;
        return bit;
    }
    string bit512(string abc) {
        h[0] = H0[0];
        h[1] = H0[1];
        h[2] = H0[2];
        h[3] = H0[3];
        h[4] = H0[4];
        h[5] = H0[5];
        h[6] = H0[6];
        h[7] = H0[7];
        string bit;
        for(int i = 0; i< abc.size(); i++) {
            bit += bit8(biner((ut)(abc[i])));
        }
        bit += "1";
        while(bit.size() % 512 != 448) {
            bit += "0";
        }
        bit += bit64(abc);
        for(int i = 0; i < 16; i++) {
            w[i] = bit.substr(i*32,32);
        }
        for(int i = 16; i < 64; i++) {
            ut sum = pembaca(tau1(w[i-2])) + pembaca(w[i-7]) + pembaca(tau0(w[i-15])) + pembaca(w[i-16]);
            w[i] = bit32(biner(sum & 0xFFFFFFFF));
        }
        string hasilAkhir;
        mainloop(hasilAkhir);
        return hasilAkhir;
    }
    string a,b,c,d,e,f,g,hh;
    void mainloop(string& x) {
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        hh = h[7];
        for(int i= 0; i < 64; i++) {
            string s1 = sigma1(e);
            string chh = ch(e,f,g);
            string temp1 = bit32(biner((pembaca(hh) + pembaca(s1) + pembaca(chh) + pembaca(k[i]) + pembaca(w[i])) & 0xFFFFFFFF));
            string s0 = sigma0(a);
            string majj = maj(a,b,c);
            string temp2 = bit32(biner((pembaca(s0) + pembaca(majj))& 0xFFFFFFFF));

            hh = g;
            g = f;
            f = e;
            e = bit32(biner((pembaca(d) + pembaca(temp1)) & 0xFFFFFFFF));
            d = c;
            c = b;
            b = a;
            a = bit32(biner((pembaca(temp1) + pembaca(temp2)) & 0xFFFFFFFF));
        }
        h[0] = bit32(biner((pembaca(h[0]) + pembaca(a)) & 0xFFFFFFFF));
        h[1] = bit32(biner((pembaca(h[1]) + pembaca(b)) & 0xFFFFFFFF));
        h[2] = bit32(biner((pembaca(h[2]) + pembaca(c)) & 0xFFFFFFFF));
        h[3] = bit32(biner((pembaca(h[3]) + pembaca(d)) & 0xFFFFFFFF));
        h[4] = bit32(biner((pembaca(h[4]) + pembaca(e)) & 0xFFFFFFFF));
        h[5] = bit32(biner((pembaca(h[5]) + pembaca(f)) & 0xFFFFFFFF));
        h[6] = bit32(biner((pembaca(h[6]) + pembaca(g)) & 0xFFFFFFFF));
        h[7] = bit32(biner((pembaca(h[7]) + pembaca(hh)) & 0xFFFFFFFF));
        string hasilAkhir = pembacahs();
        x = hasilAkhir;
    }
    string pembacahs() {
        const char* hex = "0123456789abcdef";
        string result;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) { 
                ut byte = 0;
                for (int k = 0; k < 8; k++) {
                    byte = (byte << 1) | (h[i][j*8 + k] == '1');
                }
                result += hex[byte >> 4];
                result += hex[byte & 0x0F];
            }
        }
        return result;
    }
};

bahanInvestasi murid;
investasi Anak;
pinjaman anak;
Akun user;
sha256 algo;
bool lagi = true;
int N = 1;

struct riwayat {
    struct waktu {
        int jam;
        int menit;
        int detik;
    };
    struct tanggal {
        int hari;
        int bulan;
        int tahun;
    };
    waktu time;
    tanggal tgl;
    string tipe; 
    bool status;
    string tujuan;
    int jumlah;
    string idt;
};
vector<riwayat>Riwayat;

void riwayat_investasi();
void buy_and_sell(int i);
void cekPI();
void detail_transaksi(const vector<riwayat>& x,int i); 
void output(string x);
void delay();
string np(string x);
string rupiah(string x);
void profil95();
void akun1();
void bikin_akun2();
void vitur();
void tarik_tunai4();
void transfer3();
void riwayat6(const vector<riwayat> &x);
void pembelian7();
void pinjaman8();
void investasi9();
string salt() { 
    string acak;
    string bahan = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890):"; 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,63);
    for(int i = 0; i < 16; i++) {
        int n = dist(gen);
        acak += bahan[n];
    }
    return acak;
}

string acak = salt();

int main() { 
    output("=====================================================");
    output("                        SPIE                         ");
    output("       Sistem Perbankan & Investasi ter-Enskripsi    ");
    output("                  By Irfan Putra S.                  ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Sistem terenskripsi aktif");
    output("[ INFO ] Koneksi aktif terverifikasi");
    cout <<"\n";
    output("-----------------------------------------------------");
    output("Silakan pilih metode akses:\n\n[1] Masuk ke Akun (Login)\n[2] Daftar Akun Baru (Register)\n[0] kembali\n");
    output("-----------------------------------------------------");
    string n;
    bool c;
    c = true;
    while(c) {
        cout << ">Pilihan Anda [0-2]: _";
        cin >> n;
        this_thread::sleep_for(chrono::milliseconds(500));
        if(n == "1") {
            akun1();
            c = false;
        }
        else if(n == "2") {
            bikin_akun2();
            c = false;
        }
        else if(n == "0") break;
        else {
            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
        }
    }
    return 0;
}

void delay() {
    for(int i = 0; i < 4; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

string np(string x) {
    if(x.size() != 6) return "2";
    bool y = true;
    for(int i = 0; i < 6; i++) {
        if(((int)x[i] >= (int)('0')) and ((int)x[i] <= (int)('9'))) continue;
        else y = false;
    }
    if(!y) return "1";
    return "3";
}

void output(string x) {
    cout << x << endl;
    this_thread::sleep_for(chrono::milliseconds(250));
    cout << flush;
}
void bikin_akun2() {
    output("\n=====================================================");
    output("               SPIE ACCOUNT REGISTRATION             ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure Channel : aktif");
    output("[ INFO ] Semua data akan dienkripsi");
    output("\n-----------------------------------------------------");
    output("Silahkan masukan data data berikut : ");
    string a,b,x,d,e; 
    cout << "\n[1/5] Masukan nama lengkap: ";
    cin.ignore();
    getline(cin,a);
    cout << "\n[2/5] Masukan nomor telepon : ";
    cin >> b;
    b = b + acak;
    b = algo.has(b);
    cout << "\n[3/5] Masukan username : ";
    cin >> x;
    cout << ">Melihat ketersediaan username";
    delay();
    cout << endl;
    output("[✓] Username tersedia");
    cout << "\n[4/5] Masukan password : ";
    cin >> d;
    d = acak + d;
    d = algo.has(d);
    int n = 11; 
    int jeda = 2;
    string verifikasi;
    while(n--) {
        cout << "\n[4/5] Verifikasi password : ";
        cin >> verifikasi;
        verifikasi = acak + verifikasi;
        verifikasi = algo.has(verifikasi);
        cout << "Verifikasi Password";
        delay();
        if(verifikasi == d) {
            output("\n[✓] verifikasi password berhasil");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] password anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali password anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] password anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali password anda ! ");
                cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    cout << "\n[5/5] Masukan nomor pin (6 angka) : ";
    cin >> e;
    while(true) {
        if(np(e) == "1") {
            output("[!] Tolong Hanya memasukan angka saja");
        }
        else if(np(e) == "2") {
            output("[!] Tolong masukan harus terdiri dari 6 angka saja");
        }
        else break;
        cout << "\n[5/5] Masukan nomor pin (6 angka) : ";
        cin >> e;
    }
    e = e + acak;
    e = algo.has(e);
    n = 11; 
    jeda = 2;
    verifikasi = "";
    while(n--) {
        cout << "\n[5/5] Verifikasi nomor pin : ";
        cin >> verifikasi;
        verifikasi = verifikasi + acak;
        verifikasi = algo.has(verifikasi);
        cout << "Verifikasi nomor pin";
        delay();
        if(verifikasi == e) {
            output("\n[✓] verifikasi nomor pin berhasil");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor pin anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor pin anda ! ");
                cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    output("\n[✓] selamat anda berhasil atas pengisian 5 data");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1000000,9999999);
    int m = dis(gen);
    cout << "berikut adalah nomor rekening anda : ";
    cout << m << endl;
    output("[!] Tolong jangan dibagikan secara sembarangan !");
    string nr = to_string(m);
    cout << "\nPercobaan pengamanan data";
    delay();
    cout << "\n>Mengenkripsi seluruh data";
    delay();
    cout << "\n>Mengirimkan data ke Database";
    delay();
    cout << "\n[✓] Data berhasil di enskripsi dan dikirim ke data base";
    user.awal(a,b,x,d,e,nr);
    cout << "Kami sangat berterima kasih atas kerja sama anda dalam pengisian data ini\n";
    cout << ">mengalihkan ke bagian menu utama dari kami";
    delay();
    vitur();
}

void akun1() {
    output("\n=====================================================");
    output("                 SPIE AUTHENCITAION                   ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure channel : active");
    output("[ INFO ] Data akan di enskripsi end-to-end");
    output("\n-----------------------------------------------------");
    output("Silahkan Untuk login akun anda : ");
    string x;
    int jeda = 2;
    int n = 11;
    while(n--) {
        cout << "\n[1/5] Masukan username : ";
        cin >> x;
        cout << "Mengecek username";
        delay();
        if(user.cekUS(x)) {
            output("\n[✓] username ada");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] username anda tidak ada ! ");
                output("[!] Tolong masukan kembali Username anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] username anda tidak ada ! ");
                output("[!] Tolong masukan kembali username anda ! ");
                cout << "[!!] Penloginan Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    jeda = 2;
    n = 11;
    while(n--) {
        cout << "\n[2/5] Masukan nomor rekening : ";
        cin >> x;
        cout << "Mengecek nomor rekening";
        delay();
        if(user.cekNR(x)) {
            output("\n[✓] nomor rekening anda sesuai");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] nomor rekening anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor rekening anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] nomor rekening anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor rekeing anda ! ");
                cout << "[!!] Penloginan Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    jeda = 2;
    n = 11;
    while(n--) {
        cout << "\n[3/5] Masukan nomor telepon : ";
        cin >> x;
        x = x + acak;
        x = algo.has(x);
        cout << "Mengecek nomor telepon";
        delay();
        if(user.cekNT(x)) {
            output("\n[✓] nomor telepon sesuai ");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] nomor telepon anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor telepon anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] nomor telepon anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali nomor telepon anda ! ");
                cout << "[!!] Penloginan Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    jeda = 2;
    n = 11;
    while(n--) {
        cout << "\n[4/5] Masukan password : ";
        cin >> x;
        x = acak + x;
        x = algo.has(x);
        cout << "Mengecek password";
        delay();
        if(user.cekPAS(x)) {
            output("\n[✓] password sesuai ");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] password anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali password anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] passsword anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali password anda ! ");
                cout << "[!!] Penloginan Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    jeda = 2;
    n = 11;
    while(n--) {
        cout << "\n[5/5] Masukan nomor pin : ";
        cin >> x;
        x = x + acak;
        x = algo.has(x);
        cout << "Mengecek nomor pin";
        delay();
        if(user.cekNP(x)) {
            output("\n[✓] nomor pin sesuai ");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");
                cout << "[!!] Penloginan Akun dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                main();
            }
        }
    }
    cout << "\n> Mengecek kembali seluruh data";
    delay();
    output("\n[✓] Akun ada di database\nTerimakasih atas kerjasama nya");
    cout << "> mengalihkan ke bagian menu utama dari kami";
    delay();
    vitur();
}

void vitur() {
    output("\n\n=====================================================");
    output("                    DASHBOARD SPIE                    ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Sistem terenskripsi aktif");
    output("[ INFO ] Koneksi aktif terverifikasi");
    cout << endl;
    output("-----------------------------------------------------");
    if(lagi) cout << "Selamat datang " << user.tampilkanNL() << endl;
    else cout << "Selamat datang kembali " << user.tampilkanNL() << endl;
    cout << endl;
    cout << "username    : " << user.tampilkanUS() << endl;
    cout << "Dana        : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Status Akun : AKTIF\n" ;
    output("\n-----------------------------------------------------");
    cout << "Menu utama : \n";
    cout << "[1] Cek profil\n[2] Transfer\n[3] Tarik tunai\n[4] Ganti informasi akun\n[5] Lihat riwayat transaksi\n[6] pembelian\n[7] Pinjaman berbunga\n[8] Investasi\n[0] Logout";
    cout << endl;
    output("\n-----------------------------------------------------");
    cout << ">Pilihan anda : ";
    string n;
    bool c;
    c = true;
    lagi = false;
    while(c) {
        cin >> n;
        if(n == "1") { 
            cout << "Mengalihkan ke fitur Cek Profil";
            delay();
            profil95();
            c = false;
        }
        else if(n == "2") {
            cout << "Mengalihkan ke fitur Transfer";
            delay();
            transfer3();
            c = false;
        }
        else if(n == "3") {
            cout << "Mengalihkan ke fitur Tarik tunai";
            delay();
            tarik_tunai4();
            c = false;
        }
        else if(n == "4") { 
            cout << "Mengalihkan ke fitur Ganti informasi akun";
            delay();
            profil95();
            c = false;
        }
        else if(n == "5") {
            cout << "Mengalihkan ke fitur Lihat riwayat transaksi";
            delay();
            riwayat6(Riwayat);
            c = false;
        }
        else if(n == "6") {
            cout << "Mengalihkan ke fitur Pembelian";
            delay();
            pembelian7();
            c = false;
        }
        else if(n == "7") {
            cout << "Mengalihkan ke fitur Pinjaman berbunga";
            delay();
            pinjaman8();
            c = false;
        }
        else if(n == "8") {
            cout << "Mengalihkan ke fitur investasi";
            delay();
            investasi9();
            c = false;
        }
        else if(n == "0") {
            main();
        }
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void transfer3() {
    output("\n=====================================================");
    output("          SPIE MONEY TRANSFER                   ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure Transfer mode : active");
    output("[ INFO ] Semua transaksi terenskripsi");
    output("\n-----------------------------------------------------");
    cout << "Saldo anda : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    output("\n-----------------------------------------------------");
    output("\nLanjutkan : ");
    output("[1] Ya");
    output("[2] tidak");
    output("\n-----------------------------------------------------");
    string input;
    while(true) {
        cout << "Input:_";
        cin >> input;
        if(input == "2") vitur();
        else if(input == "1") break;
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
    output("Masukan data transfer : "); 
    string x;
    int jeda = 2;
    int n = 11;
    while(n--) {
        cout << "\n[1/4] Masukan nomor pin : ";
        cin >> x;
        x = x + acak;
        x = algo.has(x);
        cout << "Mengecek nomor pin";
        delay();
        if(user.cekNP(x)) {
            output("\n[✓] nomor pin sesuai ");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");
                cout << "[!!] Proses transfer dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                vitur();
            }
        }
    }
    string y,z;
    cout << "[2/4] Masukan nama lengkap tujuan : ";
    cin.ignore();
    getline(cin,x);
    cout << "[3/4] Masukan no.rekening tujuan : ";
    cin >> y; 
    bool c = true;
    while(c) {
        cout << "[4/4] Masukan Jumlah : ";
        cin >> z;
        if(stoi(z) <= 0) {
            output("[!] Jumlah harus lebih dari nol");
        }
        else if(stoi(z) > user.tampilkanDANA()) {
            output("[!] Jumlah tidak boleh melebihi Dana anda");
        }
        else c = false;
    }
    cout << "Tunggu sebentar";
    delay();
    output("\n=====================================================");
    output("                 KONFIRMASI TRANSFER                 ");
    output("=====================================================");
    cout << endl;
    cout << "Tujuan : " <<  x << endl;
    cout << "nomor rekening tujuan : " << y << endl;
    cout << "Jumlah : " << rupiah(z) << endl << endl;
    output("-----------------------------------------------------");
    output("Pastikan data sudah benar");
    output("[1] Konfirmasi transfer\n[2] batal");
    cout << endl;
    while(true) {
        cout << "input :_ ";
        cin >> y;
        if(y == "1") {
            cout << "\nMemproses transaksi";
            delay();
            cout << "\n> Mengenkripsi data";
            delay();
            cout << "\n> Menghubungkan ke server";
            delay();
            cout << "\n> Mengirim dana";
            delay();
            cout <<"\n[✓] Transfer berhasil";
            user.ubahDANA(user.tampilkanDANA() - stoi(z));
            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
            time_t sekarang = time(0);
            tm *waktu = localtime(&sekarang);
            int tahun  = 1900 + waktu->tm_year;
            int bulan  = 1 + waktu->tm_mon;
            int hari   = waktu->tm_mday;
            int jam    = waktu->tm_hour;
            int menit  = waktu->tm_min;
            int detik  = waktu->tm_sec;
            Riwayat.push_back({
                {jam,menit,detik},
                {hari,bulan,detik},
                "Transfer",
                true,
                x,
                stoi(z),
                "0x000000" + to_string(N)
            });
            N++;
            vitur();
        }
        else if(y == "2") transfer3();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }

}

void riwayat6(const vector<riwayat>& x) { 
    output("\n\n=====================================================");
    output("               SPIE TRANSACTION HISTORY              ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Data Integrity : VERIFIED");
    output("[ INFO ] Riwayat terenkripsi & aman");
    output("\n-----------------------------------------------------");
    output("Filter : ");
    output("[1] Semua transaksi");
    output("[2] Pembelian"); // publik
    output("[3] Tarik tunai");
    output("[4] Transfer");
    output("[5] Pinjaman berbunga");
    output("[6] Investasi");
    output("[0] kembali");
    cout << endl;
    output("-----------------------------------------------------");
    bool c = true;
    string n;
    while(c) {
        cout << "Pilihan anda [0-5] :_";
        cin >> n;
        if(n == "1") {
            if(x.empty()) {
                output("[!] Anda tidak memiliki riwayat Seluruh transaksi");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("             RIWAYAT SELURUH TRANSAKSI               ");
            output("=====================================================");
            for(int i = 0; i < x.size(); i++) {
                cout << "[" << i  + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                cout << "    " << "ke      : " << x[i].tujuan << endl;
                cout << "    " << "Jumlah  : " <<rupiah(to_string(x[i].jumlah)) << endl;
                cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                output("-----------------------------------------------------");
            }
            cout <<"[0] Kembali | [1-" << x.size() << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= x.size()) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
        }
        else if(n == "2") {
            if(x.empty()) {
                output("[!] Anda tidak memiliki riwayat pembelian");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("                 RIWAYAT PEMBELIAN                   ");
            output("=====================================================");
            int j = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i].tipe == "Pembelian") {
                    cout << "[" << j + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                    cout << "    " << "ke      : " << x[i].tujuan << endl; 
                    cout << "    " << "Jumlah  : " << rupiah(to_string(x[i].jumlah)) << endl;
                    cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                    output("-----------------------------------------------------");
                    j++;
                }
            }
            if(j == 0) {
                output("[!] Tidak ada riwayat pembelian");
                riwayat6(x);
            }
            cout <<"[0] Kembali | [1-" << j + 1 << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= j + 1) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
            cout << endl;
        }
        else if(n == "3") {
            if(x.empty()) {
                output("[!] Anda tidak memiliki riwayat tarik tunai");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("                 RIWAYAT TARIK TUNAI                 ");
            output("=====================================================");
            int j = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i].tipe == "Tarik tunai") {
                    cout << "[" << j  + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                    cout << "    " << "ke      : " << x[i].tujuan << endl;
                    cout << "    " << "Jumlah  : " << rupiah(to_string(x[i].jumlah)) << endl;
                    cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                    output("-----------------------------------------------------");
                    j++;
                }
            }
            if(j == 0) {
                output("[!] Tidak ada riwayat transaksi tarik tunai");
                riwayat6(x);
            }
            cout <<"[0] Kembali | [1-" << j + 1 << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= j + 1) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
            cout << endl;
        }
        else if(n == "4") {
            if(x.empty()) {
                output("[!] Anda tidak memiliki riwayat transfer");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("                  RIWAYAT TRANSFER                   ");
            output("=====================================================");
            int j = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i].tipe == "Transfer") {
                    cout << "[" << j  + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                    cout << "    " << "ke      : " << x[i].tujuan << endl;
                    cout << "    " << "Jumlah  : " << rupiah(to_string(x[i].jumlah)) << endl;
                    cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                    output("-----------------------------------------------------");
                    j++;
                }
            }
            if(j == 0) {
                output("[!] Tidak ada riwayat transaksi transfer");
                riwayat6(x);
            }
            cout <<"[0] Kembali | [1-" << j + 1 << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= j + 1) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
            cout << endl;
        }
        else if(n == "5") {
            if(x.empty()) {
                output("Anda tidak memiliki riwayat Pinjaman berbunga");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("              RIWAYAT PINJAMAN BERBUNGA              ");
            output("=====================================================");
            int j = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i].tipe == "Pinjaman Berbunga") {
                    cout << "[" << j  + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                    cout << "    " << "ke      : " << x[i].tujuan << endl;
                    cout << "    " << "Jumlah  : " << rupiah(to_string(x[i].jumlah)) << endl;
                    cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                    output("-----------------------------------------------------");
                    j++;
                }
            }
            if(j == 0) {
                output("[!] Tidak ada riwayat transaksi Pinjaman Berbunga");
                riwayat6(x);
            }
            cout <<"[0] Kembali | [1-" << j + 1 << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= j + 1) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
            cout << endl;
        }
        else if(n == "6") {
            if(x.empty()) {
                output("Anda tidak memiliki riwayat Pinjaman berbunga");
                riwayat6(x);
            }
            output("\n=====================================================");
            output("                 RIWAYAT INVESTASI                   ");
            output("=====================================================");
            int j = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i].tipe == "Investasi") {
                    cout << "[" << j  + 1 << "] " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << " | " << x[i].tipe << endl;
                    cout << "    " << "ke      : " << x[i].tujuan << endl;
                    cout << "    " << "Jumlah  : " << rupiah(to_string(x[i].jumlah)) << endl;
                    cout << "    " << "Status  : " << "Berhasil" << endl << endl;
                    output("-----------------------------------------------------");
                    j++;
                }
            }
            if(j == 0) {
                output("[!] Tidak ada riwayat transaksi Investasi");
                riwayat6(x);
            }
            cout <<"[0] Kembali | [1-" << j + 1 << "]\n";
            cout << endl;
            bool q = true;
            string p;
            while(q) {
                cout << "input :_";
                cin >> p;
                if(p == "0") riwayat6(x);
                else if(stoi(p)  >= 1 && stoi(p) <= j + 1) {
                    detail_transaksi(x,stoi(p) - 1);
                }
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
            cout << endl;
        }
        else if(n == "0") vitur();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
    vitur();
}

void detail_transaksi(const vector<riwayat>& x,int i) { // layer ke 7
    output("\n=====================================================");
    output("                   DETAIL TRANSAKSI                  ");
    output("=====================================================");
    cout << endl;
    cout << "Tanggal      : " << x[i].tgl.hari << "-" << x[i].tgl.bulan << "-" << 2026 << endl;
    cout << "Waktu        : " << x[i].time.jam << ":" << x[i].time.menit << ":" << x[i].time.detik << endl;
    cout << "Tipe         : " << x[i].tipe << endl;
    cout << "tujuan       : " << x[i].tujuan << endl; 
    cout << "Jumlah       : " << rupiah(to_string(x[i].jumlah)) << endl; 
    cout << "id transaksi : " << x[i].idt << endl;
    cout << "status       : Berhasil" << endl << endl;
    output("-----------------------------------------------------");
    output("[✓] Data terenkripsi\n[✓] Transaksi tervalidasi\n");
    output("-----------------------------------------------------");
    cout << "[0] Kembali\n";
    string n;
    bool c = true;
    while(c) {
        cout << "input :_";
        cin >> n;
        if(n == "0") riwayat6(x);
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void tarik_tunai4() {
    output("\n=====================================================");
    output("                SPIE CASH WITHDRAWAL                 ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure Withdrawal mode : active");
    output("[ INFO ] Semua transaksi terenskripsi");
    output("\n-----------------------------------------------------");
    cout << "Saldo anda : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    output("\n-----------------------------------------------------");
    output("\nLanjutkan : ");
    output("[1] Ya");
    output("[2] tidak");
    output("\n-----------------------------------------------------");
    string input;
    while(true) {
        cout << "Input:_";
        cin >> input;
        if(input == "2") vitur();
        else if(input == "1") break;
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
    output("Masukan data transaksi: "); 
    string x;
    int jeda = 2;
    int n = 11;
    while(n--) {
        cout << "\n[1/3] Masukan nomor pin : ";
        cin >> x;
        x = x + acak;
        x = algo.has(x);
        cout << "Mengecek nomor pin";
        delay();
        if(user.cekNP(x)) {
            output("\n[✓] nomor pin sesuai ");
            break;
        }
        else {
            if(7 < n) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");

            }
            else if(0 < n < 8) {
                output("\n[!] Nomor pin anda tidak sesuai ! ");
                output("[!] Tolong masukan kembali Nomor pin anda ! ");
                cout << "[!!] Proses tarik tunai dikunci selama " << jeda << " detik !\n\n";
                this_thread::sleep_for(chrono::seconds(jeda));
                jeda = 2 * jeda;
            }
            else {
                cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                vitur();
            }
        }
    }
    string y,z;
    cout << "[2/3] Masukan no.rekening: ";
    cin >> y; 
    bool c = true;
    while(c) {
        cout << "[3/3] Masukan Jumlah : ";
        cin >> z;
        if(stoi(z) <= 0) {
            output("[!] Jumlah harus lebih dari nol");
        }
        else if(stoi(z) > user.tampilkanDANA()) {
            output("[!] Jumlah tidak boleh melebihi Dana anda");
        }
        else c = false;
    }
    cout << "Tunggu sebentar";
    delay();
    output("\n=====================================================");
    output("                 KONFIRMASI PENARIKAN                ");
    output("=====================================================");
    cout << endl;
    cout << "nomor rekening tujuan : " << y << endl;
    cout << "Jumlah : " << rupiah(z) << endl << endl;
    output("-----------------------------------------------------");
    output("Pastikan data sudah benar");
    output("[1] Konfirmasi penarikan\n[2] batal");
    cout << endl;
    while(true) {
        cout << "input :_ ";
        cin >> x;
        if(x == "1") {
            cout << "\nMemproses transaksi";
            delay();
            cout << "\n> Mengenkripsi data";
            delay();
            cout << "\n> Menghubungkan ke server";
            delay();
            cout << "\n> Mengirim dana";
            delay();
            cout <<"\n[✓] Penarikan berhasil";
            user.ubahDANA(user.tampilkanDANA() - stoi(z));
            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
            time_t sekarang = time(0);
            tm *waktu = localtime(&sekarang);
            int tahun  = 1900 + waktu->tm_year;
            int bulan  = 1 + waktu->tm_mon;
            int hari   = waktu->tm_mday;
            int jam    = waktu->tm_hour;
            int menit  = waktu->tm_min;
            int detik  = waktu->tm_sec;
            Riwayat.push_back({
                {jam,menit,detik},
                {hari,bulan,detik},
                "Tarik tunai",
                true,
                "Diri sendiri",
                stoi(z),
                "0x000000" + to_string(N)
            });
            N++;
            vitur();
        }
        else if(x == "2") tarik_tunai4();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void pembelian7() {
    output("\n=====================================================");
    output("                SPIE PURCHASE CENTER                 ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure Purchase Mode : active ");
    output("[ INFO ] Semua transaksi akan dilindungi sistem");
    output("\n-----------------------------------------------------");
    cout << "Saldo anda : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    output("\n-----------------------------------------------------");
    output("Pilih kategori pembelian : ");
    output("[1] Pulsa dan paket data");
    output("[2] Token listrik dan utilitas (PLN/PDAM)");
    output("[3] E-Vouncher belanja dan Hiburan");
    output("[0] kembali");
    cout << endl;
    output("-----------------------------------------------------");
    bool c = true;
    string n;
    while(c) {
        cout << "Pilihan anda [0-3] :_";
        cin >> n;
        if(n == "1") { 
            string a,b,c;
            output("\n=====================================================");
            output("                PULSA DAN PAKET DATA                 ");
            output("=====================================================");
            cout << "Silahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Proses pembelian dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            vitur();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            cout << "[3/3] Nomor telepon : ";
            cin >> c;
            cout << "Terimakasih atas kerja samanya" << endl;
            output("\n-----------------------------------------------------");
            output("Pilih Produk Telko:");
            output("[1] Pulsa Rp 25.000          | Rp 25.000");
            output("[2] Pulsa Rp 50.000          | Rp 50.000");
            output("[3] Pulsa Rp 100.000         | Rp 100.000");
            output("[4] Paket Data 15GB (30 Hari)| Rp 65.000");
            output("[0] Kembali");
            output("\n-----------------------------------------------------");
            string x;
            bool y = true;
            while(y) {
                cout << "input :_ ";
                cin >> x;
                if(x == "1") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 25000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN               ");
                    output("=====================================================");
                    cout << endl; // no.telepon,total bayar dan pilihan
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Pulsa Rp.25.000,00" << endl;
                    cout << "Total biaya : Rp.25.000,00 \n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 25000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "Pulsa dan paket kuota",
                                25000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "2") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 50000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN               ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Pulsa Rp.50.000,00" << endl;
                    cout << "Total biaya : Rp.50.000,00 \n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 50000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "Pulsa dan paket kuota",
                                50000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "3") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 100000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN                ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Pulsa Rp.100.000,00" << endl;
                    cout << "Total biaya : Rp.100.000,00 \n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 100000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "Pulsa dan paket kuota",
                                100000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "4") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 65000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN                ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Pulsa Rp.65.000,00" << endl;
                    cout << "Total biaya : Rp.65.000,00\n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 65000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "Pulsa dan paket kuota",
                                65000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                    vitur();
                }
                else if(x == "0") pembelian7();
                else {
                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                }
            }
        }
        else if(n == "3") { 
            string a,b,c;
            output("\n=====================================================");
            output("        SPIE E-VOUNCHER BELANJA DAN HIBURAN          ");
            output("=====================================================");
            cout << "Silahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Proses pembelian dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            cout << "[3/3] Nomor telepon : ";
            cin >> c;
            cout << "Terimakasih atas kerja samanya" << endl;
            output("\n-----------------------------------------------------");
            output("Pilih E-Voucher yang ingin dibeli:");
            output("[1] Spotify Premium (1 Bulan)  | Rp  55.000");
            output("[2] Google Play Voucher R50k   | Rp  50.000");
            output("[3] Voucher Tokopedia Rp 100k  | Rp 100.000");
            output("[0] Kembali");
            output("\n-----------------------------------------------------");
            string x;
            bool y = true;
            while(y) {
                cout << "input :_ ";
                cin >> x;
                if(x == "1") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 55000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN                ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Spotify Premium (1 Bulan)  Rp.55.000,00" << endl;
                    cout << "Total biaya : Rp.55.000,00 \n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 55000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "E-voucher dan hiburan",
                                55000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "2") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 50000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN               ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Google Play Voucher Rp.50.000,00" << endl;
                    cout << "Total biaya : Rp.50.000,00\n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 50000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "E-voucher dan hiburan",
                                50000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "3") {
                    cout << "Tunggu sebentar";
                    delay();
                    if(user.tampilkanDANA() < 100000) {
                        cout << "[!] Saldo anda kurang ";
                        pembelian7();
                    }
                    output("\n=====================================================");
                    output("                 KONFIRMASI PEMBELIAN                ");
                    output("=====================================================");
                    cout << endl; 
                    cout << "Nomor telepon : " << c << endl;
                    cout << "pilihan : Voucher Tokopedia Rp.100.000,00" << endl;
                    cout << "Total biaya : Rp.100.000,00 \n" << endl;
                    output("\n-----------------------------------------------------");
                    output("Pastikan data sudah benar");
                    output("[1] Konfirmasi transfer\n[0] batal");
                    string apaya;
                    while(true) {
                        cout << "input :_";
                        cin >> apaya;
                        if(apaya == "1") {
                            cout << "\nMemproses transaksi pembelian";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Transfer berhasil";
                            user.ubahDANA(user.tampilkanDANA() - 100000);
                            cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pembelian",
                                true,
                                "E-voucher dan hiburan",
                                100000,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            vitur();
                        }
                        else if(apaya == "0") pembelian7();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "0") pembelian7();
                else {
                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                }
            }
        }
        else if(n == "2") {
            string a,b;
            output("\n=====================================================");
            output("       SPIE TOKEN LISTRIK & UTILITAS (PLN/PDAM)      ");
            output("=====================================================");
            cout << "Silahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/2] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/2] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Proses pembelian dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/2] Masukan nomor pin : ";
                cin >> b;
            }
            cout << "Terimakasih atas kerja samanya" << endl;
            output("\n-----------------------------------------------------");
            output("Pilihan : \n");
            output("[1] PLN");
            output("[2] PDAM");
            output("[0] kembali");
            output("\n-----------------------------------------------------");
            string x;
            while(true) {
                cout << "Input:_";
                cin >> x;
                if(x == "1") {
                    output("\n=====================================================");
                    output("                        PDAM                          ");
                    output("=====================================================\n");
                    output("1 m³ = 3000");
                    output("\n-----------------------------------------------------");
                    while(true) {
                        string x,y;
                        cout << "Masukan Kebutuhan m³ : ";
                        cin >> x;
                        if(stoi(x) * 3000 > user.tampilkanDANA()) {
                            cout << "Saldo anda kurang" << endl;
                            pembelian7();
                        }
                        cout << "\nTotal anda : " << rupiah(to_string(stoi(x) * 3000));
                        output("\nLanjutkan ?");
                        output("[1] ya");
                        output("[2] tidak");
                        while(true) {
                            cout << "input :";
                            cin >> y;
                            if(y == "1") {
                                cout << "Tunggu sebentar";
                                delay();
                                cout << "\nMemproses transaksi pembelian";
                                delay();
                                cout << "\n> Mengenkripsi data";
                                delay();
                                cout << "\n> Meverifikasi saldo";
                                delay();
                                cout << "\n> Menyimpan transaksi";
                                delay();
                                cout <<"\n[✓] Transaksi berhasil";
                                user.ubahDANA(user.tampilkanDANA() -  stoi(x) * 3000);
                                cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                time_t sekarang = time(0);
                                tm *waktu = localtime(&sekarang);
                                int tahun  = 1900 + waktu->tm_year;
                                int bulan  = 1 + waktu->tm_mon;
                                int hari   = waktu->tm_mday;
                                int jam    = waktu->tm_hour;
                                int menit  = waktu->tm_min;
                                int detik  = waktu->tm_sec;
                                Riwayat.push_back({
                                    {jam,menit,detik},
                                    {hari,bulan,detik},
                                    "Pembelian",
                                    true,
                                    "Token listrik dan utilitas",
                                    stoi(x) * 3000,
                                    "0x000000" + to_string(N)
                                });
                                N++;
                                vitur();
                            }
                            else if(y == "2") pembelian7();
                            else {
                                cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                            }
                        }
                    }
                }
                else if(x == "2") {
                    output("\n=====================================================");
                    output("                        PLN                          ");
                    output("=====================================================\n");
                    output("1 kWh = 2000");
                    output("\n-----------------------------------------------------");
                    while(true) {
                        string x;
                        cout << "Masukan Kebutuhan kWh : ";
                        cin >> x;
                        if(stoi(x) * 2000 > user.tampilkanDANA()) {
                            cout << "Saldo anda kurang" << endl;
                            pembelian7();
                        }
                        cout << "\nTotal anda : " << rupiah(to_string(stoi(x) * 2000));
                        output("\nLanjutkan ?");
                        output("[1] ya");
                        output("[2] tidak");
                        while(true) {
                            cout << "input :";
                            cin >> x;
                            if(x == "1") {
                                cout << "Tunggu sebentar";
                                delay();
                                cout << "\nMemproses transaksi pembelian";
                                delay();
                                cout << "\n> Mengenkripsi data";
                                delay();
                                cout << "\n> Meverifikasi saldo";
                                delay();
                                cout << "\n> Menyimpan transaksi";
                                delay();
                                cout <<"\n[✓] Transaksi berhasil";
                                user.ubahDANA(user.tampilkanDANA() - stoi(x) * 2000);
                                cout << "\nSisa saldo : " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                time_t sekarang = time(0);
                                tm *waktu = localtime(&sekarang);
                                int tahun  = 1900 + waktu->tm_year;
                                int bulan  = 1 + waktu->tm_mon;
                                int hari   = waktu->tm_mday;
                                int jam    = waktu->tm_hour;
                                int menit  = waktu->tm_min;
                                int detik  = waktu->tm_sec;
                                Riwayat.push_back({
                                    {jam,menit,detik},
                                    {hari,bulan,detik},
                                    "Pembelian",
                                    true,
                                    "Token listrik dan utilitas",
                                    stoi(x) * 2000,
                                    "0x000000" + to_string(N)
                                });
                                N++;
                                vitur();
                            }
                            else if(x == "0") pembelian7();
                            else {
                                cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                            }
                        }
                    }
                }
                else if(x == "0") pembelian7();
                else {
                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                }
            }
        }
        else if(n == "0") vitur();
        else {
            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
        }
    }
}

void profil95() {
    output("\n=====================================================");
    output("                 SPIE ACCOUNT SETTINGS                 ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure settings mode : active");
    output("[ INFO ] Perubahan data akan diverifikasi");
    output("\n-----------------------------------------------------");
    output("informasi akun: ");
    cout << endl;
    cout << "nama lengkap  : " << user.tampilkanNL() << endl;
    cout << "Username      : " << user.tampilkanUS() << endl;
    cout << "Dana          : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "No.telepon    : *******" << endl;
    cout << "Password      : *******" << endl ;
    cout << "No.Pin        : *******" <<endl;
    cout << "No.rekening   : *******\n\n";
    output("-----------------------------------------------------");
    cout << "pilih yang ingin diubah : \n\n";
    output("[1] nama lengkap");
    output("[2] username"); 
    output("[3] No.telepon");
    output("[4] password");
    output("[5] No.pin");
    output("[0] kembali");
    cout << endl;
    output("-----------------------------------------------------");
    string n;
    bool c;
    c = true;
    while(c) {
        cout << ">Pilihan Anda [0-5]: _";
        cin >> n;
        this_thread::sleep_for(chrono::milliseconds(500));
        if(n == "1") {
            int jeda = 2;
            string x;
            int m = 11;
            while(m--) {
                cout << "Masukan Nama lengkap lama anda untuk verifikasi : ";
                cin.ignore();
                getline(cin,x);
                cout << "Mengverifikasi";
                delay();
                if(user.cekNL(x)) {
                    output("\n[✓] Nama lengkap lama sesuai ");
                    cout << "\nMasukan nama Lengkap baru anda : ";
                    cin >> x;
                    user.ubahNL(x);
                    cout << "\nMemproses Perubahan nama lengkap";
                    delay();
                    cout << "\n> Mengenkripsi nama lengkap baru";
                    delay();
                    cout << "\n> Memperbarui sistem keamanan";
                    delay();
                    cout << "\n> Menyimpan segala perubahan";
                    delay();
                    output("\n[✓] Nama lengkap baru berhasil diperbarui");
                    break;
                }
                else {
                    if(7 < m) {
                        output("\n[!] Nama lengkap lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nama lengkap lama anda ! ");

                    }
                    else if(0 < m < 8) {
                        output("\n[!] Nama lengkap lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nama lengkap lama anda ! ");
                        cout << "[!!] Proses ganti nama lengkap akun dikunci selama " << jeda << " detik !\n\n";
                        this_thread::sleep_for(chrono::seconds(jeda));
                        jeda = 2 * jeda;
                    }
                    else {
                        cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                        main();
                    }
                }
            }
            c = false;
            profil95();
        }
        else if(n == "2") {
            cout << "Username lama : " << user.tampilkanUS() << endl;
            cout << "Username baru : ";
            string x;
            cin >> x;
            user.ubahUS(x);
            cout << ">Melihat ketersediaan username";
            delay();
            cout << endl;
            output("[✓] Username tersedia");
            cout << "\nMemproses Perubahan Username";
            delay();
            cout << "\n> Mengenkripsi username baru";
            delay();
            cout << "\n> Memperbarui sistem keamanan";
            delay();
            cout << "\n> Menyimpan segala perubahan";
            delay();
            output("\n[✓] Username berhasil diperbarui\n");
            c = false;
            profil95();
        }
        else if(n == "3") {
            int jeda = 2;
            string x;
            int m = 11;
            while(m--) {
                cout << "Masukan nomor telepon lama anda untuk verifikasi : ";
                cin >> x;
                x = x + acak;
                x = algo.has(x);
                cout << "Mengverifikasi";
                delay();
                if(user.cekNT(x)) {
                    output("\n[✓] Nomor telepon lama sesuai ");
                    cout << "\nMasukan  Nomor telepon baru anda : ";
                    cin >> x;
                    user.ubahNT(x);
                    cout << "\nMemproses Perubahan Nomor telepon";
                    delay();
                    cout << "\n> Mengenkripsi Nomor telepon baru";
                    delay();
                    cout << "\n> Memperbarui sistem keamanan";
                    delay();
                    cout << "\n> Menyimpan segala perubahan";
                    delay();
                    output("\n[✓] nomor telepon berhasil diperbarui");
                    break;
                }
                else {
                    if(7 < m) {
                        output("\n[!] Nomor telepon lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nomor telepon lama anda ! ");

                    }
                    else if(0 < m < 8) {
                        output("\n[!] Nomor telepon lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nomor telepon lama anda ! ");
                        cout << "[!!] Proses ganti nomor telepon akun dikunci selama " << jeda << " detik !\n\n";
                        this_thread::sleep_for(chrono::seconds(jeda));
                        jeda = 2 * jeda;
                    }
                    else {
                        cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                        main();
                    }
                }
            }
            c = false;
            profil95();
        }
        else if(n == "4") {
            int jeda = 2;
            string x;
            int m = 11;
            while(m--) {
                cout << "Masukan password lama anda untuk verifikasi : ";
                cin >> x;
                cout << "Mengverifikasi";
                delay();
                x = acak + x;
                x = algo.has(x);
                if(user.cekPAS(x)) {
                    output("\n[✓] Password lama sesuai ");
                    cout << "\nMasukan Password baru anda : ";
                    cin >> x;
                    user.ubahPAS(x);
                    cout << "\nMemproses Perubahan Password";
                    delay();
                    cout << "\n> Mengenkripsi Password baru";
                    delay();
                    cout << "\n> Memperbarui sistem keamanan";
                    delay();
                    cout << "\n> Menyimpan segala perubahan";
                    delay();
                    output("\n[✓] Password berhasil diperbarui");
                    break;
                }
                else {
                    if(7 < m) {
                        output("\n[!] Password lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Password lama anda ! ");

                    }
                    else if(0 < m < 8) {
                        output("\n[!] Password lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Pasword lama anda ! ");
                        cout << "[!!] Proses ganti password akun ikunci selama " << jeda << " detik !\n\n";
                        this_thread::sleep_for(chrono::seconds(jeda));
                        jeda = 2 * jeda;
                    }
                    else {
                        cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                        main();
                    }
                }
            }
            c = false;
            vitur();
        }
        else if(n == "5") {
            int jeda = 2;
            string x;
            int m = 11;
            while(m--) {
                cout << "Masukan nomor pin lama anda untuk verifikasi : ";
                cin >> x;
                cout << "Mengverifikasi";
                delay();
                x = x + acak;
                x = algo.has(x);
                if(user.cekNP(x)) {
                    output("\n[✓] Nomor pin lama sesuai ");
                    cout << "\nMasukan Nomor pin baru anda : ";
                    cin >> x;
                    user.ubahNP(x);
                    cout << "\nMemproses Perubahan Nomor pin";
                    delay();
                    cout << "\n> Mengenkripsi Nomor pin baru";
                    delay();
                    cout << "\n> Memperbarui sistem keamanan";
                    delay();
                    cout << "\n> Menyimpan segala perubahan";
                    delay();
                    output("\n[✓] Nomor pin berhasil diperbarui");
                    break;
                }
                else {
                    if(7 < m) {
                        output("\n[!] Nomor pin lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nomor pin anda ! ");

                    }
                    else if(0 < m < 8) {
                        output("\n[!] Nomor pin lama anda tidak sesuai ! ");
                        output("[!] Tolong masukan kembali Nomor pin lama anda ! ");
                        cout << "[!!] Proses ganti nomor pin akun dikunci selama " << jeda << " detik !\n\n";
                        this_thread::sleep_for(chrono::seconds(jeda));
                        jeda = 2 * jeda;
                    }
                    else {
                        cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                        main();
                    }
                }
            }
            c = false;
            profil95();
        }
        else if(n == "0") vitur();
        else {
            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
        }
    }
}

void pinjaman8() {
    output("\n=====================================================");
    output("                 SPIE PINJAMAN                  ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure channel : active");
    output("[ INFO ] Data akan di enskripsi end-to-end");
    output("\n-----------------------------------------------------");
    output("Status Anda :\n");
    cout << "Saldo anda : " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Total Pinjaman anda : " << anak.total() << endl;
    output("\n--------------------------------------------------");
    output("Menu:\n");
    output("[1] Ajukan Pinjaman"); 
    output("[2] Lihat Pinjaman Aktif"); 
    output("[3] Bayar Cicilan"); 
    output("[0] Kembali\n");
    output("--------------------------------------------------");
    string x;
    while(true) {
        cout <<"Input:_";
        cin >> x;
        if(x == "1") {
            output("\n=====================================================");
            output("                   AJUKAN PINJAMAN                   ");
            output("=====================================================");
            output("Pilih Bank : ");
            output("[1] Bank ihsan"); 
            output("[2] BCA"); 
            output("[3] BRI");
            output("[4] Bank euy");
            output("[5] Bank meser");
            output("[0] Kembali\n");
            output("--------------------------------------------------");
            while(true) {
                double a,b;
                string a1,a2;
                cout << "Input:_";
                cin >> x;
                if(x == "1") {
                    output("\n\n=====================================================");
                    output("                     BANK IHSAN                      ");
                    output("=====================================================");
                    output("Informasi : \n");
                    output("1.Maksimal Harga pinjaman adalah RP.100.000.000,00 (100 juta rupiah)");
                    output("2.Maksiman Waktu pinjaman adalah 36 bulan (3 tahun)");
                    output("3.Bunga anda adalah 6% dari pinjaman anda \n");
                    output("--------------------------------------------------\n");
                    output("[1] Ajukan pinjaman");
                    output("[0] Kembali\n");
                    output("--------------------------------------------------");
                    while(true) {
                        cout << "Input:_";
                        cin >> x;
                        if(x == "1") {
                            cout << "Silahkan untuk memasukan data Pinjaman: " << endl;
                            cout << "[1/4] Masukan nomor rekening : ";
                            cin >> a1;
                            if(user.cekNR(a1)) {
                                int jeda = 2;
                                int n = 11;
                                while(n--) {
                                    cout << "\n[2/4] Masukan nomor pin : ";
                                    cin >> a2;
                                    a2 = a2 + acak;
                                    a2 = algo.has(a2);
                                    cout << "Mengecek nomor pin";
                                    delay();
                                    if(user.cekNP(a2)) {
                                        output("\n[✓] nomor pin sesuai ");
                                        break;
                                    }
                                    else {
                                        if(7 < n) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                                        }
                                        else if(0 < n < 8) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                                            this_thread::sleep_for(chrono::seconds(jeda));
                                            jeda = 2 * jeda;
                                        }
                                        else {
                                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                                            main();
                                        }
                                    }
                                }
                            }
                            else {
                                cout << "[2/4] Masukan nomor pin : ";
                                cin >> a2;
                            }
                            cout << "[3/4] Masukan Harga Pinjaman : ";
                            cin >> a;
                            if(a > 100000000) {
                                output("Lebih dari maksimal pinjaman");
                                pinjaman8();
                            }
                            cout << "[4/4] Masukan berapa bulan pinjaman : ";
                            cin >> b;
                            if(b > 36) {
                                output("Lebih dari maksimal waktu pinjaman");
                                pinjaman8();
                            }
                            cout << "Memproses";
                            delay();
                            output("\n=====================================================");
                            output("                 KONFIRMASI PINJAMAN                ");
                            output("=====================================================");
                            cout << endl; 
                            cout << "Nomor Rekening : " << a1 << endl;
                            cout << "Jumlah Pinjaman : " << fixed << setprecision(2) << a << endl;
                            double bunga = a * 0.06;
                            cout << "Bunga : " << fixed << setprecision(2) << bunga << endl;
                            cout << "Waktu pinjaman : " << b << endl;
                            output("\n-----------------------------------------------------");
                            output("Pastikan data sudah benar");
                            output("[1] Konfirmasi pinjaman\n[2] batal");
                            string apaya;
                            while(true) {
                                cout << "Input:_";
                                cin >> apaya;
                                if(apaya == "1") {
                                    cout << "\nMemproses transaksi Pinjaman";
                                    delay();
                                    cout << "\n> Mengenkripsi data";
                                    delay();
                                    cout << "\n> Meverifikasi saldo";
                                    delay();
                                    cout << "\n> Menyimpan transaksi";
                                    delay();
                                    cout <<"\n[✓] Pinjaman berhasil";
                                    user.ubahDANA(user.tampilkanDANA() + a);
                                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                    time_t sekarang = time(0);
                                    tm *waktu = localtime(&sekarang);
                                    int tahun  = 1900 + waktu->tm_year;
                                    int bulan  = 1 + waktu->tm_mon;
                                    int hari   = waktu->tm_mday;
                                    int jam    = waktu->tm_hour;
                                    int menit  = waktu->tm_min;
                                    int detik  = waktu->tm_sec;
                                    Riwayat.push_back({
                                        {jam,menit,detik},
                                        {hari,bulan,detik},
                                        "Pinjaman Berbunga",
                                        true,
                                        "Bank ihsan",
                                        (int)a,
                                        "0x000000" + to_string(N)
                                    });
                                    N++;
                                    anak.tambah("bank ihsan",a,0.06,b);
                                    anak.tambah1(a);
                                    pinjaman8();
                                }
                                else if(apaya == "2") {
                                    pinjaman8();
                                }
                                else {
                                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                                }
                            }
                        }
                        else if(x == "0") pinjaman8();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "2") {
                    output("\n\n=====================================================");
                    output("                          BCA                       ");
                    output("=====================================================");
                    output("Informasi : \n");
                    output("1.Maksimal Harga pinjaman adalah RP.200.000.000,00 (200 juta rupiah)");
                    output("2.Maksiman Waktu pinjaman adalah 48 bulan (4 tahun)");
                    output("3.Bunga anda adalah 10% dari pinjaman anda \n");
                    output("--------------------------------------------------\n");
                    output("[1] Ajukan pinjaman");
                    output("[0] Kembali\n");
                    output("--------------------------------------------------");
                    while(true) {
                        cin >> x;
                        if(x == "1") {
                            cout << "Silahkan untuk memasukan data Pinjaman: " << endl;
                            cout << "[1/4] Masukan nomor rekening : ";
                            cin >> a1;
                            if(user.cekNR(a1)) {
                                int jeda = 2;
                                int n = 11;
                                while(n--) {
                                    cout << "\n[2/4] Masukan nomor pin : ";
                                    cin >> a2;
                                    a2 = a2 + acak;
                                    a2 = algo.has(a2);
                                    cout << "Mengecek nomor pin";
                                    delay();
                                    if(user.cekNP(a2)) {
                                        output("\n[✓] nomor pin sesuai ");
                                        break;
                                    }
                                    else {
                                        if(7 < n) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                                        }
                                        else if(0 < n < 8) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                                            this_thread::sleep_for(chrono::seconds(jeda));
                                            jeda = 2 * jeda;
                                        }
                                        else {
                                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                                            main();
                                        }
                                    }
                                }
                            }
                            else {
                                cout << "[2/4] Masukan nomor pin : ";
                                cin >> a2;
                            }
                            cout << "[3/4] Masukan Harga Pinjaman : ";
                            cin >> a;
                            if(a > 200000000) {
                                output("Lebih dari maksimal pinjaman");
                                pinjaman8();
                            }
                            cout << "[4/4] Masukan berapa bulan pinjaman : ";
                            cin >> b;
                            if(b > 48) {
                                output("Lebih dari maksimal waktu pinjaman");
                                pinjaman8();
                            }
                            cout << "Memproses";
                            delay();
                            output("\n=====================================================");
                            output("                 KONFIRMASI PINJAMAN                ");
                            output("=====================================================");
                            cout << endl;
                            cout << "Nomor Rekening : " << a1 << endl;
                            cout << "Jumlah Pinjaman : " << fixed << setprecision(2) << a << endl;
                            double bunga = a * 0.1;
                            cout << "Bunga : " << fixed << setprecision(2) << bunga << endl;
                            cout << "Waktu pinjaman : " << b << endl;
                            output("\n-----------------------------------------------------");
                            output("Pastikan data sudah benar");
                            output("[1] Konfirmasi pinjaman\n[2] batal");
                            string apaya;
                            while(true) {
                                cout << "Input:_";
                                cin >> apaya;
                                if(apaya == "1") {
                                    cout << "\nMemproses transaksi Pinjaman";
                                    delay();
                                    cout << "\n> Mengenkripsi data";
                                    delay();
                                    cout << "\n> Meverifikasi saldo";
                                    delay();
                                    cout << "\n> Menyimpan transaksi";
                                    delay();
                                    cout <<"\n[✓] Pinjaman berhasil";
                                    user.ubahDANA(user.tampilkanDANA() + a);
                                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                    time_t sekarang = time(0);
                                    tm *waktu = localtime(&sekarang);
                                    int tahun  = 1900 + waktu->tm_year;
                                    int bulan  = 1 + waktu->tm_mon;
                                    int hari   = waktu->tm_mday;
                                    int jam    = waktu->tm_hour;
                                    int menit  = waktu->tm_min;
                                    int detik  = waktu->tm_sec;
                                    Riwayat.push_back({
                                        {jam,menit,detik},
                                        {hari,bulan,detik},
                                        "Pinjaman Berbunga",
                                        true,
                                        "BCA",
                                        (int)a,
                                        "0x000000" + to_string(N)
                                    });
                                    anak.tambah("BCA",a,0.1,b);
                                    anak.tambah1(a);
                                    N++;
                                    pinjaman8();
                                }
                                else if(apaya == "0") pinjaman8();
                                else {
                                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                                }
                            }
                        }
                        else if(x == "0") {
                            pinjaman8();
                        }
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "3") {
                    output("\n\n=====================================================");
                    output("                         BRI                         ");
                    output("=====================================================");
                    output("Informasi : \n");
                    output("1.Maksimal Harga pinjaman adalah RP.250.000.000,00 (250 juta rupiah)");
                    output("2.Maksiman Waktu pinjaman adalah 36 bulan (3 tahun)");
                    output("3.Bunga anda adalah 8% dari pinjaman anda \n");
                    output("--------------------------------------------------\n");
                    output("[1] Ajukan pinjaman");
                    output("[0] Kembali\n");
                    output("--------------------------------------------------");
                    while(true) {
                        cin >> x;
                        if(x == "1") {
                            cout << "Silahkan untuk memasukan data Pinjaman: " << endl;
                            cout << "[1/4] Masukan nomor rekening : ";
                            cin >> a;
                            if(user.cekNR(a1)) {
                                int jeda = 2;
                                int n = 11;
                                while(n--) {
                                    cout << "\n[2/4] Masukan nomor pin : ";
                                    cin >> a2;
                                    a2 = a2 + acak;
                                    a2 = algo.has(a2);
                                    cout << "Mengecek nomor pin";
                                    delay();
                                    if(user.cekNP(a2)) {
                                        output("\n[✓] nomor pin sesuai ");
                                        break;
                                    }
                                    else {
                                        if(7 < n) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                                        }
                                        else if(0 < n < 8) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                                            this_thread::sleep_for(chrono::seconds(jeda));
                                            jeda = 2 * jeda;
                                        }
                                        else {
                                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                                            main();
                                        }
                                    }
                                }
                            }
                            else {
                                cout << "[2/4] Masukan nomor pin : ";
                                cin >> a2;
                            }
                            cout << "[3/4] Masukan Harga Pinjaman : ";
                            cin >> a;
                            if(a > 250000000) {
                                output("Lebih dari maksimal pinjaman");
                                pinjaman8();
                            }
                            cout << "[4/4] Masukan berapa bulan pinjaman : ";
                            cin >> b;
                            if(b > 36) {
                                output("Lebih dari maksimal waktu pinjaman");
                                pinjaman8();
                            }
                            cout << "Memproses";
                            delay();
                            output("\n=====================================================");
                            output("                 KONFIRMASI PINJAMAN                ");
                            output("=====================================================");
                            cout << endl; 
                            cout << "Nomor Rekening : " << a1 << endl;
                            cout << "Jumlah Pinjaman : " << fixed << setprecision(2) << a << endl;
                            double bunga = a * 0.08;
                            cout << "Bunga : " << fixed << setprecision(2) << bunga << endl;
                            cout << "Waktu pinjaman : " << b << endl;
                            output("\n-----------------------------------------------------");
                            output("Pastikan data sudah benar");
                            output("[1] Konfirmasi pinjaman\n[2] batal");
                            string apaya;
                            while(true) {
                                cout << "Input:_";
                                cin >> apaya;
                                if(apaya == "1") {
                                    cout << "\nMemproses transaksi Pinjaman";
                                    delay();
                                    cout << "\n> Mengenkripsi data";
                                    delay();
                                    cout << "\n> Meverifikasi saldo";
                                    delay();
                                    cout << "\n> Menyimpan transaksi";
                                    delay();
                                    cout <<"\n[✓] Pinjaman berhasil";
                                    user.ubahDANA(user.tampilkanDANA() + a);
                                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                    time_t sekarang = time(0);
                                    tm *waktu = localtime(&sekarang);
                                    int tahun  = 1900 + waktu->tm_year;
                                    int bulan  = 1 + waktu->tm_mon;
                                    int hari   = waktu->tm_mday;
                                    int jam    = waktu->tm_hour;
                                    int menit  = waktu->tm_min;
                                    int detik  = waktu->tm_sec;
                                    Riwayat.push_back({
                                        {jam,menit,detik},
                                        {hari,bulan,detik},
                                        "Pinjaman Berbunga",
                                        true,
                                        "BRI",
                                        (int)a,
                                        "0x000000" + to_string(N)
                                    });
                                    anak.tambah("BRI",a,0.08,b);
                                    anak.tambah1(a);
                                    N++;
                                    pinjaman8();
                                }
                                else if(apaya == "0") pinjaman8();
                                else {
                                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                                }
                            }
                        }
                        else if(x == "0") pinjaman8();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "4") {
                    output("\n\n=====================================================");
                    output("                       BANK EUY                      ");
                    output("=====================================================");
                    output("Informasi : \n");
                    output("1.Maksimal Harga pinjaman adalah RP.150.000.000,00 (150 juta rupiah)");
                    output("2.Maksiman Waktu pinjaman adalah 24 bulan (2 tahun)");
                    output("3.Bunga anda adalah 5% dari pinjaman anda \n");
                    output("--------------------------------------------------\n");
                    output("[1] Ajukan pinjaman");
                    output("[0] Kembali\n");
                    output("--------------------------------------------------");
                    while(true) {
                        cin >> x;
                        if(x == "1") {
                            cout << "Silahkan untuk memasukan data Pinjaman: " << endl;
                            cout << "[1/4] Masukan nomor rekening : ";
                            cin >> a;
                            if(user.cekNR(a1)) {
                                int jeda = 2;
                                int n = 11;
                                while(n--) {
                                    cout << "\n[2/4] Masukan nomor pin : ";
                                    cin >> a2;
                                    a2 = a2 + acak;
                                    a2 = algo.has(a2);
                                    cout << "Mengecek nomor pin";
                                    delay();
                                    if(user.cekNP(a2)) {
                                        output("\n[✓] nomor pin sesuai ");
                                        break;
                                    }
                                    else {
                                        if(7 < n) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                                        }
                                        else if(0 < n < 8) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                                            this_thread::sleep_for(chrono::seconds(jeda));
                                            jeda = 2 * jeda;
                                        }
                                        else {
                                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                                            main();
                                        }
                                    }
                                }
                            }
                            else {
                                cout << "[2/4] Masukan nomor pin : ";
                                cin >> a2;
                            }
                            cout << "[3/4] Masukan Harga Pinjaman : ";
                            cin >> a;
                            if(a > 150000000) {
                                output("Lebih dari maksimal pinjaman");
                                pinjaman8();
                            }
                            cout << "[4/4] Masukan berapa bulan pinjaman : ";
                            cin >> b;
                            if(b > 24) {
                                output("Lebih dari maksimal waktu pinjaman");
                                pinjaman8();
                            }
                            cout << "Memproses";
                            delay();
                            output("\n=====================================================");
                            output("                 KONFIRMASI PINJAMAN                ");
                            output("=====================================================");
                            cout << endl; 
                            cout << "Nomor Rekening : " << a1 << endl;
                            cout << "Jumlah Pinjaman : " << fixed << setprecision(2) << a << endl;
                            double bunga = a * 0.05;
                            cout << "Bunga : " << fixed << setprecision(2) << bunga << endl;
                            cout << "Waktu pinjaman : " << b << endl;
                            output("\n-----------------------------------------------------");
                            output("Pastikan data sudah benar");
                            output("[1] Konfirmasi pinjaman\n[2] batal");
                            string apaya;
                            while(true) {
                                cout << "Input:_";
                                cin >> apaya;
                                if(apaya == "1") {
                                    cout << "\nMemproses transaksi Pinjaman";
                                    delay();
                                    cout << "\n> Mengenkripsi data";
                                    delay();
                                    cout << "\n> Meverifikasi saldo";
                                    delay();
                                    cout << "\n> Menyimpan transaksi";
                                    delay();
                                    cout <<"\n[✓] Pinjaman berhasil";
                                    user.ubahDANA(user.tampilkanDANA() + a);
                                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                    time_t sekarang = time(0);
                                    tm *waktu = localtime(&sekarang);
                                    int tahun  = 1900 + waktu->tm_year;
                                    int bulan  = 1 + waktu->tm_mon;
                                    int hari   = waktu->tm_mday;
                                    int jam    = waktu->tm_hour;
                                    int menit  = waktu->tm_min;
                                    int detik  = waktu->tm_sec;
                                    Riwayat.push_back({
                                        {jam,menit,detik},
                                        {hari,bulan,detik},
                                        "Pinjaman Berbunga",
                                        true,
                                        "Bank euy",
                                        (int)a,
                                        "0x000000" + to_string(N)
                                    });
                                    anak.tambah("bank euy",a,0.05,b);
                                    anak.tambah1(a);
                                    N++;
                                    pinjaman8();
                                }
                                else if(apaya == "0") pinjaman8();
                                else {
                                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                                }
                            }
                        }
                        else if(x == "0") pinjaman8();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
                else if(x == "5") {
                    output("\n\n=====================================================");
                    output("                      BANK MESER                     ");
                    output("=====================================================");
                    output("Informasi : \n");
                    output("1.Maksimal Harga pinjaman adalah RP.1.000.000.000,00 (1 milyar rupiah)");
                    output("2.Maksiman Waktu pinjaman adalah 60 bulan (5 tahun)");
                    output("3.Bunga anda adalah 0% dari pinjaman anda \n");
                    output("--------------------------------------------------\n");
                    output("[1] Ajukan pinjaman");
                    output("[0] Kembali\n");
                    output("--------------------------------------------------");
                    while(true) {
                        cin >> x;
                        if(x == "1") {
                            cout << "Silahkan untuk memasukan data Pinjaman: " << endl;
                            cout << "[1/4] Masukan nomor rekening : ";
                            cin >> a1;
                            if(user.cekNR(a1)) {
                                int jeda = 2;
                                int n = 11;
                                while(n--) {
                                    cout << "\n[2/4] Masukan nomor pin : ";
                                    cin >> b;
                                    a2= a2 + acak;
                                    a2 = algo.has(a2);
                                    cout << "Mengecek nomor pin";
                                    delay();
                                    if(user.cekNP(a2)) {
                                        output("\n[✓] nomor pin sesuai ");
                                        break;
                                    }
                                    else {
                                        if(7 < n) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                                        }
                                        else if(0 < n < 8) {
                                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                                            this_thread::sleep_for(chrono::seconds(jeda));
                                            jeda = 2 * jeda;
                                        }
                                        else {
                                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                                            main();
                                        }
                                    }
                                }
                            }
                            else {
                                cout << "[2/4] Masukan nomor pin : ";
                                cin >> a2;
                            }
                            cout << "[3/4] Masukan Harga Pinjaman : ";
                            cin >> a;
                            if(a > 1000000000) {
                                output("Lebih dari maksimal pinjaman");
                                pinjaman8();
                            }
                            cout << "[4/4] Masukan berapa bulan pinjaman : ";
                            cin >> b;
                            if(b > 60) {
                                output("Lebih dari maksimal waktu pinjaman");
                                pinjaman8();
                            }
                            cout << "Memproses";
                            delay();
                            output("\n=====================================================");
                            output("                 KONFIRMASI PINJAMAN                ");
                            output("=====================================================");
                            cout << endl; 
                            cout << "Nomor Rekening : " << a1 << endl;
                            cout << "Jumlah Pinjaman : " << fixed << setprecision(2) << a << endl;
                            double bunga = a * 0;
                            cout << "Bunga : " << fixed << setprecision(2) << bunga << endl;
                            cout << "Waktu pinjaman : " << b << endl;
                            output("\n-----------------------------------------------------");
                            output("Pastikan data sudah benar");
                            output("[1] Konfirmasi pinjaman\n[2] batal");
                            string apaya;
                            while(true) {
                                cout << "Input:_";
                                cin >> apaya;
                                if(apaya == "1") {
                                    cout << "\nMemproses transaksi Pinjaman";
                                    delay();
                                    cout << "\n> Mengenkripsi data";
                                    delay();
                                    cout << "\n> Meverifikasi saldo";
                                    delay();
                                    cout << "\n> Menyimpan transaksi";
                                    delay();
                                    cout <<"\n[✓] Pinjaman berhasil";
                                    user.ubahDANA(user.tampilkanDANA() + a);
                                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                                    time_t sekarang = time(0);
                                    tm *waktu = localtime(&sekarang);
                                    int tahun  = 1900 + waktu->tm_year;
                                    int bulan  = 1 + waktu->tm_mon;
                                    int hari   = waktu->tm_mday;
                                    int jam    = waktu->tm_hour;
                                    int menit  = waktu->tm_min;
                                    int detik  = waktu->tm_sec;
                                    Riwayat.push_back({
                                        {jam,menit,detik},
                                        {hari,bulan,detik},
                                        "Pinjaman Berbunga",
                                        true,
                                        "Bank meser",
                                        (int)a,
                                        "0x000000" + to_string(N)
                                    });
                                    anak.tambah("bank meser",a,0,b);
                                    anak.tambah1(a);
                                    N++;
                                    pinjaman8();
                                }
                            }
                        }
                        else if(x == "0") pinjaman8();
                        else {
                            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                        }
                    }
                }
            }
        }
        else if(x == "2" or x == "3") {
            output("\n=====================================================");
            if(x == "2") output("              LIHAT PINJAMAN AKTIF               ");
            else if(x == "3") output("              BAYAR CICILAN              ");
            output("=====================================================");
            output("Riwayat transaksi : \n");
            int n = anak.ukuran();
            for(int i = 0; i < n ; i++) {
                cout << "[" << i + 1 << "]" << anak.tampilkanNB(i) << endl;
                cout << "Jumlah pinjaman tersisa: " << anak.tampilkanJP(i) << endl;
                cout << "Waktu pinjaman tersisa: " << anak.tampilkanWP(i) << endl;
                if(anak.tampilkanWP(i) <= 6) cout << "Status : urgent / bahaya\n";
                else cout << "Status : Aman\n";
                output("--------------------------------------------------\n");
            }
            if(n == 0) cout << "\n[!] Anda tidak memiliki riwayat Pinjaman\n";
            cout << "[0] kembali | [1 - " << n << "]" << endl;
            bool c = true;
            double bayaran;
            while(true) {
                cout << "Input:_";
                cin >> x;
                if(stoi(x) >= 1 and stoi(x) <= n) {
                    output("\n=====================================================");
                    output("                   DETAIL PINJAMAN                ");
                    output("=====================================================");
                    cout << endl;
                    cout << "Pinjaman awal : " << fixed << setprecision(2) << anak.tampilkanPA(stoi(x) - 1) << endl;
                    cout << "Waktu awal : " << anak.tampilkanWP(stoi(x) - 1) << endl;
                    cout << "Pinjaman saat ini : " << fixed << setprecision(2) << anak.tampilkanJP(stoi(x) - 1) + anak.tampilkanPB(stoi(x) - 1) * anak.tampilkanJP(stoi(x) - 1) << endl;
                    cout << "Waktu saat ini : " << anak.tampilkanWP(stoi(x) - 1) << endl;
                    cout << "Bunga (%) : " << fixed << setprecision(2) << anak.tampilkanPB(stoi(x) - 1) * 100 << endl;
                    cout << "Bunga : " << fixed << setprecision(2) << anak.tampilkanPB(stoi(x) - 1) * anak.tampilkanJP(stoi(x) - 1) << endl;
                    if(anak.tampilkanWP(stoi(x) - 1) <= 6) cout << "Status : urgent/Bahaya ";
                    else cout << "Status : safe/aman ";
                    output("\n-----------------------------------------------------");
                    output("[✓] Data terenkripsi\n[✓] Pinjaman tervalidasi\n");
                    output("-----------------------------------------------------");
                    cout << "[0] Kembali | [1] Bayar cicilan\n";
                    c = true;
                    string y;
                    while(c) {
                        cout << "input :_";
                        cin >> y;
                        if(y == "0") pinjaman8();
                        else if(y == "1") {
                            cout << "Pinjaman saat ini : " << (1 + anak.tampilkanPB(stoi(x) - 1)) * anak.tampilkanJP(stoi(x) - 1) << endl;
                            cout << "Jumlah : ";
                            cin >> bayaran;
                            cout << "\nMemproses transaksi Pinjaman";
                            delay();
                            cout << "\n> Mengenkripsi data";
                            delay();
                            cout << "\n> Meverifikasi saldo";
                            delay();
                            cout << "\n> Menyimpan transaksi";
                            delay();
                            cout <<"\n[✓] Pinjaman berhasil";
                            user.ubahDANA(user.tampilkanDANA() - bayaran);
                            cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                            time_t sekarang = time(0);
                            tm *waktu = localtime(&sekarang);
                            int tahun  = 1900 + waktu->tm_year;
                            int bulan  = 1 + waktu->tm_mon;
                            int hari   = waktu->tm_mday;
                            int jam    = waktu->tm_hour;
                            int menit  = waktu->tm_min;
                            int detik  = waktu->tm_sec;
                            Riwayat.push_back({
                                {jam,menit,detik},
                                {hari,bulan,detik},
                                "Pinjaman Berbunga",
                                true,
                                "Bank ihsan",
                                (int)bayaran,
                                "0x000000" + to_string(N)
                            });
                            N++;
                            c = false;
                            if(bayaran >= (1 + anak.tampilkanPB(stoi(x) - 1)) * anak.tampilkanJP(stoi(x) - 1)) { 
                                anak.hapus(stoi(x) - 1);
                                user.ubahDANA(user.tampilkanDANA() + (bayaran -  (1 + anak.tampilkanPB(stoi(x) - 1)) * anak.tampilkanJP(stoi(x) - 1)));
                            }
                            else {
                                anak.ubahJP(stoi(x) - 1,(1 + anak.tampilkanPB(stoi(x) - 1)) * anak.tampilkanJP(stoi(x) - 1) - bayaran);
                            }
                            pinjaman8();
                        }
                        else {
                            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                        }
                    }
                }
                else if(x == "0") pinjaman8();
                else {
                    cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
                }
            }
        }
        else if(x == "0") vitur();
        else {
            cout << "[!] Inputan tidak sesuai\n[!] Tolong masukan dengan benar\n\n";
        }
    }
    vitur();
}

void portofolio() {
    output("\n=====================================================");
    output("                  PORTOFOLIO ASET                     ");
    output("=====================================================\n");
    for(int i = 0; i < Anak.ukuran(); i++) {
        cout << "[" <<  i + 1 << "] " << Anak.tampilkanNI(i) << endl;
        cout << "Jumlah Aset: " << Anak.tampilkanJI(i) << endl;
        cout << "Harga Aset sekarang : " << Anak.tampilkanHBS(i) << endl;
        cout << "Harga aset saat anda beli: " << Anak.tampilkanHB(i) << endl;
        cout << "Profit/loss: " << Anak.tampilkanPR(i) << "( " << Anak.tampilkanPP(i) << " %) \n";
    }
    if(Anak.ukuran() == 0) output("[!] Anda tidak memiliki portofolio aset investasi");
    cout << "\n[0] kembali\n";
    string x;
    while(true) {
        cout << "Input:_ ";
        cin >> x;
        if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void cekPI() {
    output("\n=====================================================");
    output("                   PROFIL INVESTASI                 ");
    output("=====================================================");
    cout << endl;
    output("informasi : ");
    cout << "Nama investor: " << user.tampilkanNL() << endl;
    cout << "ID akun : 0x0000001\n";
    cout << "Saldo tersedia: " << user.tampilkanDANA() << endl;
    cout << "Seluruh aset anda: " << Anak.jumlah_semua_persen_profit() << endl;
    cout << "Seluruh profit/loss anda: " << Anak.jumlah_semua_profit() << endl;
    cout << "Persentase profit/loss: " << Anak.jumlah_semua_persen_profit() << "%\n";
    cout << "Status akun: Aktif\n";
    output("\n-----------------------------------------------------");
    output("[1] Riwayat seluruh transaksi investasi");
    output("[2] portofolio aset investasi ");
    output("[0] kembali");
    output("\n-----------------------------------------------------");
    string x;
    while(true) {
        cout << "Input:_";
        cin >> x;
        if(x == "1") riwayat_investasi();
        else if(x == "2") portofolio();
        else if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void Emas(int i) {
    output("\n=====================================================");
    output("                        EMAS                        ");
    output("=====================================================\n");
    output("Informasi: ");
    cout << "Harga terbaru : " << to_string(murid.tampilkan_harga(0)) << endl;
    output("Kategori: low risk-low return");
    cout << "Kenaikan : " <<  to_string(murid.tampilkan_harga(0) * murid.tampilkan_persen_profit(0)) << " ("<< murid.tampilkan_persen_profit(0) * 100 << "%)" <<  endl;
    output("\n-----------------------------------------------------");
    cout << "Saldo anda: " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Total Aset emas anda : " << to_string(Anak.asetEmas()) << endl;
    cout << "Banyaknya Aset emas anda: " << Anak.jumlahEmas() << endl;
    output("\n-----------------------------------------------------");
    string a,b;
    int x;
    cout << "Silahkan untuk memasukan data transaksi : " << endl;
    cout << "[1/3] Masukan nomor rekening : ";
    cin >> a;
    if(user.cekNR(a)) {
        int jeda = 2;
        int n = 11;
        while(n--) {
            cout << "\n[2/3] Masukan nomor pin : ";
            cin >> b;
            b = b + acak;
            b = algo.has(b);
            cout << "Mengecek nomor pin";
            delay();
            if(user.cekNP(b)) {
                output("\n[✓] nomor pin sesuai ");
                break;
            }
            else {
                if(7 < n) {
                    output("\n[!] Nomor pin anda tidak sesuai ! ");
                    output("[!] Tolong masukan kembali Nomor pin anda ! ");

                }
                else if(0 < n < 8) {
                    output("\n[!] Nomor pin anda tidak sesuai ! ");
                    output("[!] Tolong masukan kembali Nomor pin anda ! ");
                    cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                    this_thread::sleep_for(chrono::seconds(jeda));
                    jeda = 2 * jeda;
                }
                else {
                    cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                    main();
                }
            }
        }
    }
    else {
        cout << "[2/3] Masukan nomor pin : ";
        cin >> b;
    }
    if(i == 2) cout << "[3/3] jumlah gram : ";
    else cout << "[3/3] Jumlah gram (Anda memiliki " << Anak.jumlahEmas() << ") : ";
    cin >> x;
    if(i != 2) {
        if(x > Anak.jumlahEmas()) {
            cout << "[!] Jumlah gram yang ingin dijual tidak boleh melebihi apa yang dipunya" << endl;
            Emas(i);
        }
    }
    else {
        if(x * murid.tampilkan_harga(0) > user.tampilkanDANA()) {
            cout << "[!] Saldo anda tidak cukup\n";
            Emas(i);
        }
    }
    cout << "Terimakasih atas kerja samanya" << endl;
    cout << "Memproses";
    delay();
    output("\n=====================================================");
    output("                 KONFIRMASI TRANSAKSI                ");
    output("=====================================================");
    cout << endl; // no.telepon,total bayar dan pilihan
    if(i == 2) {
        cout << "Harga Aset yang akan anda beli: " << to_string(x * murid.tampilkan_harga(0)) << endl;
        cout << "Banyaknya Aset yang akan anda beli: " << x << endl;
    }
    else {
        cout << "Harga Aset yang akan anda jual: " << x * murid.tampilkan_harga(0) << endl;
        cout << "Banyaknya Aset yang akan anda jual: " << x << endl;
    }
    cout << "Prediksi keuntungan: 15% - 20%";
    output("\n-----------------------------------------------------");
    output("Pastikan data sudah benar");
    output("[1] Konfirmasi Transaksi\n[2] batal");
    string apaya;
    while(true) {
        cout << "Input:_";
        cin >> apaya;
        if(apaya == "1") {
            cout << "\nMemproses transaksi Investasi";
            delay();
            cout << "\n> Mengenkripsi data";
            delay();
            cout << "\n> Meverifikasi saldo";
            delay();
            cout << "\n> Menyimpan transaksi";
            delay();
            cout <<"\n[✓] transaksi berhasil";
            if(i == 2 ) user.ubahDANA(user.tampilkanDANA() - x * murid.tampilkan_harga(0));
            else user.ubahDANA(user.tampilkanDANA() + x * murid.tampilkan_harga(0));
            cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
            time_t sekarang = time(0);
            tm *waktu = localtime(&sekarang);
            int tahun  = 1900 + waktu->tm_year;
            int bulan  = 1 + waktu->tm_mon;
            int hari   = waktu->tm_mday;
            int jam    = waktu->tm_hour;
            int menit  = waktu->tm_min;
            int detik  = waktu->tm_sec;
            double y = murid.tampilkan_harga(0);
            Riwayat.push_back({
                {jam,menit,detik},
                {hari,bulan,detik},
                "Investasi",
                true,
                "Emas",
                (int)(x * murid.tampilkan_harga(0)),
                "0x000000" + to_string(N)
            });
            N++;
            murid.ubahPersen(0,0.2); 
            if (i == 2) {
                Anak.tambah(
                    "Emas",
                    "Emas digital",
                    x,
                    2750000,
                    murid.tampilkan_harga(0),
                    x * murid.tampilkan_harga(0),
                    murid.tampilkan_harga(0) - y,
                    20.0
                );
            }
            else {
                Anak.tambah(
                    "Emas",
                    "Emas digital",
                    -x,
                    -2750000,
                    -y,
                    x * -y,
                    -murid.tampilkan_harga(0) + y,
                    -20.0
                );
            }
            investasi9();
        }
        else if(apaya == "2") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void Obligasi(int i) {
    output("\n=====================================================");
    output("                       OBLIGASI                        ");
    output("=====================================================\n");
    output("Kategori : low risk-low reward");
    output("Obligasi yang tersedia : ");
    output("[1] Pemerintah");
    output("Informasi : ");
    cout << "Harga : " << 1000000;
    cout << "\nJaminan Kenaikan : " << "+100000" << " (+10%)\n";
    output("\n-----------------------------------------------------");
    cout << "Saldo anda: " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Total Aset Obligasi anda : " << to_string(Anak.asetObligasi()) << endl;
    cout << "Banyaknya Aset Obligasi anda : " << Anak.jumlahObligasi() << endl;
    output("\n-----------------------------------------------------");
    output ("Pilihan : ");
    output("[1] Lanjutkan");
    output("[0] kembali");
    output("\n-----------------------------------------------------");
    string x;
    while(true) {
        cout << "Input:_";
        cin >> x;
        if(x == "1") {
            string a,b;
            cout << "\nSilahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Transaksi dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            double x;
            if(i == 2) cout << "[3/3] Masukan jumlah surat yang ingin di beli : ";
            else cout << "[3/3] Masukan jumlah surat yang ingin di jual ( Anda punya " << Anak.jumlahObligasi() << ") : ";
            cin >> x;
            if(i != 2) {
                if(x > Anak.jumlahObligasi()) {
                    cout << "[!] Jumlah surat yang ingin dijual tidak boleh melebihi apa yang dipunya" << endl;
                    Obligasi(i);
                }
            }
            else {
                if(x * murid.tampilkan_harga(1) > user.tampilkanDANA()) {
                    cout << "[!] Saldo anda tidak cukup\n";
                    Obligasi(i);
                }
            }
            cout << "Terimakasih atas kerja samanya" << endl;
            cout << "Memproses";
            delay();
            output("\n=====================================================");
            output("                 KONFIRMASI TRANSAKSI                ");
            output("=====================================================");
            cout << endl; 
            if(i == 2) {
                cout << "Harga Aset yang akan anda beli: " << to_string(x * murid.tampilkan_harga(1)) << endl;
                cout << "Banyaknya Aset yang akan anda beli: " << x << endl;
            }
            else {
                cout << "Harga Aset yang akan anda jual: " << x * murid.tampilkan_harga(1) << endl;
                cout << "Banyaknya Aset yang akan anda jual: " << x << endl;
            }
            output("\n-----------------------------------------------------");
            output("Pastikan data sudah benar");
            output("[1] Konfirmasi Transaksi\n[2] batal");
            string apaya;
            while(true) {
                cout << "Input:_";
                cin >> apaya;
                if(apaya == "1") {
                    cout << "\nMemproses transaksi Investasi";
                    delay();
                    cout << "\n> Mengenkripsi data";
                    delay();
                    cout << "\n> Meverifikasi saldo";
                    delay();
                    cout << "\n> Menyimpan transaksi";
                    delay();
                    cout <<"\n[✓] transaksi berhasil";
                    if(i == 2) user.ubahDANA(user.tampilkanDANA() - x * murid.tampilkan_harga(1));
                    else user.ubahDANA(user.tampilkanDANA() + x * (murid.tampilkan_harga(1) + 100000));
                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                    time_t sekarang = time(0);
                    tm *waktu = localtime(&sekarang);
                    int tahun  = 1900 + waktu->tm_year;
                    int bulan  = 1 + waktu->tm_mon;
                    int hari   = waktu->tm_mday;
                    int jam    = waktu->tm_hour;
                    int menit  = waktu->tm_min;
                    int detik  = waktu->tm_sec;
                    double y = murid.tampilkan_harga(1);
                    Riwayat.push_back({
                        {jam,menit,detik},
                        {hari,bulan,detik},
                        "Investasi",
                        true,
                        "Obligasi",
                        (int)(x * murid.tampilkan_harga(1)),
                        "0x000000" + to_string(N)
                    });
                    N++;
                    murid.ubahPersen(1,0); 
                    if (i == 2) {
                        Anak.tambah(
                            "Obligasi",
                            "Surat Obligasi",
                            x,
                            1000000,
                            1100000,
                            x * 1000000,
                            100000 * x,
                            10.0
                        );
                    }
                    else {
                        Anak.tambah(
                            "Obligasi",
                            "Surat Obligasi",
                            -x,
                            -1000000,
                            -1100000,
                            x * -y,
                            -100000 * x,
                            -10.0
                        );
                    }
                    investasi9();
                }
                else if(apaya == "2") investasi9();
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
        }
        else if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void Saham(int j) {
    output("\n=====================================================");
    output("                        SAHAM                        ");
    output("=====================================================\n");
    cout << "Saldo anda: " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Jumlah Aset Saham anda : " << to_string(Anak.asetSaham()) << endl;
    cout << "Banyaknya Aset Saham anda: " << Anak.jumlahSaham() << endl;
    output("\n-----------------------------------------------------");
    output("Jenis Saham yg tersedia : ");
    for(int i = 2; i <= 13; i++) {
        cout << "\n[" << i - 1 << "] " << murid.tampilkan_nama(i) << endl;
        if(murid.tampilkan_harga(i) > 0) cout << "+" << murid.tampilkan_harga(i) << " ";
        else cout << murid.tampilkan_harga(i) << " ";
        if(murid.tampilkan_persen_profit(i) >= 0) cout << "(+" << murid.tampilkan_persen_profit(i) << "%)" << endl;
        else cout << "(" << murid.tampilkan_persen_profit(i) << "%)" << endl;
    }
    output("\n-----------------------------------------------------");
    cout << "[0] Kembali | [1-12] Beli investasi\n";
    string x;
    while(true) {
        cout << "Input:_";
        cin >> x;
        if(stoi(x) >= 1 and stoi(x) <= 12) {
            int i = stoi(x);
            string a,b;
            cout << "Tunggu sebentar";
            delay();
            cout << "\nSilahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Pendaftaran Akun dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            double x;
            if(j == 2) cout << "[3/3] Masukan jumlah lot yang ingin di beli (1 lot = 100 lembar) : " ;
            else cout << "[3/3] Masukan jumlah lot yang ingin di jual  (1 lot = lembar) :";
            cin >> x;
            if(j != 2) {
                if(x > Anak.jumlahSaham()) {
                    cout << "[!] Jumlah lot saham yang ingin dijual tidak boleh melebihi apa yang dipunya" << endl;
                    Saham(i);
                }
            }
            else {
                if(x * murid.tampilkan_harga(i + 1) * 100 > user.tampilkanDANA()) {
                    cout << "[!] Saldo anda kurang\n";
                    Saham(i);
                }
            }
            cout << "Terimakasih atas kerja samanya" << endl;
            cout << "Memproses";
            delay();
            output("\n=====================================================");
            output("                 KONFIRMASI TRANSAKSI                ");
            output("=====================================================");
            cout << endl; 
            if(j == 2) {
                cout << "Kode Saham : " << murid.tampilkan_nama(i + 1) << endl;
                cout << "Harga Aset yang akan anda beli: " << to_string(x * murid.tampilkan_harga(i + 1) * 100) << endl;
                cout << "Banyaknya Aset yang akan anda beli: " << x << endl;
            }
            else {
                cout << "Kode Saham : " << murid.tampilkan_nama(i + 1) << endl;
                cout << "Harga Aset yang akan anda jual: " << x * murid.tampilkan_harga(i - 1) * 100 << endl;
                cout << "Banyaknya Aset yang akan anda jual: " << x << endl;
            }
            output("\n-----------------------------------------------------");
            output("Pastikan data sudah benar");
            output("[1] Konfirmasi Transaksi\n[2] batal");
            string apaya;
            while(true) {
                cout << "Input:_";
                cin >> apaya;
                if(apaya == "1") {
                    cout << "\nMemproses transaksi Investasi";
                    delay();
                    cout << "\n> Mengenkripsi data";
                    delay();
                    cout << "\n> Meverifikasi saldo";
                    delay();
                    cout << "\n> Menyimpan transaksi";
                    delay();
                    cout <<"\n[✓] transaksi berhasil";
                    if(j == 2) user.ubahDANA(user.tampilkanDANA() - x * murid.tampilkan_harga(i + 1) * 100);
                    else user.ubahDANA(user.tampilkanDANA() + x * murid.tampilkan_harga(i + 1) * 100);
                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                    time_t sekarang = time(0);
                    tm *waktu = localtime(&sekarang);
                    int tahun  = 1900 + waktu->tm_year;
                    int bulan  = 1 + waktu->tm_mon;
                    int hari   = waktu->tm_mday;
                    int jam    = waktu->tm_hour;
                    int menit  = waktu->tm_min;
                    int detik  = waktu->tm_sec;
                    double y = murid.tampilkan_harga(i + 1);
                    Riwayat.push_back({
                        {jam,menit,detik},
                        {hari,bulan,detik},
                        "Investasi",
                        true,
                        "Saham " + murid.tampilkan_nama(i + 1),
                        (int)(x * murid.tampilkan_harga(i + 1) * 100),
                        "0x000000" + to_string(N)
                    });
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dist(-500,500);
                    N++;
                    double perubahan = dist(gen) / 100;
                    murid.ubahPersen(i + 1,perubahan);
                    if (i == 2) {
                        Anak.tambah(
                            "Saham",
                            "Saham",
                            x,
                            y,
                            murid.tampilkan_harga(i + 1),
                            x * y * 100,
                            murid.tampilkan_harga(i + 1) - y,
                            perubahan
                        );
                    }
                    else {
                        Anak.tambah(
                            "Saham",
                            "Saham",
                            -x,
                            -y,
                            -murid.tampilkan_harga(i + 1),
                            100 * x * -y,
                            -murid.tampilkan_harga(i + 1) + y,
                            perubahan
                        );
                    }
                    investasi9();
                }
                else if(apaya == "2") investasi9();
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
        }
        else if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void Crypto(int i) {
    output("\n=====================================================");
    output("                       CRYPTO                        ");
    output("=====================================================\n");
    // informasi
    //output("\n-----------------------------------------------------");
    cout << "Saldo anda: " << rupiah(to_string(user.tampilkanDANA())) << endl;
    cout << "Jumlah Aset crypto anda : " << to_string(Anak.asetCrypto()) << endl;
    cout << "Banyaknya Aset crypto anda: " << Anak.jumlahCrypto() << endl;
    output("\n-----------------------------------------------------");
    output("Jenis crypto yg tersedia : ");
    cout << "[1] " << murid.tampilkan_nama(14) << endl;
    if(murid.tampilkan_harga(14) > 0) cout << "+" << murid.tampilkan_harga(14) << " ";
    else cout << murid.tampilkan_harga(14) << " ";
    if(murid.tampilkan_persen_profit(14) > 0) cout << "(+" << murid.tampilkan_persen_profit(14) << "%)" << endl;
    else cout << "(" << murid.tampilkan_persen_profit(14) << "%)" << endl;
    cout << "[2] " << murid.tampilkan_nama(15)<< endl;
    if(murid.tampilkan_harga(15) > 0) cout << "+" << murid.tampilkan_harga(15) << " ";
    else cout << murid.tampilkan_harga(15) << " ";
    if(murid.tampilkan_persen_profit(15) > 0) cout << "(+" << murid.tampilkan_persen_profit(15) << "%)" << endl;
    else cout << "(" << murid.tampilkan_persen_profit(14) << "%)" << endl;
    output("\n-----------------------------------------------------");
    cout << "[0] Kembali | [1-2] Beli investasi\n";
    string x;
    while(true) {
        cout << "Input:_";
        cin >> x;
        if(x == "1") {
            string a,b;
            cout << "\nSilahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Transaksi dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            double x;
            if(i == 2) cout << "[3/3] Masukan jumlah Aset yang ingin di beli : ";
            else cout << "[3/3] Masukan jumlah Aset yang ingin di jual : ";
            cin >> x;
            if(i != 2) {
                if(x > Anak.jumlahCrypto()) {
                    cout << "[!] Jumlah Aset yang ingin dijual tidak boleh melebihi apa yang dipunya" << endl;
                    Crypto(i);
                }
            }
            else {
                if(x * murid.tampilkan_harga(14) > user.tampilkanDANA()) {
                    cout << "[!] Saldo anda tidak cukup\n";
                    Crypto(i);
                }
            }
            cout << "Terimakasih atas kerja samanya" << endl;
            cout << "Memproses";
            delay();
            output("\n=====================================================");
            output("                 KONFIRMASI TRANSAKSI                ");
            output("=====================================================");
            cout << endl; 
            if(i == 2) {
                cout << "Harga Aset yang akan anda beli: " << to_string(x * murid.tampilkan_harga(14)) << endl;
                cout << "Banyaknya Aset yang akan anda beli: " << x << endl;
            }
            else {
                cout << "Harga Aset yang akan anda jual: " << x * murid.tampilkan_harga(14) << endl;
                cout << "Banyaknya Aset yang akan anda jual: " << x << endl;
            }
            output("\n-----------------------------------------------------");
            output("Pastikan data sudah benar");
            output("[1] Konfirmasi pinjaman\n[2] batal");
            string apaya;
            while(true) {
                cout << "Input:_";
                cin >> apaya;
                if(apaya == "1") {
                    cout << "\nMemproses transaksi Investasi";
                    delay();
                    cout << "\n> Mengenkripsi data";
                    delay();
                    cout << "\n> Meverifikasi saldo";
                    delay();
                    cout << "\n> Menyimpan transaksi";
                    delay();
                    cout <<"\n[✓] transaksi berhasil";
                    if(i == 2) user.ubahDANA(user.tampilkanDANA() - x * murid.tampilkan_harga(14));
                    else user.ubahDANA(user.tampilkanDANA() + x * murid.tampilkan_harga(14));
                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                    time_t sekarang = time(0);
                    tm *waktu = localtime(&sekarang);
                    int tahun  = 1900 + waktu->tm_year;
                    int bulan  = 1 + waktu->tm_mon;
                    int hari   = waktu->tm_mday;
                    int jam    = waktu->tm_hour;
                    int menit  = waktu->tm_min;
                    int detik  = waktu->tm_sec;
                    double y = murid.tampilkan_harga(14);
                    Riwayat.push_back({
                        {jam,menit,detik},
                        {hari,bulan,detik},
                        "Investasi",
                        true,
                        murid.tampilkan_nama(14),
                        (int)(x * murid.tampilkan_harga(14)),
                        "0x000000" + to_string(N)
                    });
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dist(-1500,1500);
                    double perubahan = dist(gen) / 100.0;
                    N++;
                    murid.ubahPersen(14,perubahan); 
                    if (i == 2) {
                        Anak.tambah(
                            "Crypto",
                            "Crypto",
                            x,
                            y,
                            murid.tampilkan_harga(14),
                            x * y,
                            -murid.tampilkan_harga(14) + y,
                            perubahan
                        );
                    }
                    else {
                        Anak.tambah(
                            "Crypto",
                            "Crypto",
                            -x,
                            -y,
                            -murid.tampilkan_harga(14),
                            -x * y,
                            murid.tampilkan_harga(14) - y,
                            perubahan
                        );
                    }
                    investasi9();
                }
                else if(apaya == "2") investasi9();
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
        }
        else if(x == "2") {
            string a,b;
            cout << "\nSilahkan untuk memasukan data transaksi : " << endl;
            cout << "[1/3] Masukan nomor rekening : ";
            cin >> a;
            if(user.cekNR(a)) {
                int jeda = 2;
                int n = 11;
                while(n--) {
                    cout << "\n[2/3] Masukan nomor pin : ";
                    cin >> b;
                    b = b + acak;
                    b = algo.has(b);
                    cout << "Mengecek nomor pin";
                    delay();
                    if(user.cekNP(b)) {
                        output("\n[✓] nomor pin sesuai ");
                        break;
                    }
                    else {
                        if(7 < n) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");

                        }
                        else if(0 < n < 8) {
                            output("\n[!] Nomor pin anda tidak sesuai ! ");
                            output("[!] Tolong masukan kembali Nomor pin anda ! ");
                            cout << "[!!] Transaksi dikunci selama " << jeda << " detik !\n\n";
                            this_thread::sleep_for(chrono::seconds(jeda));
                            jeda = 2 * jeda;
                        }
                        else {
                            cout << "\n[!!!] kami berharap agar bekerja sama dengan anda di suatu waktu nanti\n";
                            main();
                        }
                    }
                }
            }
            else {
                cout << "[2/3] Masukan nomor pin : ";
                cin >> b;
            }
            double x;
            if(i == 2) cout << "[3/3] Masukan jumlah Aset yang ingin di beli : ";
            else cout << "[3/3] Masukan jumlah Aset yang ingin di jual : ";
            cin >> x;
            if(i != 2) {
                if(x > Anak.jumlahCrypto()) {
                    cout << "[!] Jumlah surat yang ingin dijual tidak boleh melebihi apa yang dipunya" << endl;
                    Crypto(i);
                }
            }
            else {
                if(x * murid.tampilkan_harga(15) > user.tampilkanDANA()) {
                    cout << "[!] Saldo anda tidak cukup\n";
                    Crypto(i);
                }
            }
            cout << "Terimakasih atas kerja samanya" << endl;
            cout << "Memproses";
            delay();
            output("\n=====================================================");
            output("                 KONFIRMASI TRANSAKSI                ");
            output("=====================================================");
            cout << endl; 
            if(i == 2) {
                cout << "Harga Aset yang akan anda beli: " << to_string(x * murid.tampilkan_harga(15)) << endl;
                cout << "Banyaknya Aset yang akan anda beli: " << x << endl;
            }
            else {
                cout << "Harga Aset yang akan anda jual: " << x * murid.tampilkan_harga(15) << endl;
                cout << "Banyaknya Aset yang akan anda jual: " << x << endl;
            }
            output("\n-----------------------------------------------------");
            output("Pastikan data sudah benar");
            output("[1] Konfirmasi pinjaman\n[2] batal");
            string apaya;
            while(true) {
                cout << "Input:_";
                cin >> apaya;
                if(apaya == "1") {
                    cout << "\nMemproses transaksi Investasi";
                    delay();
                    cout << "\n> Mengenkripsi data";
                    delay();
                    cout << "\n> Meverifikasi saldo";
                    delay();
                    cout << "\n> Menyimpan transaksi";
                    delay();
                    cout <<"\n[✓] transaksi berhasil";
                    if(i == 2) user.ubahDANA(user.tampilkanDANA() - x * murid.tampilkan_harga(15));
                    else user.ubahDANA(user.tampilkanDANA() + x * murid.tampilkan_harga(15));
                    cout << "\nSaldo Sekarang: " << rupiah(to_string(user.tampilkanDANA())) << endl;
                    time_t sekarang = time(0);
                    tm *waktu = localtime(&sekarang);
                    int tahun  = 1900 + waktu->tm_year;
                    int bulan  = 1 + waktu->tm_mon;
                    int hari   = waktu->tm_mday;
                    int jam    = waktu->tm_hour;
                    int menit  = waktu->tm_min;
                    int detik  = waktu->tm_sec;
                    double y = murid.tampilkan_harga(15);
                    Riwayat.push_back({
                        {jam,menit,detik},
                        {hari,bulan,detik},
                        "Investasi",
                        true,
                        murid.tampilkan_nama(15),
                        (int)(x * murid.tampilkan_harga(15)),
                        "0x000000" + to_string(N)
                    });
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dist(-1500,1500);
                    N++;
                    double perubahan = dist(gen) / 100.00;
                    murid.ubahPersen(15,perubahan); 
                    if (i == 2) {
                        Anak.tambah(
                            "Crypto",
                            "Crypto",
                            x,
                            y,
                            murid.tampilkan_harga(15),
                            x * y,
                            murid.tampilkan_harga(15) - y,
                            perubahan
                        );
                    }
                    else {
                        Anak.tambah(
                            "Crypto",
                            "Crypto",
                            -x,
                            -y,
                            -murid.tampilkan_harga(15),
                            -x * y,
                            -murid.tampilkan_harga(15) + y,
                            perubahan
                        );
                    }
                    investasi9();
                }
                else if(apaya == "2") investasi9();
                else {
                    output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
                }
            }
        }
        else if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void buy_and_sell(int i) {
    output("\n=====================================================");
    output("                   BUY AND SELL                     ");
    output("=====================================================\n");
    output("Silahkan pilih instrumen investasi: ");
    output("1.Emas");
    output("2.Surat Obligasi ");
    output("3.Saham");
    output("4.Crypto");
    output("\n-----------------------------------------------------");
    output("[0] kembali | [1-4] pilihan instrumen");
    string x;
    while(true) {
        cout << "Input:_";
        cin >> x;
        if(x == "1") Emas(i);
        else if(x == "2") Obligasi(i);
        else if(x == "3") Saham(i);
        else if(x == "4") Crypto(i);
        else if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void riwayat_investasi() {
    output("\n=====================================================");
    output("                  RIWAYAT ASET                     ");
    output("=====================================================\n");
    for(int i = 0; i < Anak.ukuran(); i++) {
        cout << "\n[" <<  i + 1 << "] "  <<  Riwayat[i].tgl.hari << "-" << Riwayat[i].tgl.bulan << "-" << 2026 << " | " << Riwayat[i].tipe << endl;
        cout << "*Nama Aset Investasi : " << Anak.tampilkanNI(i) << endl;
        cout << "*Jumlah Aset: " << Anak.tampilkanJA(i) << endl;
        cout << "*Harga Aset sekarang : " << to_string(Anak.tampilkanHBS(i)) << endl;
        cout << "*Harga aset saat anda beli: " << to_string(Anak.tampilkanHB(i)) << endl;
        cout << "*Profit/loss: " << Anak.tampilkanPR(i) << "( " << Anak.tampilkanPP(i) << " %) \n";
    }
    if(Anak.ukuran() == 0) output("[!] Anda tidak memiliki Riwayat aset investasi");
    cout << "\n[0] kembali\n";
    string x;
    while(true) {
        cout << "Input:_ ";
        cin >> x;
        if(x == "0") investasi9();
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

void investasi9() {
    output("\n=====================================================");
    output("                    SPIE INVESTASI                  ");
    output("=====================================================");
    cout << endl;
    output("[ STATUS ] Secure channel : active");
    output("[ INFO ] Data akan di enskripsi end-to-end");
    output("--------------------------------------------------");
    output("Status : ");
    cout << "Saldo anda: " << to_string(user.tampilkanDANA()) << endl;
    cout << "Seluruh aset anda: " << to_string(Anak.jumlah_semua_harga_aset()) << endl;
    cout << "seluruh profit anda: " << to_string(Anak.jumlah_semua_profit()) << " (" << Anak.jumlah_semua_persen_profit() << "%)\n";
    output("\n--------------------------------------------------");
    output("Menu utama:");
    cout << "[1] Cek profil investasi anda\n[2] Beli Aset investasi\n[3] Jual Aset investasi\n[4] Lihat riwayat transaksi investasi\n[0] kembali";
    cout << endl;
    output("\n-----------------------------------------------------");
    cout << ">Pilihan anda : ";
    string n;
    bool c;
    c = true;
    lagi = false;
    while(c) { 
        cin >> n;
        if(n == "1") { 
            cout << "Mengalihkan ke fitur Cek Profil investasi";
            delay();
            cekPI();
            c = false;
        }
        else if(n == "2") {
            cout << "Mengalihkan ke fitur Beli Aset investasi";
            delay();
            buy_and_sell(2);
            c = false;
        }
        else if(n == "3") {
            cout << "Mengalihkan ke fitur Jual aset investasi";
            delay();
            buy_and_sell(3);
            c = false;
        }
        else if(n == "4") { 
            cout << "Mengalihkan ke fitur Lihat riwayat investasi";
            delay();
            riwayat_investasi();
            c = false;
        }
        else if(n == "0") {
            vitur();
        }
        else {
            output("\n[!] Inputan anda tidak sesuai !\n[!] Tolong masukan dengan benar");
        }
    }
}

string rupiah(string x) {
    string a = "";
    int jumlah = 0;
    for(int i = x.size() - 1; i >= 0; i--) {
        a = x[i] + a;
        jumlah++;
        if(jumlah % 3 == 0 and i != 0)  {
            a = "." + a;
        }
    }
    return "Rp." + a + ",00";
}
    
