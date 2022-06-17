#ifndef RC_INPUT_H
#define RC_INPUT_H

extern int key_w;
extern int key_s;
extern int key_d;
extern int key_a;
extern int key_k;
extern int key_l;
extern int key_q;
extern double mouse_x;

void i_keydown(unsigned char key, int x, int y);
void i_keyup(unsigned char key, int x, int y);
void i_mouse(int x, int y);

#endif // RC_INPUT_H
