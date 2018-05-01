#include "MainWindow.h"
MainWindow::MainWindow(){
	this->set_default_size(640,480);
	this->main_box.set_row_homogeneous(false);
	this->main_menu.set_vexpand(false);
	this->main_menu.set_hexpand(true);
	this->main_menu.add(*(new Gtk::MenuItem("Main menu")));
	this->main_box.attach(this->main_menu,0,0,4,1);
	this->main_box.attach(this->content_box,0,1,this->content_box.get_width(),this->content_box.get_height());
	this->add(main_box);
}
MainWindow::~MainWindow(){
	
}
