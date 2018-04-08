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


#include <iostream>
#include <gtkmm-3.0/gtkmm.h>
#include <string>
#include "filesystem_management/gtk_filesystem_entry.h"
#include "command_handling/command_button.h"
#include "command_handling/command_text_view.h"




class MainWindowContent_FileManager:public Gtk::Grid{
	private:
		FileSystemEntriesView *left_list;
		FileSystemEntriesView *right_list;
		Gtk::Entry left_path_entry;
		Gtk::Entry right_path_entry;
		
		Gtk::Entry left_command_entry;
		Gtk::Entry right_command_entry;
		Command_Text_View command_results;
		Command_Button *load_left_command_button;
		Command_Button *load_right_command_button;
		
		const gint list_height=6;
		const gint list_width=8;
		const gint actions_height=1;
		const gint console_height=3;
		gint current_height;
	public:
		MainWindowContent_FileManager(){
			this->current_height=0;
			this->set_hexpand(true);
			/*
			FileSystemEntriesView are objects to list entries from path.
			They get values using get_list_from_path.
			
			*/
			left_list=new FileSystemEntriesView(&left_path_entry);
			right_list=new FileSystemEntriesView(&right_path_entry);
			load_left_command_button=new Command_Button(left_command_entry.get_buffer(),command_results.get_buffer(),left_path_entry.get_buffer(),left_list,right_list);
			load_right_command_button=new Command_Button(right_command_entry.get_buffer(),command_results.get_buffer(),right_path_entry.get_buffer(),left_list,right_list);
			left_path_entry.set_text("/home/");
			left_path_entry.signal_activate().connect(
				sigc::mem_fun(*left_list,&FileSystemEntriesView::get_list_from_gtk_entry)
			);
			right_path_entry.signal_activate().connect(
				sigc::mem_fun(*right_list,&FileSystemEntriesView::get_list_from_gtk_entry)
			);
			
			this->attach(left_path_entry,0,0,list_width,actions_height);
			this->attach(right_path_entry,list_width,0,list_width,actions_height);
			current_height+=actions_height;
			
			this->attach(*left_list,0,current_height,list_width-1,list_height);
			
			this->attach(*right_list,list_width+1,current_height,list_width-1,list_height);
			
			
			current_height+=list_height;
			this->attach(left_command_entry,0,current_height,list_width,actions_height);
			this->attach(right_command_entry,list_width,current_height,list_width,actions_height);
			current_height+=actions_height;
			this->attach(*load_left_command_button,0,current_height,list_width,actions_height);
			this->attach(*load_right_command_button,list_width,current_height,list_width,actions_height);
			current_height+=actions_height;
			
			this->attach(command_results,0,current_height,this->get_width()-2,console_height);
			current_height+=console_height;
		}
		gint get_width(){
			return list_width*2+2;
		}
		gint get_height(){
			return current_height;
		}
		~MainWindowContent_FileManager(){
			delete this->load_left_command_button;
			delete this->load_right_command_button;
			delete this->left_list;
			delete this->right_list;
		}
};



class MainWindow:public Gtk::Window{
	protected:
		Gtk::Grid main_box;
		Gtk::MenuBar main_menu;
		MainWindowContent_FileManager content_box;
	public:
		MainWindow(){
			this->set_default_size(640,480);
			this->main_box.set_row_homogeneous(false);
			this->main_menu.set_vexpand(false);
			this->main_menu.set_hexpand(true);
			this->main_menu.add(*(new Gtk::MenuItem("Alamakota")));
			this->main_box.attach(this->main_menu,0,0,4,1);
			this->main_box.attach(this->content_box,0,1,this->content_box.get_width(),this->content_box.get_height());
			this->add(main_box);
		}
		
		~MainWindow(){
		}
};




int main(int argc,char **argv)
{
	auto app=Gtk::Application::create(argc, argv,"manager.file");
	
    MainWindow window;
    window.show_all();
    return app->run(window);
    return 0;
}
