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

#ifndef COMMAND_BUTTON_H
#define COMMAND_BUTTON_H
#include <gtkmm-3.0/gtkmm.h>
#include "command_text_view.h"
#include "../filesystem_management/gtk_filesystem_entry.h"
class Command_Button:public Gtk::Button{
	private:
		Glib::RefPtr<Gtk::EntryBuffer> command_text;
		Glib::RefPtr<Gtk::TextBuffer> output;
		Glib::RefPtr<Gtk::EntryBuffer> path;
		FileSystemEntriesView *left_list,*right_list;
		void run_command();				
	public:
		Command_Button(Glib::RefPtr<Gtk::EntryBuffer> command_text,Glib::RefPtr<Gtk::TextBuffer> output,Glib::RefPtr<Gtk::EntryBuffer> path,FileSystemEntriesView *listLeft,FileSystemEntriesView *listRight);
};

#endif
