#include <ncurses.h>
#include <stdio.h>

int get_y_acc(int y_ball, int x_ball, int y_acc, int x_acc, int l_rocket, int r_rocket) {
    int r = y_acc;
    if (y_acc == 1 && y_ball == 24) {
        r = -1;
    }
    if (y_acc == -1 && y_ball == 0) {
        r = 1;
    }
    if (x_ball == 1 && x_acc == -1) {
        if (l_rocket == y_ball + 1) {
            r = -1;
        }
        if (l_rocket == y_ball - 1) {
            r = 1;
        }
    }
    if (x_ball == 78 && x_acc == 1) {
        if (r_rocket == y_ball + 1) {
            r = -1;
        }
        if (r_rocket == y_ball - 1) {
            r = 1;
        }
    }
    return r;
};
int get_x_acc(int y_ball, int x_ball, int x_acc, int l_rocket, int r_rocket) {
    int r = x_acc;
    if (x_ball == 78 && x_acc == 1) {
        if (r_rocket == y_ball || r_rocket == y_ball + 1 || r_rocket == y_ball - 1) {
            r = -1;
        }
    }
    if (x_ball == 1 && x_acc == -1) {
        if (l_rocket == y_ball || l_rocket == y_ball + 1 || l_rocket == y_ball - 1) {
            r = 1;
        }
    }
    return r;
}
int move_rocket(int pos, char c) {
    int r = pos;
    if (c == 'A' || c == 'K') {
        if (pos != 1) {
            r = pos - 1;
        }
    } else if (c == 'Z' || c == 'M') {
        if (pos != 23) {
            r = pos + 1;
        }
    }
    return r;
}

int get_goal(int x_ball) {
    int r = 0;
    if (x_ball == 0) {
        r = 1;
    }
    if (x_ball == 79) {
        r = -1;
    }
    return r;
}
int is_win(int r_s, int l_s) {
    int r = 0;
    if (l_s == 21) {
        printw("Left won!");
        r = 1;
    }
    if (r_s == 21) {
        printw("Righ won!");
        r = 1;
    }
    return r;
}

// void clear_screen() { printw("\e[1;1H\e[2J"); }

void draw(int l_rocket, int r_rocket, int x_ball, int y_ball, int l_score, int r_score) {
    printw("Score: %d : %d\n\n\n", l_score, r_score);
    for (int i = -1; i <= 25; i++) {
        for (int j = 0; j < 80; j++) {
            if ((j == 1 && (i == l_rocket || i == l_rocket - 1 || i == l_rocket + 1)) ||
                (j == 78 && (i == r_rocket || i == r_rocket - 1 || i == r_rocket + 1))) {
                printw("|");
            } else if (i == -1 || i == 25) {
                printw("_");
            } else if (y_ball == i && x_ball == j) {
                printw("*");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
}

void init() {
    initscr();
    cbreak();              // Отключаем буферизацию строк
    noecho();              // Не отображаем вводимые символы
    keypad(stdscr, TRUE);  // Включаем специальные клавиши
    // nodelay(stdscr, TRUE);          // Неблокирующий ввод
    halfdelay(1);
    curs_set(0);           // Скрываем курсор
}
void logic() {
    int l_ro = 12, r_ro = 12, x_ball = 40, y_ball = 12, x_acc = -1, y_acc = 0, l_s = 0, r_s = 0, turn = 0;
    char input;
    printf("Left input:");
    while (scanf("%c", &input) != 1 || (input != 'A' && input != 'Z' && input != ' '));
    while (scanf("%c", &input) != 1 || (input != 'K' && input != 'M' && input != ' '));
    printf("\n");
    init();

    while (1) {
        input = getch();
        if (turn) {
            if ((input == 'A') || (input == 'Z')) l_ro = move_rocket(l_ro, input);
        } else {
            if ((input == 'K') || (input == 'M')) r_ro = move_rocket(r_ro, input);
        }
        y_acc = get_y_acc(y_ball, x_ball, y_acc, x_acc, l_ro, r_ro);
        x_acc = get_x_acc(y_ball, x_ball, x_acc, l_ro, r_ro);
        x_ball += x_acc;
        y_ball += y_acc;
        if (get_goal(x_ball) != 0) {
            if (get_goal(x_ball) == 1) {
                r_s++;
            } else {
                l_s++;
            }
            l_ro = y_ball = r_ro = 12;
            x_ball = 40;
            y_acc = 0;
        }
        turn = turn ^ 1;
        refresh();
        // napms(50);
        clear();
        draw(l_ro, r_ro, x_ball, y_ball, l_s, r_s);
        if (is_win(r_s, l_s)) {
            break;
            refresh();
        }
    }
}

int main() {
    logic();
    return 0;
}
