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


#ifndef GTK_FILESYSTEM_ENTRY_H
#define GTK_FILESYSTEM_ENTRY_H
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <string>

/*
 *
 * OS version should contain FileSystemEntriesView implementation.
 * It should also contain model columns for Gtk::TreeView and
 * definition of OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE type
 * which is used for adding rows to TreeView from this type variables.
 * 
 */

#ifdef __linux__
#include "linux/linux_includes.h"
#else
#error Not implemented
#endif


class FileSystemEntriesView:public Gtk::ScrolledWindow{
	private:
		
		/*
		get_list_from_gtk_entry uses get_list_from_path with entry's text value.
		get_list_from_path makes list from OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE (children class of abstract FilesystemEntry) objects described in filesystem_management.h
		by adding rows to tree view from OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE's data in format described by model_columns.
		OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE class is OS-dependant
		*/
		void get_list_from_path(std::string path);
		void add_row(OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE *file);
		void add_row(std::string path);
		Gtk::TreeView *tree_view;
	public:
		Glib::RefPtr<Gtk::ListStore>m_refTreeModel;
		
		Gtk::Entry *entry;
		ModelColumns *model_columns;
		Glib::RefPtr<Gtk::TreeSelection>get_selection();
		
		
		void get_list_from_gtk_entry();
		
		FileSystemEntriesView(Gtk::Entry *entry);
		
		~FileSystemEntriesView();
		
	protected:
	
		
		
};
#endif
