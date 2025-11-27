#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;


// Hàm di chuyển con trỏ
void gotoxy(int column, int line){
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Cấu trúc toạ độ
struct Point{ int x, y; };


// --- LỚP RẮN (KHUNG SƯỜN) ---
class CONRAN {
    public:
        Point A[200]; 
        int DoDai; 


        CONRAN(){
            DoDai = 3;
            A[0].x = 10; A[0].y = 10;
            A[1].x = 11; A[1].y = 10;
            A[2].x = 12; A[2].y = 10;
        }


        // Vẽ thân rắn (khung sườn)
        void Ve(Point Qua){
            for (int i = 0; i < DoDai; i++){
                gotoxy(A[i].x, A[i].y);
                cout << "X";
            }
            gotoxy(Qua.x, Qua.y); cout<<"*";
        }


        // Di chuyển (khung sườn)
        void DiChuyen(int Huong, Point& Qua){
            for (int i = DoDai - 1; i > 0; i--)
                A[i] = A[i - 1];
            if (Huong == 0) A[0].x += 1; // sang phải
            if (Huong == 1) A[0].y += 1; // đi xuống
            if (Huong == 2) A[0].x -= 1; // sang trái
            if (Huong == 3) A[0].y -= 1; // đi lên
            if ((A[0].x == Qua.x) && (A[0].y == Qua.y)){
            DoDai++;
            Qua.x = rand()%(MAXX-MINX)+MINX;
            Qua.y = rand()%(MAXY-MINY)+MINY;
            }
        }
};

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20
void VeKhung(){
    for (int x = MINX; x <= MAXX; x++)
        for (int y = MINY; y <= MAXY; y++)
            if(x== MINX || x == MAXX || y == MINY || y == MAXY){
                gotoxy(x,y);
                cout << "+";
            }
}

int main(){
    CONRAN r;
    int Huong = 0;
    char t;

    Point Qua;
    srand((int)time(0));
    Qua.x = rand()%(MAXX-MINX)+MINX;
    Qua.y = rand()%(MAXY-MINY)+MINY;

    while (1){
        if (_kbhit()){
            t = _getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
        }


        system("cls");
        r.Ve(Qua); // vẽ rắn
        r.DiChuyen(Huong, Qua); // di chuyển
        VeKhung();
        Sleep(150);
    }


    return 0;
}