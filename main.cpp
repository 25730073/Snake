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
        void Ve(){
            for (int i = 0; i < DoDai; i++){
                gotoxy(A[i].x, A[i].y);
                cout << "X";
            }
        }


        // Di chuyển (khung sườn)
        void DiChuyen(int Huong){
            for (int i = DoDai - 1; i > 0; i--)
                A[i] = A[i - 1];

            if (Huong == 0) A[0].x += 1; // sang phải
            if (Huong == 1) A[0].y += 1; // đi xuống
            if (Huong == 2) A[0].x -= 1; // sang trái
            if (Huong == 3) A[0].y -= 1; // đi lên
        }
};


int main(){
    CONRAN r;
    int Huong = 0;
    char t;


    while (1){
        if (_kbhit()){
            t = _getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
        }


        system("cls");
        r.Ve(); // vẽ rắn
        r.DiChuyen(Huong); // di chuyển
        Sleep(150);
    }


    return 0;
}