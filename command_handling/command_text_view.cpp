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

#include "command_text_view.h"

Command_Text_View::Command_Text_View(){
	this->set_vexpand(true);
	this->set_hexpand(true);
	this->set_can_focus(false);
	this->content.set_hexpand(true);
	this->content.set_vexpand(true);
	this->content.set_editable(false);
	this->add(content);
	this->show_all();
	
}

void Command_Text_View::set_text(std::string s){
	this->content.get_buffer()->set_text(s);
}


Glib::RefPtr<Gtk::TextBuffer> Command_Text_View::get_buffer(){
	return this->content.get_buffer();
}
