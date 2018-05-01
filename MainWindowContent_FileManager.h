#ifndef MAINWINDOWCONTENT_FILEMANAGER_H
#define MAINWINDOWCONTENT_FILEMANAGER_H
#include <iostream>
#include <gtkmm-3.0/gtkmm.h>
#include <string>
#include "filesystem_management/gtk_filesystem_entry.h"
#include "command_handling/command_button.h"
#include "command_handling/command_text_view.h"
#include "actions/actions_grid.h"

class MainWindowContent_FileManager:public Gtk::Grid{
	private:
		FileSystemEntriesView *left_list;
		FileSystemEntriesView *right_list;
		
		ActionsGrid *actions_grid;
		
		Gtk::Entry left_path_entry;
		Gtk::Entry right_path_entry;
		
		Gtk::Entry left_command_entry;
		Gtk::Entry right_command_entry;
		Command_Text_View command_results;
		Command_Button *load_left_command_button;
		Command_Button *load_right_command_button;
		
		const gint list_height=6;
		const gint list_width=16;
		const gint actions_height=1;
		const gint console_height=3;
		gint current_height;
	public:
		MainWindowContent_FileManager();
		gint get_width();
		gint get_height();
		
	
	~MainWindowContent_FileManager();
};
#endif
