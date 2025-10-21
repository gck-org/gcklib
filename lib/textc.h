#ifndef TEXTC_H
#define TEXTC_H

char *str_dup(char *s);
char *tostrupr(char *s);
char *tostrlwr(char *s);

char *textc_trim(char *s);
char *textc_pad_left(int count, char *s, char pad);
char *textc_pad_right(int count, char *s, char pad);

#endif
