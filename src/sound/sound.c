#include <SDL2/SDL.h>
#include <err.h>
#include "sound.h"

static Uint8 *audio_pos;
static Uint32 audio_len;

void audio(const char *path)
{
	Uint32 wav_length;
	Uint8 *wav_buffer;
	SDL_AudioSpec wav_spec;

	if (SDL_LoadWAV(path, &wav_spec, &wav_buffer, &wav_length) == NULL)
		errx(1, "Could not load %s: %s.\n", path, SDL_GetError());
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	audio_pos = wav_buffer;
	audio_len = wav_length;

	if (SDL_OpenAudio(&wav_spec, NULL) < 0)
	{
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}
	SDL_PauseAudio(0);
	while (audio_len > 0)
		SDL_Delay(100);

	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);
}

void my_audio_callback(void *userdata, Uint8 *stream, int len)
{
	if (audio_len == 0)
		return;
	len = (Uint32)len > audio_len ? audio_len : (Uint32)len;
	SDL_memset(stream, 0, len);
	SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
	audio_pos += len;
	audio_len -= len;
	(void)userdata;
}