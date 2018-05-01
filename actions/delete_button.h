#ifndef DELETE_BUTTON_H
#define DELETE_BUTTON_H
#include "../filesystem_management/gtk_filesystem_entry.h"
#include <gtkmm-3.0/gtkmm.h>
#include "action_button.h"
namespace actions{
	class DeleteButton:public actions::ActionButton{
		private:
			FileSystemEntriesView  *left_view,*right_view;
			Gtk::Entry *left_path_entry,*right_path_entry;
		public:
			DeleteButton(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right);
	};
}

#endif
