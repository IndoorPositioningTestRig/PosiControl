#include "DrawLib.h"

//public fields:
vector<dl_Line2d> dl_lines2D;
vector<dl_Rectangle2d> dl_rectangles2D;
vector<dl_Circle2d> dl_circles2D;

//private fields:
//struct with window settings
dl_WindowSettings screensettings;
//drawable gtk widgets 
GtkWidget *window;
GtkWidget *darea;

//private functions:
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,  gpointer user_data);
static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data);

//implementation public functions:
/**
 * initial function to create a window
 * 
 * */
void dl_CreateWindow(int width, int height)
{
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

dl_Color dl_GetColor(int r, int g, int b){
    dl_Color color;
    color.r = r; 
    color.g = g;
    color.b = b;
    return color;
}
dl_Point2d dl_GetPoint(int x, int y){
    dl_Point2d point;
    point.x = x;
    point.y = y;
    return point;
}

dl_Circle2d dl_GetCircle(int x, int y, int radius, dl_Color &color){
    dl_Circle2d circle;
    circle.point = dl_GetPoint(x,y);
    circle.color = color;
    circle.radius = radius;
    return circle;
}

int dl_AddLine(dl_Line2d &line){
    dl_lines2D.push_back(line);
    return dl_lines2D.size() -1;
}

int dl_AddRectangle(dl_Rectangle2d &rect){
    dl_rectangles2D.push_back(rect);
    return dl_rectangles2D.size() -1;
}

int dl_AddCircle(dl_Circle2d &circle){
    dl_circles2D.push_back(circle);
    return dl_circles2D.size() -1;
}

void dl_RefreshScreen(){
    gtk_widget_queue_draw(darea);
}

void dl_ClearScreen(){
    dl_lines2D.clear();
    gtk_widget_queue_draw(darea);
}

//implementation private functions


static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,  gpointer user_data)
{
    //draw lines
    unsigned int i;
    for(i = 0; i < dl_lines2D.size(); i++){
        cairo_set_source_rgb(cr, dl_lines2D[i].color.r, dl_lines2D[i].color.g, dl_lines2D[i].color.b);
        cairo_set_line_width(cr, dl_lines2D[i].thickness);
        cairo_move_to(cr, dl_lines2D[i].startPoint.x, dl_lines2D[i].startPoint.y);
        cairo_line_to(cr,dl_lines2D[i].endPoint.x, dl_lines2D[i].endPoint.y);
        cairo_stroke(cr); 
    }

    //draw rectangles
    for(i = 0; i < dl_rectangles2D.size(); i++){
        cairo_set_source_rgb(cr, dl_rectangles2D[i].color.r, dl_rectangles2D[i].color.g, dl_rectangles2D[i].color.b);
        cairo_set_line_width(cr, dl_rectangles2D[i].thickness);
        cairo_move_to(cr, dl_rectangles2D[i].startPoint.x, dl_rectangles2D[i].startPoint.y);
        cairo_line_to(cr,dl_rectangles2D[i].endPoint.x, dl_rectangles2D[i].startPoint.y);
        cairo_line_to(cr,dl_rectangles2D[i].endPoint.x, dl_rectangles2D[i].endPoint.y);
        cairo_line_to(cr,dl_rectangles2D[i].startPoint.x, dl_rectangles2D[i].endPoint.y);
        cairo_line_to(cr,dl_rectangles2D[i].startPoint.x, dl_rectangles2D[i].startPoint.y);
        cairo_stroke(cr); 
    }

    //draw circles 
    int size = dl_circles2D.size();
    //cout << "drawing cirlces: \n amount: " << size << endl;
    for(i=0; i < dl_circles2D.size(); i++){
        dl_Color c = dl_circles2D[i].color;
        cairo_set_source_rgb(cr, c.r, c.g,c.b);
        cairo_set_line_width(cr, 2);  
        cairo_arc(cr, dl_circles2D[i].point.x, dl_circles2D[i].point.y, dl_circles2D[i].radius, 0, 2 * M_PI);
        cairo_stroke(cr);
    }
    return FALSE;
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{
    //gtk_widget_queue_draw(widget);
    return TRUE;
}
