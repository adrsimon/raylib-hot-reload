#ifndef PLUG_H_
#define PLUG_H_

#include <sys/_types/_null.h>

void (*plug_init)() = NULL;
void *(*plug_pre_reload)(void) = NULL;
void (*plug_post_reload)(void*) = NULL; 
void (*plug_update)(void) = NULL;

#endif // PLUG_H_
