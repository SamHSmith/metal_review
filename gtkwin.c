#include <gtk/gtk.h>


GtkWindow *window;


char* title = "Sick title";
int width = 640; int height = 480;
int close_pressed = FALSE;

void update_window(){
  gtk_window_set_title(window, title);
  gtk_window_set_default_size(window, width, height);
}

void gtk_set_title(char* t){
  title = t;
  update_window();
}

void gtk_set_size(int w, int h){
  width=w;
  height=h;
  update_window();
}

void close_button_pressed(){
  close_pressed=TRUE;
}

int is_close_button_pressed(){
  return close_pressed;
}

void gtk_refresh_window(){
  close_pressed=FALSE;
  gtk_main_iteration_do(FALSE);
}

void gtk_show_window(){
  gtk_widget_show((GtkWidget *)window);
}

void gtk_hide_window(){
  gtk_widget_hide((GtkWidget *)window);
}

void gtk_create_window(){
  window = (GtkWindow*)gtk_window_new(GTK_WINDOW_TOPLEVEL);

  g_signal_connect(G_OBJECT(window), 
                   "delete-event", G_CALLBACK(close_button_pressed), NULL);
}

void gtk_create_window_and_show(int w, int h, char* t){
  gtk_create_window();
  gtk_set_title(t);
  gtk_set_size(w,h);
  gtk_show_window();
}

void gtk_init_gtk(){
  gtk_init(0, NULL);
}
