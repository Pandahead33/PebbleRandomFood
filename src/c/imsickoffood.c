#include <pebble.h>
#include <stdlib.h>

static Window *s_window;
static TextLayer *s_text_layer;
static TextLayer *s_logo_layer;

static void init(void) {
	//Create string array for holding all types of food
  char *foodtypes[18];
  foodtypes[0]="BBQ";
  foodtypes[1]="American";
  foodtypes[2]="Seafood";
  foodtypes[3]="Sandwiches";
  foodtypes[4]="Italian";
  foodtypes[5]="Pizza";
  foodtypes[6]="Burgers";
  foodtypes[7]="at a Steakhouse";
  foodtypes[8]="Diner";
  foodtypes[9]="Mexican";
  foodtypes[10]="at Home";
  foodtypes[11]="Caribbean";
  foodtypes[12]="Mediterranean";
  foodtypes[13]="French";
  foodtypes[14]="Indian";
  foodtypes[15]="Thai";
  foodtypes[16]="Chinese";
  foodtypes[17]="Breakfast";
  
  // Create a window and get information about the window
	s_window = window_create();
  Layer *window_layer = window_get_root_layer(s_window);
  GRect bounds = layer_get_bounds(window_layer);
  
  //Make window pretty
  window_set_background_color(s_window, GColorRajah);
	
  // Create a text layer and set the text
	s_text_layer = text_layer_create(bounds);
  text_layer_set_size(s_text_layer, GSize(200, 100));
  
  // Generate random number
  srand(time(NULL));
  int r = (rand() % 19) - 1;
  
  //Display the output and make it pretty
  text_layer_set_background_color(s_text_layer, GColorCeleste);
  text_layer_set_text_color(s_text_layer, GColorRajah);
	text_layer_set_text(s_text_layer, foodtypes[r]);
  
  // Set the font and text alignment
	text_layer_set_font(s_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
	text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  
  // Create a text layer and set the text
	s_logo_layer = text_layer_create(GRect(0, 100, 145, 100));
  
  //Display the output and make it pretty
  text_layer_set_background_color(s_logo_layer, GColorClear);
  text_layer_set_text_color(s_logo_layer, GColorCeleste);
	text_layer_set_text(s_logo_layer, "I'm Sick of Food");
  
  // Set the font and text alignment
	text_layer_set_font(s_logo_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
	text_layer_set_text_alignment(s_logo_layer, GTextAlignmentCenter); 
  
	// Add the text layer to the window
	layer_add_child(window_get_root_layer(s_window), text_layer_get_layer(s_text_layer));
  layer_add_child(window_get_root_layer(s_window), text_layer_get_layer(s_logo_layer));
  
  // Enable text flow and paging on the text layer, with a slight inset of 10, for round screens
  text_layer_enable_screen_text_flow_and_paging(s_text_layer, 10);

	// Push the window, setting the window animation to 'true'
	window_stack_push(s_window, true);
	
	// App Logging!
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Just pushed a window!");
}

static void deinit(void) {
	// Destroy the text layer
	text_layer_destroy(s_text_layer);
	
	// Destroy the window
	window_destroy(s_window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}
