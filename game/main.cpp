#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <stack>
using namespace std;

struct coordinate{
    int x;
    int y;
};

class Tile{
    private:
        unsigned int value_;
        bool blocked_;

    public:

        Tile(): value_(0), blocked_(false) {}
        void SetValue(int a){
            value_ = a;
        }
    friend class Game;
};

class Game{
    private:
        Tile data_[4][4];
        bool win_;
        bool full_;
        unsigned int score_;
        vector<coordinate> free_list;
    public:
        
        Game(): win_(false),full_(false),score_(0),free_list({0*16}) {}

        void PrintBoard(){
            for (int i = 0; i<4; ++i) {
                cout << "--------" << endl;
                for (int j = 0; j < 4; ++j) {
                    cout << data_[i][j].value_ << "|";
                }
                cout << endl;
            }
            // footer
            cout << "--------" << endl;
        }

        template<typename T>
        void PrintVector(const vector<T&> vec){
            for (auto i = vec.cbegin(); i != vec.cend(); ++i) {
                cout << *i << ',';
            }
            cout << endl;
        }

        void PopNumber(){
            vector<coordinate> free_list;
            GetAvailableTiles(free_list);
            int shuffle_times = free_list.size()>1 ? 2 : 1;

            cout << shuffle_times << endl;
            while (shuffle_times > 0) {

                // time-besed seed
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(free_list.begin(), free_list.end(), default_random_engine(seed));
                
                coordinate last = free_list.back();
                data_[last.x][last.y].SetValue(2);
                free_list.pop_back();
                --shuffle_times;
            }

        }

        void GetAvailableTiles(vector<coordinate>& list){
            for(auto i = 0; i < 4; ++i){
                for(auto j = 0; j < 4; ++j){
                    if (data_[i][j].value_ == 0) {
                        coordinate c{i, j};
                        list.push_back(c);
                    }
                }
            }
        }
        
};

int main(int argc, char* argv[]){

    Game g;
    g.PrintBoard();
    g.PopNumber();
    g.PrintBoard();
    
/*
    while(cin >> arg) {
        switch (arg)
        {
        case 'a':
            cout << "move to left" << endl;
            break;
        case 's':
            cout << "move to down" << endl;
            break;
        case 'w':
            cout << "move to up" << endl;
            break;
        case 'd':
            cout << "move to right" << endl;
            break;
        case 'q':
            exit(0);
        default:
            break;
        }        
    }
*/
    return 0;
}

