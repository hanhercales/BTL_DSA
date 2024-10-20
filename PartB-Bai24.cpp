//tdduong a.k.a Han
#include<bits/stdc++.h>
#include "Vector.cpp"
#define Han signed main

using namespace std;

class Dict{
    public:
        string eng;
        string vie;

        Dict() : eng(""), vie(""){}

        Dict(const string &english, const string &vietnamese)
            : eng(english), vie(vietnamese){}
};

class Dictionary{
    private:
        Vector<Vector<Dict>> table;

        int HashFunction(const string &key) const{
            int s = 0;
            for(auto c:key) s += (int) c;
            return s % 997;
        }
    public:
        Dictionary() : table(997){
            for(size_t i = 0; i < 997; ++i)
                table.push_back(Vector<Dict>());
        }

        void insert(const string &eng, const string &vie){
            int index = HashFunction(eng);
            for(size_t i = 0; i < table[index].getSize(); ++i)
                if(table[index][i].eng == eng){
                    cout << "Tu da ton tai!";
                    return;
                }
            table[index].push_back(Dict(eng, vie));
        }

        string translate(const string &eng) const{
            int index = HashFunction(eng);
            if(table[index].getSize() == 0) return "Khong tim thay tu!";
            for(size_t i = 0; i < table[index].getSize(); ++i)
                return "Nghia cua tu " + eng + ": " + table[index][i].vie;
            return "Khong tim thay tu!";
        }

        void remove(const string &eng){
            int index = HashFunction(eng);
            if(table[index].getSize() == 0){
                cout << "Khong tim thay tu!";
                return;
            }
            for(size_t i = 0; i < table[index].getSize(); ++i)
                if(table[index][i].eng == eng){
                    table[index].erase(i);
                    return;
                }
        }

        void update(const string &eng, const string &vie){
            int index = HashFunction(eng);
            for(size_t i = 0; i < table[index].getSize(); ++i)
                if(table[index][i].eng == eng){
                    table[index][i].vie = vie;
                    return;
                }
            cout << "Khong tim thay tu!";
        }

        void readFile(const string &filename){
            ifstream file(filename);
            if(!file.is_open()){
                cout << "Khong the mo file!\n";
                return;
            }
            string eng, vie;
            while(file >> eng >> vie)
                insert(eng, vie);
            file.close();
        }

        void writeFile(const string &filename){
            ofstream file(filename);
            if(!file.is_open()){
                cout << "Khong the mo file!\n";
                return;
            }
            for(size_t i = 0; i < table.getSize(); ++i)
                for(size_t j = 0; j < table[i].getSize(); ++j)
                    file << table[i][j].eng << ' ' << table[i][j].vie << endl;
            file.close();
        }
};

class App{
    private:
        Dictionary mydict;
    public:
        App(){
            cout << "MENU\n"
                 << "1. Them cap tu Anh - Viet.\n"
                 << "2. Lay nghia tu tieng Anh.\n"
                 << "3. Xoa cap tu.\n"
                 << "4. Cap nhat nghia mot tu.\n"
                 << "5. Doc FILE.\n"
                 << "6. Luu du lieu vao FILE.\n"
                 << "0. Thoat chuong trinh.\n";
        }
        ~App(){}
        void menu(){
            string eng, vie, filename;
            int n;
            while(n){
                cout << "\nNhap lua chon: ";
                cin >> n;
                switch (n){
                    case 0:
                        cout << "Dang thoat chuong trinh...";
                        break;
                    case 1:{
                        cout << "Nhap tu tieng Anh: ";
                        cin >> eng;
                        cout << "Nhap tu tieng Viet: ";
                        cin >> vie;
                        mydict.insert(eng, vie);
                        cout << "Da them vao tu dien!";
                        break;
                    }
                    case 2:{
                        cout << "Nhap tu tieng Anh: ";
                        cin >> eng;
                        cout << mydict.translate(eng);
                        break;
                    }
                    case 3:{
                        cout << "Nhap tu tieng Anh: ";
                        cin >> eng;
                        mydict.remove(eng);
                        cout << "Da xoa khoi tu dien!";
                        break;
                    }
                    case 4:{
                        cout << "Nhap tu tieng Anh: ";
                        cin >> eng;
                        cout << "Nhap nghia tieng Viet moi: ";
                        cin >> vie;
                        mydict.update(eng, vie);
                        cout << "Da cap nhat vao tu dien!";
                        break;
                    }
                    case 5:{
                        cout << "Nhap ten FILE can doc: ";
                        cin >> filename;
                        mydict.readFile(filename);
                        cout << "Doc FILE thanh cong!";
                        break;
                    }
                    case 6:{
                        cout << "Nhap ten FILE can ghi de: ";
                        cin >> filename;
                        mydict.writeFile(filename);
                        cout << "Ghi de FILE thanh cong, kiem tra " + filename + '!';
                        break;
                    }
                    default:
                        cout << "Lua chon khong dung, vui long chon lai!\n";
                        break;
                }
            }
        }
};

Han()
{
    App a;
    a.menu();

    return 0;
}