/*
	Copyright 2018 Kacper Gawroński.

	This file, and all files created by Kacper Gawroński in project
	File-Manager, are licensed under GNU General Public License.

    File-Manager is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    File-Manager is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with File-Manager.  If not, see <http://www.gnu.org/licenses/>.
*/


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
