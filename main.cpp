#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

// Hàm di chuyển con trỏ
void gotoxy(int column, int line){
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Cấu trúc toạ độ
struct Point{ int x, y; };

// --- LỚP RẮN ---
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

    // Vẽ rắn + mồi
    void Ve(Point Qua){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x, A[i].y);
            cout << "O";
        }
        gotoxy(Qua.x, Qua.y);
        cout << "*";
    }

    // Di chuyển
    void DiChuyen(int Huong, Point &Qua){
        // Dồn thân
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        // Đầu rắn
        if (Huong == 0) A[0].x += 1;
        if (Huong == 1) A[0].y += 1;
        if (Huong == 2) A[0].x -= 1;
        if (Huong == 3) A[0].y -= 1;

        // Ăn mồi
        if (A[0].x == Qua.x && A[0].y == Qua.y){
            DoDai++;

            // tạo đoạn mới nối vào đuôi
            A[DoDai - 1] = A[DoDai - 2];

            Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
            Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;
        }
    }
};

// Vẽ khung
void VeKhung(){
    for (int x = MINX; x <= MAXX; x++){
        gotoxy(x, MINY); cout << "+";
        gotoxy(x, MAXY); cout << "+";
    }

    for (int y = MINY; y <= MAXY; y++){
        gotoxy(MINX, y); cout << "+";
        gotoxy(MAXX, y); cout << "+";
    }
}

int main(){
    CONRAN r;
    int Huong = 0;
    char t;

    Point Qua;
    srand((int)time(0));
    Qua.x = rand() % (MAXX - MINX - 1) + MINX + 1;
    Qua.y = rand() % (MAXY - MINY - 1) + MINY + 1;

    while (1){
        // Bắt phím
        if (_kbhit()){
            t = _getch();
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
        }

        // Xoá màn hình
        system("cls");

        VeKhung();        // vẽ khung trước
        r.Ve(Qua);        // vẽ rắn
        r.DiChuyen(Huong, Qua); 
        Sleep(150);
    }

    return 0;
}
