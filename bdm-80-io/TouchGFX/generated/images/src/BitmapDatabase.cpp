// 4.20.0 0x25b0e7aa
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_back_icon[]; // BITMAP_BACK_ICON_ID = 0, Size: 48x48 pixels
extern const unsigned char image_blue[]; // BITMAP_BLUE_ID = 1, Size: 48x48 pixels
extern const unsigned char image_blue_icons_folder_48[]; // BITMAP_BLUE_ICONS_FOLDER_48_ID = 2, Size: 46x39 pixels
extern const unsigned char image_blue_icons_remove_32[]; // BITMAP_BLUE_ICONS_REMOVE_32_ID = 3, Size: 29x29 pixels
extern const unsigned char image_blue_icons_settings_32[]; // BITMAP_BLUE_ICONS_SETTINGS_32_ID = 4, Size: 30x30 pixels
extern const unsigned char image_blue_pressed[]; // BITMAP_BLUE_PRESSED_ID = 5, Size: 48x48 pixels
extern const unsigned char image_blue_radio_buttons_radio_round_button_normal[]; // BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_NORMAL_ID = 6, Size: 44x44 pixels
extern const unsigned char image_dark[]; // BITMAP_DARK_ID = 7, Size: 48x48 pixels
extern const unsigned char image_dark_pressed[]; // BITMAP_DARK_PRESSED_ID = 8, Size: 48x48 pixels
extern const unsigned char image_orange[]; // BITMAP_ORANGE_ID = 9, Size: 48x48 pixels
extern const unsigned char image_orange_pressed[]; // BITMAP_ORANGE_PRESSED_ID = 10, Size: 48x48 pixels
extern const unsigned char image_popup[]; // BITMAP_POPUP_ID = 11, Size: 248x168 pixels
extern const unsigned char image_toggle_off[]; // BITMAP_TOGGLE_OFF_ID = 12, Size: 58x32 pixels
extern const unsigned char image_toggle_on[]; // BITMAP_TOGGLE_ON_ID = 13, Size: 58x32 pixels
extern const unsigned char image_volume_bar[]; // BITMAP_VOLUME_BAR_ID = 14, Size: 200x8 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_back_icon, 0, 48, 48, 15, 19, 18, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue, 0, 48, 48, 5, 4, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_icons_folder_48, 0, 46, 39, 3, 11, 41, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_icons_remove_32, 0, 29, 29, 27, 10, 1, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 9, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_icons_settings_32, 0, 30, 30, 28, 12, 1, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 6, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_pressed, 0, 48, 48, 5, 4, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 38, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_blue_radio_buttons_radio_round_button_normal, 0, 44, 44, 9, 8, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 28, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_dark, 0, 48, 48, 6, 5, 36, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 37, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_dark_pressed, 0, 48, 48, 6, 5, 36, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 37, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_orange, 0, 48, 48, 6, 5, 36, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 37, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_orange_pressed, 0, 48, 48, 6, 5, 36, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 37, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_popup, 0, 248, 168, 4, 2, 240, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 162, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_off, 0, 58, 32, 8, 3, 42, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 25, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_on, 0, 58, 32, 8, 3, 42, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 25, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_volume_bar, 0, 200, 8, 0, 0, 200, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 8, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
