#ifndef _VN_ENGINE_H
#define _VN_ENGINE_H

#include "genesis.h"
#include "gfx.h"
#include "sprite.h"
#include "music.h"

#define STOP_MUSIC (1)
#define STOP_SOUND (2)

#define FLUSH_NOWAIT (1)

#define LAYER_FOREGROUND (1)
#define LAYER_BACKGROUND (2)
#define LAYER_WINDOW (4)

#define SOUND_XGM (1)
#define SOUND_ADPCM (2)

extern void VN_init();

extern void VN_background(const Image *image);
extern void VN_image(const Image *image, const u8 flags);
extern void VN_imageAt(u16 x, u16 y);
extern void VN_font(const Image *image);

extern void VN_music(const u8 *music, const u32 length, const u8 driverFlags);
extern void VN_sound(const u8 *sound, const u32 length, const u8 driverFlags);
extern void VN_stop(const u8 flags);

extern void VN_textStart();
extern void VN_textString(char *text);
extern void VN_textInt(int number);
extern void VN_text(char *text);
extern void VN_flushText();
extern void VN_flush(const u8 flags);
extern void VN_clear(const u8 flags);
extern void VN_wait(u16 duration);

extern void VN_windowDefault();
extern void VN_windowFrom(u16 x, u16 y);
extern void VN_windowTo(u16 x, u16 y);
extern void VN_windowSize(u16 w, u16 h);
extern void VN_cursor(const SpriteDefinition *sprite);

extern void VN_option(u8 number, char *text);
extern u8 VN_choice();

typedef void * (*scriptFunction)();

#endif /* _VN_ENGINE_H */
