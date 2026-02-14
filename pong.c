#include <stdio.h>

void draw(int l_rocket, int r_rocket, int x_ball, int y_ball, int l_score, int r_score) {
    printf("Score: %d : %d\n\n\n", l_score, r_score);
    for (int i = -1; i <= 25; i++) {
        for (int j = 0; j < 80; j++) {
            if ((j == 0 && (i == l_rocket || i == l_rocket - 1 || i == l_rocket + 1)) ||
                (j == 79 && (i == r_rocket || i == r_rocket - 1 || i == r_rocket + 1))) {
                printf("|");
            } else if (i == -1 || i == 25) {
                printf("—");
            } else if (y_ball == i && x_ball == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

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
int get_x_acc(int y_ball, int x_ball, int x_acc, int l_rocket, int r_rocket){
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
        if (pos != 1){
            r = pos - 1; 
        }
    } else if (c == 'x' || c == ',') {
        if (pos != 23) {
            r = pos + 1;
        }
    }
    return r;
}

int get_goal(int x_ball){
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
        printf("Left won!");
        r = 1;
    }
    if (r_s == 21) {
        printf("Righ won!");
        r = 1;
    }
    return r;
}

void logic(){
    int l_ro = 12, r_ro = 12, x_ball = 40, y_ball = 12, x_acc = -1, y_acc = 0, l_s = 0, r_s = 0, turn = 0;
    char input;
    while (1) {
        if (turn) {
            while (scanf("%c\n", &input) != 1 || (input != 'A' && input != 'Z' && input != ' ')); // читаем, пока не введут нужный символ
            l_ro = move_rocket(l_ro, input);
        } else {
            while (scanf("%c\n", &input) != 1 || (input != 'K' && input != 'M' && input != ' '));
            r_ro = move_rocket(r_ro, input);
        }
        y_acc = get_y_acc(y_ball, x_ball, y_acc, x_acc, l_ro, r_ro);
        x_acc = get_x_acc(y_ball, x_ball, x_acc, l_ro, r_ro);
        x_ball += x_acc;
        y_ball += y_acc;
        if (get_goal(x_ball) != 0){
            if (get_goal(x_ball) == 1) {
                r_s++;
            } else {
                l_s++;
            }
            l_ro = y_ball = r_ro = 12;
            x_ball = 40;
        }
        turn = turn ^ 1;
        draw(l_ro, r_ro, x_ball, y_ball, l_s, r_s);
        if (is_win(r_s, l_s)){
            break;
        }
    }
}
