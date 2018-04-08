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

#ifndef COMMAND_TEXT_VIEW_H
#define COMMAND_TEXT_VIEW_H
#include <gtkmm-3.0/gtkmm.h>
#include <string>

class Command_Text_View:public Gtk::ScrolledWindow{
	private:
		Gtk::TextView content;
	public:
		Glib::RefPtr<Gtk::TextBuffer> get_buffer();
		void set_text(std::string s);
		Command_Text_View();
};


#endif
