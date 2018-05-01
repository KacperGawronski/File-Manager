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


#ifndef COLUMNS_MODEL_H
#ifdef __linux__
	#include <gtkmm-3.0/gtkmm.h>
	#define COLUMNS_MODEL_H
	class ModelColumns : public Gtk::TreeModelColumnRecord
	{
	public:
		Gtk::TreeModelColumn<Glib::ustring>entry_type;
		Gtk::TreeModelColumn<Glib::ustring>entry_name;
		Gtk::TreeModelColumn<Glib::ustring>permissions;
		Gtk::TreeModelColumn<gint>uid;
		Gtk::TreeModelColumn<gint>gid;
		Gtk::TreeModelColumn<gint>size;
		Gtk::TreeModelColumn<gint>nlinks;
		Gtk::TreeModelColumn<Glib::ustring>modification_date;
		ModelColumns();
	};
	#endif
#endif
