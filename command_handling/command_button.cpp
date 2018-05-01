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

#include "command_button.h"
#include "shell_usage.h"
Command_Button::Command_Button(Glib::RefPtr<Gtk::EntryBuffer> command_text,Glib::RefPtr<Gtk::TextBuffer> output,Glib::RefPtr<Gtk::EntryBuffer> path,FileSystemEntriesView *listLeft,FileSystemEntriesView *listRight){
	this->command_text=command_text;
	this->output=output;
	this->path=path;
	this->set_label("Execute command");
	this->signal_clicked().connect(sigc::mem_fun(this, &Command_Button::run_command) );
	this->left_list=listLeft;
	this->right_list=listRight;
}

void Command_Button::run_command(){
	shell_usage::run_command(this->command_text->get_text(),this->output,this->path->get_text(),this->left_list,this->right_list);
}
