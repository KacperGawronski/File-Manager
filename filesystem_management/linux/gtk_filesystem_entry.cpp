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

#ifdef __linux__
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include <string>
#include "../gtk_filesystem_entry.h"

	

void FileSystemEntriesView::get_list_from_path(std::string path){
		m_refTreeModel->clear();
		std::vector<OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE*>*v=reinterpret_cast<std::vector<OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE*>*>((OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE(path)).get_children());
		for(OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE *e:*v){
			add_row(e);
			delete e;
		}
		delete v;
	}


void FileSystemEntriesView::add_row(OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE *file){
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[model_columns->entry_type] = file->get_filesystem_entry_type();
	row[model_columns->entry_name] = file->get_name();
	row[model_columns->permissions] = file->get_permissions();
	row[model_columns->size] = file->get_size();
	row[model_columns->modification_date] = file->get_modification_time();
	row[model_columns->nlinks] = file->get_nlinks();
	row[model_columns->uid] = file->get_uid();
	row[model_columns->gid] = file->get_gid();
	
	
	this->show_all_children();
}
void FileSystemEntriesView::add_row(std::string path){
	OS_SPECIFIC_FILESYSTEM_ENTRY_TYPE file(path);
	
	Gtk::TreeModel::Row row = *(m_refTreeModel->append());
	row[model_columns->entry_type] = file.get_filesystem_entry_type();
	row[model_columns->entry_name] = file.get_name();
	row[model_columns->permissions] = file.get_permissions();
	row[model_columns->size] = file.get_size();
	row[model_columns->modification_date] = file.get_modification_time();
	row[model_columns->nlinks] = file.get_nlinks();
	row[model_columns->uid] = file.get_uid();
	row[model_columns->gid] = file.get_gid();
	
	
	
	this->show_all_children();
}
void FileSystemEntriesView::get_list_from_gtk_entry(){
	get_list_from_path(this->entry->get_text());
}
FileSystemEntriesView::FileSystemEntriesView(Gtk::Entry *entry){
	this->entry=entry;
	/*Window settings*/
	this->set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
	this->set_hexpand(true);
	this->set_vexpand(true);
	this->set_margin_left(5);
	this->set_margin_right(5);
	
	
	
	/*Tree View*/
	this->tree_view=new Gtk::TreeView;
	this->model_columns=new ModelColumns;

	m_refTreeModel=Gtk::ListStore::create(*model_columns);
	tree_view->set_model(m_refTreeModel);
	
	/*
	Gtk::TreeView::Column* pColumn = tree_view->get_column(0);
	if(pColumn)
		pColumn->set_sort_column(model_columns->entry_name);
	*/
	
	Glib::RefPtr<Gtk::TreeSelection>refTreeSelection = tree_view->get_selection();
	refTreeSelection->set_mode(Gtk::SELECTION_MULTIPLE);
	
	
	tree_view->append_column("EntryType", model_columns->entry_type);
	tree_view->append_column("Name", model_columns->entry_name);
	tree_view->append_column("Permissions",model_columns->permissions);
	tree_view->append_column("Size",model_columns->size);
	tree_view->append_column("Modification date",model_columns->modification_date);
	tree_view->append_column("N links",model_columns->nlinks);
	tree_view->append_column("UID",model_columns->uid);
	tree_view->append_column("GID",model_columns->gid);
	m_refTreeModel->set_sort_column(model_columns->entry_name, Gtk::SORT_ASCENDING);
	this->add(*tree_view);
}
		
Glib::RefPtr<Gtk::TreeSelection> FileSystemEntriesView::get_selection(){
	return this->tree_view->get_selection();
}
FileSystemEntriesView::~FileSystemEntriesView(){
	delete model_columns;
	delete tree_view;
}

#endif
