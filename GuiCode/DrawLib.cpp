#include "DrawLib.h"

//private fields:
//struct with window settings
dl_WindowSettings screensettings;
//drawable gtk widgets 
GtkWidget *window;
GtkWidget *darea;

//vector with lines
std::vector<dl_LineSettings> lines;


//private functions:
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,  gpointer user_data);
static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data);


//implementation public functions:
/**
 * initial function to create a window
 * 
 * */
void dl_CreateWindow(int width, int height){
    //save screensettings:
    screensettings.height = height; screensettings.width = width;
    //init gtk:
    gtk_init(0,0);
    //init window and drawing area
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_title (GTK_WINDOW (window), "PosiControl: Indoor Positioning Test Rig Program");
    gtk_window_set_default_size (GTK_WINDOW (window), screensettings.width, screensettings.height);
    darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), darea);

    //add events
    gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  
    g_signal_connect(darea, "draw", G_CALLBACK(on_draw_event), NULL); 
    g_signal_connect(window, "button-press-event", G_CALLBACK(clicked), NULL);
    
    gtk_widget_show_all (window);
    gtk_main();
}

void dl_DrawLine(dl_LineSettings line){
    cout << "adding line" << line.startX << endl;
    lines.push_back(line);
    gtk_widget_queue_draw(darea);
}

//implementation private functions
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,  gpointer user_data)
{
    cout << "drawing :) lines size: " <<  lines.size() << endl;
    //draw lines
    unsigned int i;
    for(i = 0; i < lines.size(); i++){
        cairo_set_source_rgb(cr, lines[i].r, lines[i].g, lines[i].b);
        cairo_set_line_width(cr, lines[i].thickness);
        cairo_move_to(cr, lines[i].startX, lines[i].startY);
        cairo_line_to(cr,lines[i].endX, lines[i].endY);
    }
    cairo_stroke(cr); 
    return FALSE;
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
    gtk_widget_queue_draw(widget);
    return TRUE;
}
