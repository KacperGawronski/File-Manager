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
