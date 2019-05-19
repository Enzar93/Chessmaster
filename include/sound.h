#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>

void my_audio_callback(void *userdata, Uint8 *stream, int len);
void audio(const char *path);

#endif /* !DISPLAY_H_*/
