#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MainWindowContent_FileManager.h"
#include <gtkmm-3.0/gtkmm.h>
class MainWindow:public Gtk::Window{
	protected:
		Gtk::Grid main_box;
		Gtk::MenuBar main_menu;
		MainWindowContent_FileManager content_box;
	public:
		MainWindow();
		
		~MainWindow();
};
#endif
