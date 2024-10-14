//Tran Duc Duong a.k.a Han
//231230735
#include<bits/stdc++.h>
#define Han signed main

using namespace std;

class Game{
    private:
        string name, companyName, genre;
        float price, timePlayed;
    public:
        Game(){name = companyName = genre = ""; price = timePlayed = 0;}
        ~Game(){}

        friend istream &operator>>(istream &is, Game &g){
            is.ignore();
            cout << "Name: ";
            getline(is, g.name);
            cout << "Company: ";
            getline(is, g.companyName);
            cout << "Genre: ";
            getline(is, g.genre);
            cout << "Price: ";
            is >> g.price;
            cout << "Time PLayed: ";
            is >> g.timePlayed;
            return is;
        }

        friend ostream &operator<<(ostream &os, Game &g){
            os << '|' << setw(20) << g.name << '|' << setw(20) << g.companyName << '|' << setw(15) << 
            g.genre << '|' << setw(12) << g.timePlayed << 'h' << '|' << setw(8) << g.price << '$' << '|' ;
            return os;
        }

        bool operator<(Game &g){
            return this->name < g.name;
        }

        string getName(){
            return name;
        }

        string getCompanyName(){
            return companyName;
        }
        
        string getGenre(){
            return genre;
        }

        float getPrice(){
            return price;
        }

        float getTimePlayed(){
            return timePlayed;
        }
};

class GameList{
    private:
        int n;
        list<Game> game;
    public:
        GameList(){n = 0;}
        ~GameList(){}

        void ip(){
            cout << "Nhap so luong game: ";
            cin >> n;
            cout << "Nhap thong tin game (Ten game, ten cong ty, the loai, gia, so gio choi):\n";
            for(int i = 0; i < n; ++i){
                cout << "Game thu " << i + 1 << ":\n";
                Game x;
                cin >> x;
                game.push_back(x);
            }
        }

        void op(){
            cout << '|' << setw(20) << "Game" << '|' << setw(20) << "Company" << '|' << setw(15) << 
            "Genre" << '|' << setw(12) << "Time Played" << '|' << setw(8) << "Price" << "|\n";
            for(auto x:game)
                cout << x << endl;
        }

        void sort(){
            game.sort();
            op();
        }

        void MaxPrice(){
            float max = game.front().getPrice();
            for(auto x:game)
                if(max < x.getPrice())
                    max = x.getPrice();
            for(auto x:game)
                if(max == x.getPrice())
                    cout << x;
        }

        void MinTime(){
            float min = game.front().getTimePlayed();
            for(auto x:game)
                if(min > x.getTimePlayed())
                    min = x.getTimePlayed();
            for(auto x:game)
                if(min == x.getTimePlayed())
                    cout << x;
        }

        bool GameExist(string s){
            for(auto x:game)
                if(x.getName() == s)
                    return true;
            return false;
        }

        void SearchName(string s){
            cin.ignore();
            cout << "Nhap ten game can tim: ";
            getline(cin, s);
            if(GameExist(s)){
                cout << "Game can tim: ";
                for(auto x:game)
                    if(x.getName() == s)
                        cout << x;
            }
            else cout << "Khong game nao co ten nhu tren!";
        }

        void insertGame(){
            Game a;
            cin >> a;
            game.push_back(a);
        }

        void deleteGame(string s){
            cin.ignore();
            cout << "Nhap ten game can xoa: ";
            getline(cin, s);
            if(GameExist(s)){
                for (auto it = game.begin(); it != game.end(); )
                    if (it->getName() == s)
                        it = game.erase(it);
                    else
                        ++it;
            }
            else cout << "Khong game nao co ten nhu tren!";
        }
};

class App{
    private:
        GameList mylist;
    public:
        App(){
            cout << "MENU\n"
                 << "1. Them danh sach Game.\n"
                 << "2. In danh sach Game.\n"
                 << "3. Tim Game theo ten.\n"
                 << "4. Xoa Game theo ten.\n"
                 << "5. Them Game.\n"
                 << "6. Sap xep danh sach theo ten Game.\n"
                 << "7. Tim Game co gia cao nhat.\n"
                 << "8. Tim Game choi it nhat.\n"
                 << "0. Thoat chuong trinh.\n";
        }
        ~App(){}
        void menu(){
            
            int n;
            while(n){
                cout << "Nhap lua chon: ";
                cin >> n;
                switch (n){
                    case 0:
                        cout << "Dang thoat chuong trinh...";
                        break;
                    case 1:
                        mylist.ip();
                        break;
                    case 2:
                        mylist.op();
                        break;
                    case 3:{
                        string s;
                        mylist.SearchName(s);
                        break;
                    }
                    case 4:{
                        string s;
                        mylist.deleteGame(s);
                        break;
                    }
                    case 5:
                        mylist.insertGame();
                        break;
                    case 6:
                        mylist.sort();
                        break;
                    case 7:
                        mylist.MaxPrice();
                        break;
                    case 8:
                        mylist.MinTime();
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