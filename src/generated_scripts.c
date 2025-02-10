#include "vn_engine.h"
#include "extra.h"


int VG_enemy_hp = 100;
int VG_player_hp = 100;
int VG_player_mp = 50;


void *VS_startup();


void *VS_startup() {
	int VL_randomValue = 0;
	VN_font(&damieng_com_Hourglass_font_png);
	VN_cursor(&Cursor_sprite_png);
	VN_background(&lich_png);
	VN_music(opengameart_epic_boss_theme_helmet_tales_of_the_helmet_s_knight_18_boss_theme_ordmaer__king_of_the_windymoon_wav, sizeof(opengameart_epic_boss_theme_helmet_tales_of_the_helmet_s_knight_18_boss_theme_ordmaer__king_of_the_windymoon_wav), SOUND_ADPCM);
	while (((VG_enemy_hp > 0) && (VG_player_hp > 0))) {
		VN_textStart();
		VN_textString("Player HP: ");
		VN_textInt(VG_player_hp);
		VN_textString(" MP: ");
		VN_textInt(VG_player_mp);
		VN_textString("");
		VN_textStart();
		VN_textString("Lich HP: ");
		VN_textInt(VG_enemy_hp);
		VN_textString("");
		{
			VN_flushText();
			VN_option(1, "Attack");
			VN_option(2, "Spell");
			switch (VN_choice()) {
			case 1:
				VN_sound(opengameart_20_sword_sound_effects_attacks_and_clashes_sword_clash_1_wav, sizeof(opengameart_20_sword_sound_effects_attacks_and_clashes_sword_clash_1_wav), SOUND_ADPCM);
				VL_randomValue = rollDice(2, 6);
				VN_textStart();
				VN_textString("Your phisical attack causes ");
				VN_textInt(VL_randomValue);
				VN_textString(" of damage!");
				VG_enemy_hp = (VG_enemy_hp - VL_randomValue);
				VN_flushText();
				break;
			case 2:
				if ((VG_player_mp > 0)) {
					VN_sound(opengameart_fireball_1_105016__julien_matthey__jm_fx_fireball_01_wav, sizeof(opengameart_fireball_1_105016__julien_matthey__jm_fx_fireball_01_wav), SOUND_ADPCM);
					VL_randomValue = rollDice(3, 6);
					VN_textStart();
					VN_textString("Your magical attack causes ");
					VN_textInt(VL_randomValue);
					VN_textString(" of damage!");
					VG_enemy_hp = (VG_enemy_hp - VL_randomValue);
					VG_player_mp = (VG_player_mp - 10);
					if ((VG_player_mp < 0)) {
						VG_player_mp = 0;
					}
				}
				else {
					VN_text("Sorry, not enough MP.");
				}
				VN_flushText();
				break;
			}
			VN_flushText();
		}
		VN_sound(opengameart_evil_laugh_2_evil_laugh_02_wav, sizeof(opengameart_evil_laugh_2_evil_laugh_02_wav), SOUND_ADPCM);
		VL_randomValue = rollDice(3, 6);
		VN_textStart();
		VN_textString("The elder lich causes ");
		VN_textInt(VL_randomValue);
		VN_textString(" of damage!");
		VG_player_hp = (VG_player_hp - VL_randomValue);
		VN_flush(0);
	}
	VN_clear(LAYER_BACKGROUND|LAYER_FOREGROUND);
	if ((VG_enemy_hp > 0)) {
		VN_text("You lost!");
	}
	else {
		VN_text("You defeated the boss!");
	}
	VN_background(&obligatory_ketchup_png);
	VN_text("Originally made for Low Quality Game Jam 6.");
	VN_text("Obligatory Ketchup. ;)");
	VG_enemy_hp = 100;
	VG_player_hp = 100;
	VG_player_mp = 50;
	VN_flushText();
	return VS_startup;
}