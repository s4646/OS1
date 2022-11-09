#ifndef CODEC_H_INCLUDED
#define CODEC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int encode(char* src, char* dst, int len);

int decode(char* src, char* dst, int len);

#endif // CODEC_H_INCLUDED