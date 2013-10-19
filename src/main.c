#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0xBE, 0xB7, 0x96, 0xA7, 0xA7, 0xE6, 0x41, 0xE7, 0x95, 0xAF, 0xD9, 0xE1, 0x1E, 0x75, 0xE5, 0x63 }
PBL_APP_INFO(MY_UUID,
             "Happy Birfday!", "From Deana",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;

TextLayer message_layer, name_layer;

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
	
  text_layer_init(&message_layer, GRect(0, 40, 144, 30));
  text_layer_set_text_alignment(&message_layer, GTextAlignmentCenter);
  text_layer_set_text(&message_layer, "Happy Birthday");
  text_layer_set_font(&message_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
	
  text_layer_init(&name_layer, GRect(0, 85, 144, 30));
  text_layer_set_text_alignment(&name_layer, GTextAlignmentCenter);
  text_layer_set_text(&name_layer, "Avner!");
  text_layer_set_font(&name_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
	
  layer_add_child(&window.layer, &message_layer.layer);
  layer_add_child(&window.layer, &name_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
