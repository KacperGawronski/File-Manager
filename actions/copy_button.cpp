#include "copy_button.h"

actions::CopyButton::CopyButton(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right):ActionButton(left_path,right_path,left,right){
	
	this->set_label("Copy");
}
